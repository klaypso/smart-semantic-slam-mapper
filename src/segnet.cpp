#include "segnet.h"

using namespace caffe;

Classifier::Classifier() 
{

#ifdef CPU_ONLY
	Caffe::set_mode(Caffe::CPU);
#else
	Caffe::set_mode(Caffe::GPU);
#endif

    //std::string model_file = "/home/relaybot/Desktop/slam3d/models/segnet_model_driving_webdemo.prototxt";
    //std::string trained_fil