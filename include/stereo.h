#ifndef STEREO__HPP
#define STEREO__HPP

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "basicStructure.hpp"

/*---------  Calculate the disparity may by semi-global block matching (SGBM) algorithm
* img_L, img_R ----------- Rectified left and right image 
* disp         ----------- The disparity result
*/
void c