//
// Created by mumu on 6/5/18.
//

#include "rgbdframe.h"
#include "parameter_reader.h"
#include "orb.h"


#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>

using namespace std;
using namespace rgbd_tutor;
using namespace cv;
int main()
{
    ParameterReader para;
    FrameReader frameReader( para );
    OrbFeature  orb(para);


    RGBDFrame::Ptr refFrame = frameReader.next();
    orb.detectFeatures( refFrame );
    Eigen::Isometry3d   speed = Eigen::Isometry3d::Identity();

    while (1)
    {
        cout<<"*************************************"<<endl;
        RGBDFrame::Ptr currFrame = frameReader.next();

        std::vector<KeyPoint> keypoint1,keypoint2;
        Mat descriptors_1,descriptors_2;
        Ptr<ORB> orb ;//= ORB::create(500,1.2f,8,31,0,2,ORB::HARRIS_SCORE,31,20);

        orb->detect(re