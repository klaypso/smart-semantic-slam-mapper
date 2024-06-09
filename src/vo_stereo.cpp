/*
   IRTES-SET laboratory
   Authors: You Li (liyou026@gmail.com)
   Descirption: This a sample code of my PhD works
*/

#include "vo_stereo.hpp"

using namespace std;

VisualOdometryStereo::VisualOdometryStereo (parameters param) : param(param), VisualOdometry(param)
{
}

VisualOdometryStereo::~VisualOdometryStereo() {
}


bool VisualOdometryStereo::Process(QuadFeatureMatch& quadmatcher)
{

    quadmatches.clear();
    int num = quadmatcher.quadmatches.size();

    //copy to visual odo