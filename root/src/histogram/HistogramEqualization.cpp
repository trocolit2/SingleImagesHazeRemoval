/*
 * HistogramEqualization.cpp
 *
 *  Created on: Dec 14, 2015
 *      Author: tiagotrocoli
 */

#include <HistogramEqualization.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>

HistogramEqualization::HistogramEqualization() {
    // TODO Auto-generated constructor stub

}

cv::Mat HistogramEqualization::applyHazeRemoval(cv::Mat image) {

    std::vector<cv::Mat> channels;

    cv::cvtColor(image, image, CV_BGR2HSV);
    cv::split(image, channels);

    //MAIN FUNCTION
    cv::equalizeHist(channels[2], channels[2]);

    cv::merge(channels, image);
    cv::cvtColor(image, image, CV_HSV2BGR);

}
