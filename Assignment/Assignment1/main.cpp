#include "Triangle.hpp"
#include "rasterizer.hpp"
#include <eigen3/Eigen/Eigen>
#include <iostream>
#include <cmath>
#include <opencv2/opencv.hpp>

constexpr double MY_PI = 3.1415926;

Eigen::Matrix4f get_view_matrix(Eigen::Vector3f eye_pos)
{
    Eigen::Matrix4f view = Eigen::Matrix4f::Identity();

    Eigen::Matrix4f translate;
    translate << 1, 0, 0, -eye_pos[0], 0, 1, 0, -eye_pos[1], 0, 0, 1,
        -eye_pos[2], 0, 0, 0, 1;

    view = translate * view;

    return view;
}

Eigen::Matrix4f get_model_matrix(float rotation_angle)
{
    Eigen::Matrix4f model = Eigen::Matrix4f::Identity();

    // TODO: Implement this function
    // Create the model matrix for rotating the triangle around the Z axis.
    // Then return it.
    float alpha = rotation_angle / 180.0 * MY_PI;
    Eigen::Matrix4f rotationX, rotationY, rotationZ;
    rotationX << 1, 0, 0, 0,
                0, cos(alpha), -sin(alpha), 0,
                0, sin(alpha), cos(alpha), 0,
                0, 0, 0, 1;

    rotationY << cos(alpha), 0, sin(alpha), 0,
                0, 1, 0, 0,
                -sin(alpha), 0, cos(alpha), 0,
                0, 0, 0, 1;

    rotationZ << cos(alpha), -sin(alpha), 0, 0, 
                sin(alpha), cos(alpha), 0, 0,
                0, 0, 1, 0, 
                0, 0, 0, 1;

    model = rotationZ * model;


    return model;
}

Eigen::Matrix4f get_projection_matrix(float eye_fov, float aspect_ratio,
                                      float zNear, float zFar)
{
    Eigen::Matrix4f projection = Eigen::Matrix4f::Identity();

    // TODO: Implement this function
    // Create the projection matrix for the given parameters.
    // Then return it.
    // zNear = 2.0;
    Eigen::Matrix4f perspective, orthographic, orthographic_translate, orthographic_scale;
    float right, left, top, bottom;
    // zNear = -zNear;
    // zFar = -zFar;
    top = tan(eye_fov / 2) * abs(zNear);
    bottom = -top;
    right = aspect_ratio * top;
    left = -right;

    perspective << zNear, 0, 0, 0, 
                    0, zNear, 0, 0, 
                    0, 0, zNear + zFar, -(zNear * zFar),
                    0, 0, 1, 0;
    
    orthographic_translate << 2 / (right - left), 0, 0, 0,
                            0, 2 / (top - bottom), 0, 0,
                            0, 0, 2 / (zNear - zFar), 0,
                            0, 0, 0, 1;

    orthographic_scale << 1, 0, 0, - (right + left) / 2,
                        0, 1, 0, - (top + bottom) / 2,
                        0, 0, 1, - (zNear + zFar) / 2,
                        0, 0, 0, 1;

    orthographic = orthographic_translate * orthographic_scale;

    projection = orthographic * perspective * projection;

    return projection;
}

Eigen::Matrix4f get_rotation(Vector3f anis, float angle)
{
    Eigen::Matrix4f rotation = Eigen::Matrix4f::Identity();
    Eigen::Matrix3f I = Eigen::Matrix3f::Identity();

    Eigen::Matrix3f R1, R2, R3, N;
    N << 0, -anis[2], anis[1],
        anis[2], 0, -anis[0],
        -anis[1], anis[0], 0;

    float alpha = angle / 180.0 * MY_PI;
    R1 = cos(alpha) * I;
    R2 = anis * anis.transpose() * (1 - cos(alpha));
    R3 = sin(alpha) * N;

    rotation.topLeftCorner(3, 3) = R1 + R2 + R3;

    return rotation;
}

int main(int argc, const char** argv)
{
    float angle = 0;
    Eigen::Vector3f anix = {0, 0, 1};
    bool command_line = false;
    std::string filename = "output.png";

    if (argc >= 3) {
        command_line = true;
        angle = std::stof(argv[2]); // -r by default
        if (argc == 4) {
            filename = std::string(argv[3]);
        }
    }

    rst::rasterizer r(700, 700);

    Eigen::Vector3f eye_pos = {0, 0, 5};

    std::vector<Eigen::Vector3f> pos{{2, 0, -2}, {0, 2, -2}, {-2, 0, -2}};

    std::vector<Eigen::Vector3i> ind{{0, 1, 2}};

    auto pos_id = r.load_positions(pos);
    auto ind_id = r.load_indices(ind);

    int key = 0;
    int frame_count = 0;

    if (command_line) {
        r.clear(rst::Buffers::Color | rst::Buffers::Depth);

        r.set_model(get_model_matrix(angle));
        r.set_view(get_view_matrix(eye_pos));
        r.set_projection(get_projection_matrix(45, 1, -0.1, -50));

        r.draw(pos_id, ind_id, rst::Primitive::Triangle);
        cv::Mat image(700, 700, CV_32FC3, r.frame_buffer().data());
        image.convertTo(image, CV_8UC3, 1.0f);

        cv::imwrite(filename, image);

        return 0;
    }

    while (key != 27) {
        r.clear(rst::Buffers::Color | rst::Buffers::Depth);

        r.set_model(get_rotation(anix, angle));
        // r.set_model(get_model_matrix(angle));
        r.set_view(get_view_matrix(eye_pos));
        r.set_projection(get_projection_matrix(45, 1, -0.1, -50));

        r.draw(pos_id, ind_id, rst::Primitive::Triangle);

        cv::Mat image(700, 700, CV_32FC3, r.frame_buffer().data());
        image.convertTo(image, CV_8UC3, 1.0f);
        cv::imshow("image", image);
        key = cv::waitKey(10);

        std::cout << "frame count: " << frame_count++ << '\n';

        if (key == 'a') {
            angle += 10;
        }
        else if (key == 'd') {
            angle -= 10;
        }
    }

    return 0;
}
