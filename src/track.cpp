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
                                                         currentFrame->semantic_pre_r,
                                                         true);
	quadmatcher->init(DET_GFTT,DES_SIFT);
    //GFTT——cvGoodFeaturesToTrack 特征点
	quadmatcher->detectFeature();
	quadmatcher->circularMatching();

	//visual odometry valid
	bool success = false;
	if (viso.Process(*quadmatcher) == true)
	{
		//get ego-motion matrix (6DOF)
		cv::Mat motion;
		motion = viso.getMotion();
		//cout << "motion: " << motion << endl;

		// moving
		triangulate10D(currentFrame->img_lc,
                       currentFrame->disparity,
                       currentFrame->xyz,
                       calib_.f, calib_.c_x, calib_.c_y, calib_.b,
                       roi_3d);

		currentFrame->moving_mask = uv_disparity.Process(
                currentFrame->img_lc, //左图
                currentFrame->disparity, //SGBM得来的深度图
                viso,
                currentFrame->xyz,
                currentFrame->roi_mask,
                currentFrame->ground_mask, pitch1, pitch2);

		//visual odometry
		Matrix_ M = Matrix_::eye(4);
		for (int32_t i=0; i<4; ++i)
			for (int32_t j=0; j<4; ++j)
				M.val[i][j] = motion.at<double>(i,j);
		poseChanged = poseChanged * Matrix_::inv(M);
		pos