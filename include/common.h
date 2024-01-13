#ifndef COMMON_H
#define COMMON_H

/**
 * common.h
 * 定义一些常用的结构体
 * 以及各种可能用到的头文件，放在一起方便include
 */

// C++标准库
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
using namespace std;


// Eigen
#include <Eigen/Core>
#include <Eigen/Geometry>

// OpenCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>

// boost
#include <boost/format.hpp>
#include <boost/timer.hpp>
#include <boost/lexical_cast.hpp>

namespace rgbd_tutor
{

// 相机内参模型
// 增加了畸变参数，虽然可能不会用到
struct CAMERA_INTRINSIC_PARA