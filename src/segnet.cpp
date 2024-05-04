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
    //std::string trained_file = "/home/relaybot/Desktop/slam3d/models/segnet_weights_driving_webdemo.caffemodel";
    //std::string label_file = "/home/relaybot/Desktop/slam3d/models/semantic12.txt";
    std::string model_fi