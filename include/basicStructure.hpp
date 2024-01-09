#ifndef BASICSTRUCTURE__HPP
#define BASICSTRUCTURE__HPP
#include <iostream>

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/contrib/contrib.hpp"
#include "opencv2/core/core.hpp"


using namespace std;

//Region of interest in 3D. (usually, we chose a 30X30 meteres wide area with 1m higher than the vision system )
struc