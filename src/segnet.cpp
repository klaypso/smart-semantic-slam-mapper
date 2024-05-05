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
    std::string model_file = "../models/segnet_model_driving_webdemo.prototxt";
    std::string trained_file = "../models/segnet_weights_driving_webdemo.caffemodel";
    std::string label_file = "../models/semantic12.txt";

	/* Load the network. */
	net_.reset(new Net<float>(model_file, TEST));
	net_->CopyTrainedLayersFrom(trained_file);

	CHECK_EQ(net_->num_inputs(), 1) << "Network should have exactly one input.";
	CHECK_EQ(net_->num_outputs(), 1) << "Network should have exactly one output.";

	Blob<float>* input_layer = net_->input_blobs()[0];
	num_channels_ = input_layer->channels();
	CHECK(num_channels_ == 3 || num_channels_ == 1)
		<