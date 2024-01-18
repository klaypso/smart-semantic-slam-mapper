#ifndef FEATURE_H
#define FEATURE_H

#include "common_headers.h"

namespace rgbd_tutor
{

class Feature
{
public:
    Feature( ) {}
public:
    cv::KeyPoint    keypoint;
    cv::Ma