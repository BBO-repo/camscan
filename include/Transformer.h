#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

namespace transformer {
	cv::Mat transform(const cv::Mat & src, cv::Point2f src_p[4]);
}


#endif // TRANSFORMER_H

