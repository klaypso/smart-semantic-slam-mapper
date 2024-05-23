#include "track.h"
#include <unistd.h>
#include "readFile.h"

// tracker的主线程
using namespace rgbd_tutor;

Eigen::Isometry3d Tracker::updateFrame( RGBDFrame::Ptr& newFrame )
{
    unique_lock<mutex> lck(adjustMutex);
    currentFrame = newFrame;
    if ( state == NOT_READY )
    {
        initFirstFrame( );
        return Eigen::Isometry3d::Identity();
    }
    if ( state == OK )
    {
	    estimateVO();//在slam3d的代码里使用的是这个函数，下面的被注释
        //trackRefFrame();//下面的trackrefframe来自于高博的RGBDFrame跟踪
        return currentFrame->getTransform();
    }
    // state = LOST

    lostRecover();
    return currentFrame->get