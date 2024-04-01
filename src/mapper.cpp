
#include "mapper.h"

#include <pcl/visualization/cloud_viewer.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/pcl_visualizer.h>
//#include <pcl/filters/radius_outlier_removal.h>  
//#include <pcl/filters/statistical_outlier_removal.h>

using namespace rgbd_tutor;

Mapper::PointCloud::Ptr Mapper::generatePointCloud( const RGBDFrame::Ptr &frame )
{
    semantic_motion_fuse(frame);

    PointCloud::Ptr tmp( new PointCloud() );
    if ( frame->pointcloud == nullptr )
    {
        // point cloud is null ptr
        frame->pointcloud = boost::make_shared<PointCloud>();
#pragma omp parallel for
        for ( int m=0; m<frame->depth.rows; m+=1 )
        {
	        uchar* motion_ptr = moving_mask.ptr<uchar>(m);
            for ( int n=0; n<frame->depth.cols; n+=1 )
            {
                ushort d = frame->depth.ptr<ushort>(m)[n];
                if (d == 0)
                    continue;  //深度为0，不考虑
                if (d > max_distance * frame->camera.scale)
                    continue; //距离较远的点，不考虑