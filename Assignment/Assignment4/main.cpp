#include <chrono>
#include <iostream>
#include <opencv2/opencv.hpp>

std::vector<cv::Point2f> control_points;

void mouse_handler(int event, int x, int y, int flags, void *userdata) 
{
    if (event == cv::EVENT_LBUTTONDOWN && control_points.size() < 4) 
    {
        std::cout << "Left button of the mouse is clicked - position (" << x << ", "
        << y << ")" << '\n';
        control_points.emplace_back(x, y);
    }     
}

void naive_bezier(const std::vector<cv::Point2f> &points, cv::Mat &window) 
{
    auto &p_0 = points[0];
    auto &p_1 = points[1];
    auto &p_2 = points[2];
    auto &p_3 = points[3];

    for (double t = 0.0; t <= 1.0; t += 0.001) 
    {
        auto point = std::pow(1 - t, 3) * p_0 + 3 * t * std::pow(1 - t, 2) * p_1 +
                 3 * std::pow(t, 2) * (1 - t) * p_2 + std::pow(t, 3) * p_3;

        window.at<cv::Vec3b>(point.y + 10, point.x + 10)[2] = 255;
    }
}

cv::Point2f recursive_bezier(const std::vector<cv::Point2f> &control_points, float t) 
{
    // TODO: Implement de Casteljau's algorithm
    if (control_points.size() == 1)
        return control_points[0];
    
    std::vector<cv::Point2f> contorl_point_decrement;
    for (int i = 0; i < control_points.size() - 1; ++i)
    {
        cv::Point2f point;
        point.x = control_points[i].x + t * (control_points[i + 1].x - control_points[i].x);
        point.y = control_points[i].y + t * (control_points[i + 1].y - control_points[i].y);
        contorl_point_decrement.emplace_back(point);
    }

    return cv::Point2f(recursive_bezier(contorl_point_decrement, t));
}

void bezier(const std::vector<cv::Point2f> &control_points, cv::Mat &window) 
{
    // TODO: Iterate through all t = 0 to t = 1 with small steps, and call de Casteljau's 
    // recursive Bezier algorithm.
    std::map<std::vector<int>, std::vector<int>> point_color_count;
    for (double t = 0.0; t <= 1.0; t += 0.001)
    {
        cv::Point2f point = recursive_bezier(control_points, t);
        window.at<cv::Vec3b>(point.y + 5, point.x + 5)[1] = 255;
    }
}

void bezier_v1(const std::vector<cv::Point2f> &control_points, cv::Mat &window) 
{
    // TODO: Iterate through all t = 0 to t = 1 with small steps, and call de Casteljau's 
    // recursive Bezier algorithm.
    std::map<std::vector<int>, std::vector<int>> point_color_count;
    for (double t = 0.0; t <= 1.0; t += 0.001)
    {
        cv::Point2f point = recursive_bezier(control_points, t);

        std::vector<std::vector<float>> sample_list =
        {
            {-0.5f, -0.5f},
            {-0.5f, +0.5f},
            {+0.5f, -0.5f},
            {+0.5f, +0.5f},
        };
        
        for (int i = 0; i < sample_list.size(); ++i)
        {
            cv::Point2i sample_point = cv::Point2i(point.x + sample_list[i][0], point.y + sample_list[i][1]);
            float distance = std::sqrt(std::pow(sample_point.x + 0.5f - point.x, 2) +  std::pow(sample_point.y + 0.5f - point.y, 2));
            int point_color = 255.f * (std::sqrt(2) - distance) / std::sqrt(2);
            if (point_color > window.at<cv::Vec3b>(sample_point.y, sample_point.x)[1])
            {
                window.at<cv::Vec3b>(sample_point.y, sample_point.x)[1] = point_color;
            }
        }
    }
}

int main() 
{
    cv::Mat window = cv::Mat(700, 700, CV_8UC3, cv::Scalar(0));
    cv::cvtColor(window, window, cv::COLOR_BGR2RGB);
    cv::namedWindow("Bezier Curve", cv::WINDOW_AUTOSIZE);

    cv::setMouseCallback("Bezier Curve", mouse_handler, nullptr);

    int key = -1;
    while (key != 27) 
    {
        for (auto &point : control_points) 
        {
            cv::circle(window, point, 3, {255, 255, 255}, 3);
        }

        if (control_points.size() == 4) 
        {
            naive_bezier(control_points, window);
            bezier(control_points, window);
            bezier_v1(control_points, window);

            cv::imshow("Bezier Curve", window);
            cv::imwrite("my_bezier_curve_compare.png", window);
            key = cv::waitKey(0);

            return 0;
        }

        cv::imshow("Bezier Curve", window);
        key = cv::waitKey(20);
    }

return 0;
}
