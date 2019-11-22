#include "Transformer.h"
#include "AreaSelector.h"

int main(int argc, char ** argv) {
  // select area in image
  AreaSelector areaSelector("resources/hello.jpg");
  areaSelector.selectArea();
  
  // get the transform image based on selected points
  cv::Point2f selectedPts[4];
  areaSelector.getSelectedPoints(selectedPts);
  
  cv::Mat dest = transformer::transform(areaSelector.getSrcImageMat(), selectedPts);
  
  // display rtansform image
  cv::imshow("Transformed image", dest);
  cv::waitKey(0);
  
  return(0);
}
