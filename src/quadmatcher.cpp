
/*
   IRTES-SET laboratory
   Authors: You Li (liyou026@gmail.com)
   Descirption: This a sample code of my PhD works
*/

#include "quadmatcher.hpp"
#include <array>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/contrib/contrib.hpp"
#include "opencv2/core/core.hpp"


using namespace cv;
using namespace std;







QuadFeatureMatch::QuadFeatureMatch(cv::Mat& img_lc_,cv::Mat& img_rc_,
                                   cv::Mat& img_lp_, cv::Mat& img_rp_,
				   cv::Mat& img_s_rc_, cv::Mat& img_s_rp_,
                                   bool mode_track_)
{
   img_lc = img_lc_;
   img_rc = img_rc_;
   img_lp = img_lp_;
   img_rp = img_rp_;
   img_s_rc = img_s_rc_;
   img_s_rp = img_s_rp_;

   mode_track = mode_track_;
}


void QuadFeatureMatch::matching(vector<KeyPoint>& keypoints1, cv::Mat& descriptors1,
                                 vector<KeyPoint>& keypoints2, cv::Mat& descriptors2,
                                 int search_width, int search_height, vector<DMatch>& matches)
 {