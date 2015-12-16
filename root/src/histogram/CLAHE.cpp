/*
 * CLAHE.cpp
 *
 *  Created on: Dec 14, 2015
 *      Author: tiagotrocoli
 */

#include <CLAHE.h>
#include <vector>

CLAHE::~CLAHE() {
    clahe.release();
}

CLAHE::CLAHE(double clipLimit, cv::Size grid) {
    clahe = cv::createCLAHE(clipLimit, grid);
}

cv::Mat CLAHE::applyHazeRemoval(cv::Mat image) {

    std::vector<cv::Mat> channels;

    cv::cvtColor(image, image, CV_BGR2HSV);
    cv::split(image, channels);

    //MAIN FUNCTION
    clahe->apply(channels[2], image);

    cv::merge(channels, image);
    cv::cvtColor(image, image, CV_HSV2BGR);

    return image;
}
