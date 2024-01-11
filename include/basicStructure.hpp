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
struct ROI3D
{
  ROI3D():x_max(30000),y_max(-1000),z_max(30000){};

  ROI3D(double x, double y, double z)
    {
      x_max = x;
      y_max = y;
      z_max = z;
      
    };

  inline ROI3D& operator=(const ROI3D &t)
    {
      x_max = t.x_max;
      y_max = t.y_max;
      z_max = t.z_max;
      return *this;
    };
  
  double x_max;
  double y_max;//is negtive always
  double z_max;
};


//stereo calibration parameters
struct Ca