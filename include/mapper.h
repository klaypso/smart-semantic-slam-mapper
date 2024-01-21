#ifndef MAPPER_H
#define MAPPER_H

#include "common_headers.h"
#include "rgbdframe.h"
#include "pose_graph.h"

#include <pcl/common/transforms.h>
#include <pcl/point_types.h>

namespace rgbd_tutor
{
using namespace rgbd_tutor;

class Mapper
{
public:
    typedef pcl::PointXYZRGBA PointT;
    typedef pcl::PointCloud<PointT> PointCloud;

    Mapper( const ParameterReader& para, PoseGraph& graph )
        : parame