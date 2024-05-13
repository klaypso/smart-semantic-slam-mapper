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
	sgbm.speckleRan