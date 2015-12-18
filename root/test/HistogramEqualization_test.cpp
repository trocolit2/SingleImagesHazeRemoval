/*
 * HistogramEqualization_test.cpp
 *
 *  Created on: Dec 14, 2015
 *      Author: tiagotrocoli
 */

#include <histogram/HistogramEqualization.h>
#include <SingleImageHazeRemoval.h>

#define BOOST_TEST_DYN_LINK
//Define our Module name (prints at testing)
#define BOOST_TEST_MODULE "HistogramEqualization_test"
//VERY IMPORTANT - include this last

#include <iostream>
#include <vector>

#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>
#include <boost/test/unit_test_suite.hpp>

//BOOST_AUTO_TEST_CASE(SingleImageHazeRemoval_get) {
//
//    SingleImageHazeRemoval *singleImageHazeRemoval = new HistogramEqualization();
//    std::string getSelectedMethod_out = "No Method Selected";
//    std::cout << "SAIDA" << singleImageHazeRemoval->getSelectedMethod() << std::endl;
//
////    BOOST_CHECK_EQUAL(getSelectedMethod_out, singleImageHazeRemoval.getSelectedMethod());
//
//}
