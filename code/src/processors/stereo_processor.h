#ifndef STEREO_PROCESSOR_H
#define STEREO_PROCESSOR_H

#include "two_image_processor.h"
#include <highgui.h>

using namespace cv;

class StereoProcessor : public TwoImageProcessor
{
	Q_OBJECT

public:
	StereoProcessor(QObject *parent = 0);
	~StereoProcessor();

	QString name() {return "Stereo matching";}

	Mat medianFilter(Mat * mat, int filtersize);

private:
	bool dynamicProgramming();
	void run();
	Mat initial_leftDepthMap; // Takes integer values
	Mat initial_rightDepthMap; // Takes integer values
	Mat correctedLeftDepthMap; // Mapped to 0...255 for output
	Mat correctedRightDepthMap; // Mapped to 0...255 for output
	Mat A; // dynamic programming matrix
	Mat prev_path; // optimising matrix
};

#endif
