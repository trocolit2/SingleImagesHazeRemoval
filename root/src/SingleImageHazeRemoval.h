/*
 * SingleImageHazeRemoval.h
 *
 *  Created on: Dec 14, 2015
 *      Author: tiagotrocoli
 */

#ifndef SOURCE_DIRECTORY__SRC_SINGLEIMAGEHAZEREMOVAL_H_
#define SOURCE_DIRECTORY__SRC_SINGLEIMAGEHAZEREMOVAL_H_

#include <string>
#include <iostream>
#include <vector>

#include <opencv2/core/core.hpp>

class SingleImageHazeRemoval {

public:
    virtual ~SingleImageHazeRemoval();

    virtual cv::Mat applyHazeRemoval(cv::Mat image);

    virtual std::string getSelectedMethod() {
        return "No Method Selected";
    }

};

#endif /* SOURCE_DIRECTORY__SRC_SINGLEIMAGEHAZEREMOVAL_H_ */
