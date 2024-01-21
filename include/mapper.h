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
        : parameterReader( para ), poseGraph( graph )
    {
	    resolution = para.getData<double>("mapper_resolution");
        max_distance = para.getData<double>("mapper_max_distance");
        viewerThread = std::make_shared<std::thread> ( std::bind( &Mapper::viewer, this ));

	    area_thres = para.getData<int>("motion_area_thres");
        overlay_portion_thres = para.getData<double>("motion_overl