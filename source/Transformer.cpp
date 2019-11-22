#include "Transformer.h"


cv::Mat transformer::transform(const cv::Mat & src, cv::Point2f src_p[4]) {
	
	float w  = (float)src.cols;
	float h  = (float)src.rows;
	
	// destination points should be the whole image (TODO replace taking into account area and vertices)
	cv::Point2f dst_p[4];
	dst_p[0] = cv::Point2f(0.0f, 0.0f);
	dst_p[1] = cv::Point2f(w, 0.0f);
	dst_p[2] = cv::Point2f(w,h);
	dst_p[3] = cv::Point2f(0.0f,h);
	
	// create perspective transform matrix
	cv::Mat trans_mat33 = cv::getPerspectiveTransform(src_p, dst_p); //CV_64F->double

	// perspective transform operation using transform matrix
	cv::Mat dest = src.clone();
	cv::warpPerspective(src, dest, trans_mat33, src.size(), cv::INTER_LINEAR);
	
	return dest;
}
