/*
 * HistogramEqualization.h
 *
 *  Created on: Dec 14, 2015
 *      Author: tiagotrocoli
 */

#ifndef SOURCE_DIRECTORY__SRC_HISTOGRAM_HISTOGRAMEQUALIZATION_H_
#define SOURCE_DIRECTORY__SRC_HISTOGRAM_HISTOGRAMEQUALIZATION_H_

#include <opencv2/core/core.hpp>
#include <SingleImageHazeRemoval.h>
#include <string>

class HistogramEqualization: public SingleImageHazeRemoval {
public:
    HistogramEqualization();
    virtual ~HistogramEqualization();
    cv::Mat applyHazeRemoval(cv::Mat image);
    std::string getSelectedMethod() {
        return "HistogramEqualization";
    }
};

#endif /* SOURCE_DIRECTORY__SRC_HISTOGRAM_HISTOGRAMEQUALIZATION_H_ */
