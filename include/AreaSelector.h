#ifndef AREASELECTOR_H
#define AREASELECTOR_H

#include <string>
#include <iostream>
#include <vector>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>


class AreaSelector {
	private:
	std::string mImageFilePath;
	cv::Mat src;
	
	int mSelectedPoint {0};
	int nSelectedPts {4};
	std::vector<cv::Point> src_p;

	std::string mWindowTitle {"Click on image to select 4 source transformation points and press a key"};
	void updateDisplay(void);
	void callBackFunc(int event, int x, int y);
	friend void onMouseCallBack(int event, int x, int y, int flags, void* userdata);

	
	public:
	AreaSelector(std::string imageFilePath);
	~AreaSelector();
	void selectArea(void);
	void getSelectedPoints(cv::Point2f selectedPts2f[4]);
	const cv::Mat & getSrcImageMat();
};

#endif // AREASELECTOR_H

