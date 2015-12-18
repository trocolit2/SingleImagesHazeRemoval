/*
 * main.cpp
 *
 *  Created on: Dec 17, 2015
 *      Author: tiagotrocoli
 */

#include <iostream>

#include <histogram/HistogramEqualization.h>
#include <histogram/CLAHE.h>

int main(int argc, char **argv) {

    SingleImageHazeRemoval *haveRemovalHistogramEqualization = new HistogramEqualization();
    std::cout << "\nMETHOD 2 " << haveRemovalHistogramEqualization->getSelectedMethod() << std::endl;

    SingleImageHazeRemoval *haveRemovalCLAHE = new CLAHE();
    std::cout << "\nMETHOD 3 " << haveRemovalCLAHE->getSelectedMethod() << std::endl;

    return 0;
}

