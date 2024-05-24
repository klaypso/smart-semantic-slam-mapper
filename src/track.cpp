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
    return currentFrame->getTransform();

}

void Tracker::initFirstFrame( )
{
    orb->detectFeatures( currentFrame );
    refFrames.push_back(currentFrame);
    speed = Eigen::Isometry3d::Identity();
    state = OK;
}

void Tracker::estimateVO( )
{    
	// 初始值
    	currentFrame->setTransform( speed * refFrames.back()->getTransform() );
    	orb->detectFeatures( currentFrame );
    
	// VISO2
	QuadFeatureMatch* quadmatcher = new QuadFeatureMatch(currentFrame->img_lc,
                                                         currentFrame->img_rc,
                                                         currentFrame->img_lp,
                                                         currentFrame->img_rp,
                                                         currentFrame->semantic_cur_r,
                                               