//
// Created by LEI XU on 4/27/19.
//

#ifndef RASTERIZER_TEXTURE_H
#define RASTERIZER_TEXTURE_H
#include "global.hpp"
#include <eigen3/Eigen/Eigen>
#include <opencv2/opencv.hpp>
class Texture{
private:
    cv::Mat image_data;

public:
    Texture(const std::string& name)
    {
        image_data = cv::imread(name);
        cv::cvtColor(image_data, image_data, cv::COLOR_RGB2BGR);
        width = image_data.cols;
        height = image_data.rows;
    }

    int width, height;

    Eigen::Vector3f getColor(float u, float v)
    {
        auto u_img = u * width;
        auto v_img = (1 - v) * height;
        auto color = image_data.at<cv::Vec3b>(v_img, u_img);
        return Eigen::Vector3f(color[0], color[1], color[2]);
    }

    Eigen::Vector3f getColorBilinear(float u, float v)
    {
        if (u > 1.0f) u = 1.0f;
        if (v > 1.0f) v = 1.0f;

        auto u_img = u * width;
        auto v_img = (1 - v) * height;

        // std::cout << u << ", " << v << std::endl;
        // std::cout << u_img << ", " << v_img << std::endl;
        auto u00 = image_data.at<cv::Vec3b>(floor(v_img), floor(u_img));
        auto u10 = image_data.at<cv::Vec3b>(floor(v_img), ceil(u_img));
        auto u01 = image_data.at<cv::Vec3b>(ceil(v_img), floor(u_img));
        auto u11 = image_data.at<cv::Vec3b>(ceil(v_img), ceil(u_img));

        Eigen::Vector3f U00 = Eigen::Vector3f(u00[0], u00[1], u00[2]);
        Eigen::Vector3f U10 = Eigen::Vector3f(u10[0], u10[1], u10[2]);
        Eigen::Vector3f U01 = Eigen::Vector3f(u01[0], u01[1], u01[2]);
        Eigen::Vector3f U11 = Eigen::Vector3f(u11[0], u11[1], u11[2]);

        float s = u_img - floor(u_img);
        float t = v_img - floor(v_img);
        Eigen::Vector3f u0 = U00 + s * (U10 - U00);
        Eigen::Vector3f u1 = U01 + s * (U11 - U01);

        Eigen::Vector3f color = u0 + t * (u1 - u0);
        return color;
    }

};
#endif //RASTERIZER_TEXTURE_H
