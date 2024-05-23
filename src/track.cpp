#include "track.h"
#include <unistd.h>
#include "readFile.h"

// tracker的主线程
using namespace rgbd_tutor;

Eigen::Isometry3d Tracker::updateFrame( RGBDFrame::Ptr& newFrame )
{
    unique_lock<mu