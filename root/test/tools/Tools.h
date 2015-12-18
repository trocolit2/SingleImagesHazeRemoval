/*
 * Tools.h
 *
 *  Created on: Dec 18, 2015
 *      Author: tiagotrocoli
 */

#ifndef TEST_TOOLS_TOOLS_H_
#define TEST_TOOLS_TOOLS_H_

#include <opencv2/core/core.hpp>
#include <vector>

class Tools {



public:
    //histogram tools
    static std::vector<uint> calcHistogram(cv::Mat image, uint bins);
    static std::vector<uint> calcCumulativeHistogram(std::vector<uint> histogram);
    static cv::Mat drawHistogram(std::vector<uint>, cv::Size size = cv::Size(500, 250));

};

#endif /* TEST_TOOLS_TOOLS_H_ */
