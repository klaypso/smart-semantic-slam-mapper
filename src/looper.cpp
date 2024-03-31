#include "looper.h"

using namespace rgbd_tutor;

vector<RGBDFrame::Ptr> Looper::getPossibleLoops( const RGBDFrame::Ptr& frame )
{
    vector<RGBDFrame::Ptr>  result;
    for ( size_t i=0; i<frames.size(); i++ )
    {
        RGBDFrame::Ptr pf = frames[i];
        double  score = vocab.score( frame->bowVec