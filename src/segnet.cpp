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
		<< "Input layer should have 1 or 3 channels.";
	input_geometry_ = cv::Size(input_layer->width(), input_layer->height());

	/* Load the binaryproto mean file. */
	SetMean();

	/* Load labels. */
	std::ifstream labels(label_file.c_str());
	CHECK(labels) << "Unable to open labels file " << label_file;
	std::string line;
	while (std::getline(labels, line))
		labels_.push_back(string(line));

	//Blob<float>* output_layer = net_->output_blobs()[0];
}

std::vector<int> Classifier::Argmax(const std::vector<float>& v, int N) 
{
	// specify capacity
	Blob<float>* output_layer = net_->output_blobs()[0];
	//int output_channels = output_layer->channels();
	int output_size = output_layer->height() * output_layer->width();

	std::vector<int> result;
	result.reserve(output_size);
	for (int i = 0; i < output_size; ++i)
	{
		int idx = int(v[i]);
		resu