// clang-format off
//
// Created by goksu on 4/6/19.
//

#include <algorithm>
#include <vector>
#include "rasterizer.hpp"
#include <opencv2/opencv.hpp>
#include <math.h>


rst::pos_buf_id rst::rasterizer::load_positions(const std::vector<Eigen::Vector3f> &positions)
{
    auto id = get_next_id();
    pos_buf.emplace(id, positions);

    return {id};
}

rst::ind_buf_id rst::rasterizer::load_indices(const std::vector<Eigen::Vector3i> &indices)
{
    auto id = get_next_id();
    ind_buf.emplace(id, indices);

    return {id};
}

rst::col_buf_id rst::rasterizer::load_colors(const std::vector<Eigen::Vector3f> &cols)
{
    auto id = get_next_id();
    col_buf.emplace(id, cols);

    return {id};
}

auto to_vec4(const Eigen::Vector3f& v3, float w = 1.0f)
{
    return Vector4f(v3.x(), v3.y(), v3.z(), w);
}

static bool insideTriangle(float x, float y, const Vector3f* _v)
{   
    // TODO : Implement this function to check if the point (x, y) is inside the triangle represented by _v[0], _v[1], _v[2]
    Eigen::Vector3f ap, bp, cp, tempA, tempB, tempC;
    ap = Vector3f(x - _v[0].x(), y - _v[0].y(), 0.0f);
    bp = Vector3f(x - _v[1].x(), y - _v[1].y(), 0.0f);
    cp = Vector3f(x - _v[2].x(), y - _v[2].y(), 0.0f);

    tempA = ap.cross(Vector3f(_v[1].x() - _v[0].x(), _v[1].y() - _v[0].y(), 0.0f));
    tempB = bp.cross(Vector3f(_v[2].x() - _v[1].x(), _v[2].y() - _v[1].y(), 0.0f));
    tempC = cp.cross(Vector3f(_v[0].x() - _v[2].x(), _v[0].y() - _v[2].y(), 0.0f));

    int direction1, direction2, direction3;
    direction1 = tempA.dot(tempB);
    direction2 = tempB.dot(tempC);
    direction3 = tempC.dot(tempA);

    bool result = (direction1 ^ direction2) >= 0 && (direction1 ^ direction3) >= 0;

    return result;
}

static std::tuple<float, float, float> computeBarycentric2D(float x, float y, const Vector3f* v)
{
    float c1 = (x*(v[1].y() - v[2].y()) + (v[2].x() - v[1].x())*y + v[1].x()*v[2].y() - v[2].x()*v[1].y()) / (v[0].x()*(v[1].y() - v[2].y()) + (v[2].x() - v[1].x())*v[0].y() + v[1].x()*v[2].y() - v[2].x()*v[1].y());
    float c2 = (x*(v[2].y() - v[0].y()) + (v[0].x() - v[2].x())*y + v[2].x()*v[0].y() - v[0].x()*v[2].y()) / (v[1].x()*(v[2].y() - v[0].y()) + (v[0].x() - v[2].x())*v[1].y() + v[2].x()*v[0].y() - v[0].x()*v[2].y());
    float c3 = (x*(v[0].y() - v[1].y()) + (v[1].x() - v[0].x())*y + v[0].x()*v[1].y() - v[1].x()*v[0].y()) / (v[2].x()*(v[0].y() - v[1].y()) + (v[1].x() - v[0].x())*v[2].y() + v[0].x()*v[1].y() - v[1].x()*v[0].y());
    return {c1,c2,c3};
}

void rst::rasterizer::draw(pos_buf_id pos_buffer, ind_buf_id ind_buffer, col_buf_id col_buffer, Primitive type)
{
    auto& buf = pos_buf[pos_buffer.pos_id];
    auto& ind = ind_buf[ind_buffer.ind_id];
    auto& col = col_buf[col_buffer.col_id];

    float f1 = (50 - 0.1) / 2.0;
    float f2 = (50 + 0.1) / 2.0;

    Eigen::Matrix4f mvp = projection * view * model;
    for (auto& i : ind)
    {
        Triangle t;
        Eigen::Vector4f v[] = {
                mvp * to_vec4(buf[i[0]], 1.0f),
                mvp * to_vec4(buf[i[1]], 1.0f),
                mvp * to_vec4(buf[i[2]], 1.0f)
        };
        //Homogeneous division
        for (auto& vec : v) {
            vec /= vec.w();
        }
        //Viewport transformation
        for (auto & vert : v)
        {
            vert.x() = 0.5*width*(vert.x()+1.0);
            vert.y() = 0.5*height*(vert.y()+1.0);
            vert.z() = vert.z() * f1 + f2;
        }

        for (int i = 0; i < 3; ++i)
        {
            t.setVertex(i, v[i].head<3>());
            t.setVertex(i, v[i].head<3>());
            t.setVertex(i, v[i].head<3>());
        }

        auto col_x = col[i[0]];
        auto col_y = col[i[1]];
        auto col_z = col[i[2]];

        t.setColor(0, col_x[0], col_x[1], col_x[2]);
        t.setColor(1, col_y[0], col_y[1], col_y[2]);
        t.setColor(2, col_z[0], col_z[1], col_z[2]);

        // rasterize_triangle(t);
        // rasterize_triangle_super_sampling_V1(t);
        rasterize_triangle_super_sampling_V2(t);
    }
}

//Screen space rasterization
void rst::rasterizer::rasterize_triangle(const Triangle& t) 
{
    auto v = t.toVector4();
    
    // TODO : Find out the bounding box of current triangle.
    float minX = t.v[0].x();
    float maxX = t.v[0].x();
    float minY = t.v[0].y();
    float maxY = t.v[0].y();
    for (int i = 1; i < 3; ++i)
    {
        if (t.v[i].x() < minX)
            minX = t.v[i].x();
        else if (t.v[i].x() > maxX)
            maxX = t.v[i].x();

        if (t.v[i].y() < minY)
            minY = t.v[i].y();
        else if (t.v[i].y() > maxY)
            maxY = t.v[i].y();
    }

    // iterate through the pixel and find if the current pixel is inside the triangle
    for (int x = minX; x < maxX; ++x)
    {
        for (int y = minY; y < maxY; ++y)
        {
            if (insideTriangle(x + 0.5, y + 0.5, t.v))
            {    
                // If so, use the following code to get the interpolated z value.
                //auto[alpha, beta, gamma] = computeBarycentric2D(x, y, t.v);
                //float w_reciprocal = 1.0/(alpha / v[0].w() + beta / v[1].w() + gamma / v[2].w());
                //float z_interpolated = alpha * v[0].z() / v[0].w() + beta * v[1].z() / v[1].w() + gamma * v[2].z() / v[2].w();
                //z_interpolated *= w_reciprocal;

                auto[alpha, beta, gamma] = computeBarycentric2D(x, y, t.v);
                float w_reciprocal = 1.0/(alpha / v[0].w() + beta / v[1].w() + gamma / v[2].w());
                float z_interpolated = alpha * v[0].z() / v[0].w() + beta * v[1].z() / v[1].w() + gamma * v[2].z() / v[2].w();
                z_interpolated *= w_reciprocal;
                z_interpolated = -z_interpolated;

                // TODO : set the current pixel (use the set_pixel function) to the color of the triangle (use getColor function) if it should be painted.
                if (z_interpolated < depth_buf[get_index(x, y)])
                {
                    depth_buf[get_index(x, y)] = z_interpolated;
                    Eigen::Vector3f point = Eigen::Vector3f(x, y, 1.0f);
                    set_pixel(point, t.getColor());
                }
            }
        }
    }
}

void rst::rasterizer::rasterize_triangle_super_sampling_V1(const Triangle& t) 
{
    auto v = t.toVector4();
    
    float minX = t.v[0].x();
    float maxX = t.v[0].x();
    float minY = t.v[0].y();
    float maxY = t.v[0].y();
    for (int i = 1; i < 3; ++i)
    {
        if (t.v[i].x() < minX)
            minX = t.v[i].x();
        else if (t.v[i].x() > maxX)
            maxX = t.v[i].x();

        if (t.v[i].y() < minY)
            minY = t.v[i].y();
        else if (t.v[i].y() > maxY)
            maxY = t.v[i].y();
    }

    for (int x = minX; x < maxX; ++x)
    {
        for (int y = minY; y < maxY; ++y)
        {
            float color_ratio = 0;
            if (insideTriangle(x + 0.25, y + 0.25, t.v))
                color_ratio += 0.25;
            if (insideTriangle(x + 0.75, y + 0.25, t.v))
                color_ratio += 0.25;
            if (insideTriangle(x + 0.25, y + 0.75, t.v))
                color_ratio += 0.25;
            if (insideTriangle(x + 0.75, y + 0.75, t.v))
                color_ratio += 0.25;

            if (color_ratio > 0)
            {
                auto[alpha, beta, gamma] = computeBarycentric2D(x, y, t.v);
                float w_reciprocal = 1.0/(alpha / v[0].w() + beta / v[1].w() + gamma / v[2].w());
                float z_interpolated = alpha * v[0].z() / v[0].w() + beta * v[1].z() / v[1].w() + gamma * v[2].z() / v[2].w();
                z_interpolated *= w_reciprocal;
                z_interpolated = -z_interpolated;

                if (z_interpolated < depth_buf[get_index(x, y)])
                {
                    depth_buf[get_index(x, y)] = z_interpolated;
                    Eigen::Vector3f point = Eigen::Vector3f(x, y, 1.0f);
                    set_pixel(point, t.getColor() * color_ratio);
                }
            }
        }
    }
}

void rst::rasterizer::rasterize_triangle_super_sampling_V2(const Triangle& t) 
{
    auto v = t.toVector4();
    
    float minX = t.v[0].x();
    float maxX = t.v[0].x();
    float minY = t.v[0].y();
    float maxY = t.v[0].y();
    for (int i = 1; i < 3; ++i)
    {
        if (t.v[i].x() < minX)
            minX = t.v[i].x();
        else if (t.v[i].x() > maxX)
            maxX = t.v[i].x();

        if (t.v[i].y() < minY)
            minY = t.v[i].y();
        else if (t.v[i].y() > maxY)
            maxY = t.v[i].y();
    }

    std::vector<std::vector<float>> sample_list =
    {
        {0.25, 0.25},
        {0.25, 0.75},
        {0.75, 0.25},
        {0.75, 0.75},
    };

    for (int x = minX; x < maxX; ++x)
    {
        for (int y = minY; y < maxY; ++y)
        {
            int flag = 0;
            for (int i = 0; i < 4; i++)
            {
                if (insideTriangle(x + sample_list[i][0], y + sample_list[i][1], t.v))
                {
                    auto[alpha, beta, gamma] = computeBarycentric2D(x, y, t.v);
                    float w_reciprocal = 1.0/(alpha / v[0].w() + beta / v[1].w() + gamma / v[2].w());
                    float z_interpolated = alpha * v[0].z() / v[0].w() + beta * v[1].z() / v[1].w() + gamma * v[2].z() / v[2].w();
                    z_interpolated *= w_reciprocal;
                    z_interpolated = -z_interpolated;

                    if (z_interpolated < super_sample_depth_buf[get_index(x, y)][i])
                    {
                        flag = 1;
                        super_sample_depth_buf[get_index(x, y)][i] = z_interpolated;
                        super_sample_frame_buf[get_index(x, y)][i] = t.getColor();
                    }
                }
            }

            if (flag)
            {
                Eigen::Vector3f point = Eigen::Vector3f(x, y, 1.0f);
                Eigen::Vector3f color(0.0f, 0.0f, 0.0f);
                for (int i = 0; i < 4; ++i)
                {
                    color += super_sample_frame_buf[get_index(x, y)][i];
                }
                color = color / 4;
                set_pixel(point, color);
            }
        }
    }
}

void rst::rasterizer::set_model(const Eigen::Matrix4f& m)
{
    model = m;
}

void rst::rasterizer::set_view(const Eigen::Matrix4f& v)
{
    view = v;
}

void rst::rasterizer::set_projection(const Eigen::Matrix4f& p)
{
    projection = p;
}

void rst::rasterizer::clear(rst::Buffers buff)
{
    if ((buff & rst::Buffers::Color) == rst::Buffers::Color)
    {
        std::fill(frame_buf.begin(), frame_buf.end(), Eigen::Vector3f{0, 0, 0});
        for (std::vector<std::vector<Eigen::Vector3f>>::iterator frame_it = super_sample_frame_buf.begin();
        frame_it != super_sample_frame_buf.end(); frame_it++)
        {
            std::fill((*frame_it).begin(), (*frame_it).end(), Eigen::Vector3f{0, 0, 0});
        }
    }
    if ((buff & rst::Buffers::Depth) == rst::Buffers::Depth)
    {
        std::fill(depth_buf.begin(), depth_buf.end(), std::numeric_limits<float>::infinity());
        for (std::vector<std::vector<float>> ::iterator depth_it = super_sample_depth_buf.begin();
        depth_it != super_sample_depth_buf.end(); depth_it++)
        {
            std::fill((*depth_it).begin(), (*depth_it).end(), std::numeric_limits<float>::infinity());
        }
    }
}

rst::rasterizer::rasterizer(int w, int h) : width(w), height(h)
{
    frame_buf.resize(w * h);
    depth_buf.resize(w * h);
    super_sample_frame_buf.resize(w * h, std::vector<Eigen::Vector3f>(4));
    super_sample_depth_buf.resize(w * h, std::vector<float>(4));
}

int rst::rasterizer::get_index(int x, int y)
{
    return (height-1-y)*width + x;
}

void rst::rasterizer::set_pixel(const Eigen::Vector3f& point, const Eigen::Vector3f& color)
{
    //old index: auto ind = point.y() + point.x() * width;
    auto ind = (height-1-point.y())*width + point.x();
    frame_buf[ind] = color;
}

// clang-format on