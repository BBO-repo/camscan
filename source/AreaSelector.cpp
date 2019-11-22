#include "AreaSelector.h"

AreaSelector::AreaSelector(std::string imageFilePath) : mImageFilePath(imageFilePath){
	// load image
	src = cv::imread(mImageFilePath);
	cv::resize(src, src, cv::Size(src.cols/4, src.rows/4));
}

AreaSelector::~AreaSelector() {}

void onMouseCallBack(int event, int x, int y, int flags, void* userdata) {
	AreaSelector* selector = static_cast<AreaSelector*>(userdata);
	if (selector) {
		selector->callBackFunc(event, x, y);
	}
}

void AreaSelector::selectArea(void) {
	
	// add new window
	cv::namedWindow(mWindowTitle,cv::WINDOW_AUTOSIZE);
	
	// update display
	updateDisplay();
	
	//set the callback function for any mouse event
    cv::setMouseCallback(mWindowTitle, onMouseCallBack, this);
	cv::waitKey(0);
	std::cout << "out form selectArea" << std::endl;
	return;
}

void AreaSelector::callBackFunc(int event, int x, int y)
{
	if ( mSelectedPoint == nSelectedPts) {
		return;
	}
	else if ( event == cv::EVENT_LBUTTONDOWN ) {
		// std::cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << std::endl;
		
		// add transformation source point
		src_p.push_back(cv::Point(x, y));
		
		// increment index for next transformation source point 
		mSelectedPoint++;
		
		//update display
		updateDisplay();		
	}
}

void AreaSelector::updateDisplay(void) {
	
	cv::Mat disp = src.clone();
	switch(mSelectedPoint) {
		case 0:
			// no point selected so just show image
			break;
		case 1:
			// one point selected so draw a point
			circle(disp, src_p[mSelectedPoint-1], 2, cv::Scalar(0,0,255), 2);
			break;
		case 2:
			// two points selected so draw a line
			cv::line(disp, src_p[mSelectedPoint-1], src_p[mSelectedPoint-2], cv::Scalar(0,0,255), 2);
			break;
		case 3:
			// three points selected so draw the two lines		
            cv::line(disp, src_p[mSelectedPoint-1], src_p[mSelectedPoint-2], cv::Scalar(0,0,255), 2);
            cv::line(disp, src_p[mSelectedPoint-2], src_p[mSelectedPoint-3], cv::Scalar(0,0,255), 2);
			break;
		case 4:
			// four points selected so draw the polygone
			const cv::Point *pts = (const cv::Point*) cv::Mat(src_p).data;

			// draw the polygon 
			cv::polylines(disp, &pts, &nSelectedPts, 1, true, cv::Scalar(0,0,255),2);

			break;
    }
	
	cv::imshow(mWindowTitle, disp);
}

void AreaSelector::getSelectedPoints(cv::Point2f selectedPts2f[4]) {
	
	for (int indP = 0; indP < nSelectedPts; ++indP) {
		selectedPts2f[indP] = (cv::Point2f) src_p[indP];
	}
	return;
}

const cv::Mat & AreaSelector::getSrcImageMat() {
	return src;
}

