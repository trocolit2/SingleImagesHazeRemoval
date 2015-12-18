/*
 * Tools.cpp
 *
 *  Created on: Dec 18, 2015
 *      Author: tiagotrocoli
 */

#include "Tools.h"

std::vector<uint> Tools::calcHistogram(cv::Mat image, uint beans) {

    std::vector<uint> histVector(beans, 0);
    cv::MatConstIterator_<uint8_t> it = image.begin<uint8_t>(), it_end = image.end<uint8_t>();
    for (; it != it_end; ++it)
        ++histVector[(*it)];

    return histVector;
}

std::vector<uint> Tools::calcCumulativeHistogram(std::vector<uint> histogram) {

    std::vector<uint> cdf(histogram.size());
    for (uint i = 0; i < histogram.size(); ++i)
        for (uint j = 0; j <= i; ++j)
            cdf[i] += histogram[j];

    return cdf;
}

cv::Mat Tools::drawHistogram(std::vector<uint> histogram, cv::Size size) {

    cv::Mat histImage = cv::Mat::zeros(size, CV_8UC1);

    cv::Mat histMat(1, histogram.size(), CV_32SC1);
    for (uint i = 0; i < histogram.size(); ++i)
        histMat.at<uint>(0, i) = histogram[i];

    double maxBeanValue;
    cv::minMaxIdx(histMat, 0, &maxBeanValue);

    double highNorm = (size.height - size.height * 0.02) * 1.0 / maxBeanValue;
    double beanSize = size.width * 1.0 / histogram.size();

    for (uint i = 0; i < histogram.size(); ++i) {
        cv::Scalar color = cv::Scalar(255);
        cv::Point pt1 = cv::Point(i * beanSize, size.height - 1);
        cv::Point pt2 = cv::Point(i * beanSize + beanSize, size.height - histogram[i] * highNorm);
        cv::rectangle(histImage, pt1, pt2, color, -1);
    }

    return histImage;
}
