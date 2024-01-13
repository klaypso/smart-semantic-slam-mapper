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
struct CAMERA_INTRINSIC_PARAMETERS
{
    // 标准内参
    double cx=0, cy=0, fx=0, fy=0, scale=0;
    // 畸变因子
    double d0=0, d1=0, d2=0, d3=0, d4=0;
};



// linux终端的颜色输出
#define RESET "\033[0m"
#define BLACK "\033[30m" /* Black */
#de