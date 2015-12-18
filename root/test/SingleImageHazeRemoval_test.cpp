/*
 * SingleImageHazeRemoval_test.cpp
 *
 *  Created on: Dec 14, 2015
 *      Author: tiagotrocoli
 */
#define BOOST_TEST_DYN_LINK
//Define our Module name (prints at testing)
#define BOOST_TEST_MODULE "SingleImageHazeRemoval_test"
//VERY IMPORTANT - include this last

#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>
#include <boost/test/unit_test_suite.hpp>

#include <cmath>
#include <iostream>
#include <vector>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <SingleImageHazeRemoval.h>
#include <histogram/HistogramEqualization.h>
#include <histogram/CLAHE.h>

#include "tools/Tools.h"
#include "tools/UnderwaterImagesTools.h"

#define RESIZE_FACTOR 5

static const std::string pathImage = std::string(UNDERWATER_FOLDER_PATH) + "/" + std::string(IMAGE_PREFIX) + "1" + std::string(IMAGE_SUFIX);

static int numberBeans = 256;
static std::vector<uint> histogram;
static std::vector<uint> cumulativeHistogram;
static std::vector<cv::Mat> imChannels;
static cv::Mat tempImage;

BOOST_AUTO_TEST_CASE(SingleImageHazeRemoval_HistogramEqualization) {

    SingleImageHazeRemoval *singleImageHazeRemoval = new HistogramEqualization();
    std::string getSelectedMethod_out = "HistogramEqualization";

    BOOST_CHECK_EQUAL(getSelectedMethod_out, singleImageHazeRemoval->getSelectedMethod());

    cv::Mat image = cv::imread(pathImage);
    cv::resize(image, image, cv::Size(image.cols / RESIZE_FACTOR, image.rows / RESIZE_FACTOR));

    tempImage = image.clone();
    cv::cvtColor(tempImage, tempImage, CV_BGR2HSV);
    cv::split(tempImage, imChannels);
    histogram = Tools::calcHistogram(imChannels[2], numberBeans);
    cumulativeHistogram = Tools::calcCumulativeHistogram(histogram);

    cv::imshow("IMG ORIGINAL", image);
    cv::imshow("HIST ORIGINAL", Tools::drawHistogram(histogram));

    image = singleImageHazeRemoval->applyHazeRemoval(image);

    tempImage = image.clone();
    cv::cvtColor(tempImage, tempImage, CV_BGR2HSV);
    cv::split(tempImage, imChannels);
    histogram = Tools::calcHistogram(imChannels[2], numberBeans);
    cumulativeHistogram = Tools::calcCumulativeHistogram(histogram);

    cv::imshow("HIST " + singleImageHazeRemoval->getSelectedMethod(), Tools::drawHistogram(histogram));
    cv::imshow("IMG " + singleImageHazeRemoval->getSelectedMethod(), image);
    cv::waitKey();

}

BOOST_AUTO_TEST_CASE(SingleImageHazeRemoval_CLAHE) {

    SingleImageHazeRemoval *singleImageHazeRemoval = new CLAHE();
    std::string getSelectedMethod_out = "CLAHE";

    BOOST_CHECK_EQUAL(getSelectedMethod_out, singleImageHazeRemoval->getSelectedMethod());

    cv::Mat image = cv::imread(pathImage);
    cv::resize(image, image, cv::Size(image.cols / RESIZE_FACTOR, image.rows / RESIZE_FACTOR));
    cv::imshow("IMG ORIGINAL", image);

    singleImageHazeRemoval->applyHazeRemoval(image);

    cv::imshow("IMG " + singleImageHazeRemoval->getSelectedMethod(), image);
    cv::waitKey();

}
