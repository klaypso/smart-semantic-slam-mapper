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
   