/*
   IRTES-SET laboratory
   Authors: You Li (liyou026@gmail.com)
   Descirption: This a sample code of my PhD works
*/

#ifndef QUADMATCHER__HPP
#define QUADMATCHER__HPP

#include <iostream>

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/contrib/contrib.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/nonfree/features2d.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#include "opencv2/video/tracking.hpp"

using namespace std;
using namespace cv;


enum { DET_FAST, DET_STAR, DET_ORB, DET_SIFT, DET_SURF, DET_GFTT,
       DET_STAR_ADAPT, DET_FAST_ADAPT, DET_FAST_GRID, DET_STAR_GRID,DET_GFTT_GRID};

enum { DES_SIFT, DES_SURF, DES_BRISK, DES_FREAK,DES_ORB};


//core struct storing quadmatching result
struct pmatch {
    float   u1p,v1p; // u,v-coordinates in previous left  image
    int32_t i1p;     // feature index (for tracking)
    float   u2p,v2p; // u,v-coordinates in previous right image
    int32_t i2p;     // feature index (