#include "stereo.h"
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

/*---------  Calculate the disparity may by SGBM algorithm
* img_L, img_R ----------- Rectified left and right image 
* disp         ----------- The disparity result
*/
void calDisparity_SGBM(const cv::Mat& img_L, const cv::Mat& img_R, cv::Mat& disp)
{
	cv::StereoSGBM sgbm;

	// set the parameters of sgbm
	int cn = 1; //number of channels
	int SADWindowSize = 11; //Matched block size. It must be an odd number >=1 . Normally, it should be somewhere in the 3..11 range.
	int numberOfDisparities = 80; //Maximum disparity minus minimum disparity, must be n*16
	sgbm.minDisparity = 0; //Minimum possible disparity value
	sgbm.uniquenessRatio = 10;
	sgbm.speckleWindowSize = 100;
	sgbm.preFilterCap = 63; //Truncation value for the prefiltered image pixels
	sgbm.SADWindowSize = SADWindowSize > 0 ? SADWindowSize : 3;
	sgbm.P1 = 4*cn*sgbm.SADWindowSize*sgbm.SADWindowSize; //controlling the disparity smoothness. P2 > P1
	sgbm.P2 = 32*cn*sgbm.SADWindowSize*sgbm.SADWindowSize; //controlling the disparity smoothness.The larger the values are, the smoother the disparity is
	sgbm.numberOfDisparities = numberOfDisparities;
	sgbm.speckleRange = 32; // devided by 16, 1 or 2 is good enough
	sgbm.disp12MaxDiff = 1;

	sgbm(img_L, img_R, disp);    
/*
	cv::Mat disp8; //scaling the value into 0-255
	disp.convertTo(disp8, CV_8U, 255/(numberOfDisparities*16.));
	cv::Mat img_equalize,img_color;
	cv::equalizeHist(disp8,img_equalize);
	imshow("disp8", disp8);
*/
}


void triangulate10D(const cv::Mat& img, const cv::Mat& disp, cv::Mat& xyz,
                   const double f, const double cx, const double cy, const double b, ROI3D roi)
{
    //test
    int stype = disp.type();
    int dtype = CV_32FC3;
    //CV_Assert(stype == CV_16SC1);
    xyz.create(disp.size(),CV_MAKETYPE(dty