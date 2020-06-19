#include <opencv2/opencv.hpp>
#include "../include/loadData.h"
#include "../include/constants.h"

cv::Point2f loadGroundTruth(const std::string &pose) {
    float x, y;
    std::istringstream parser(pose);

    for (int i = 0; i < 12; i++) {
        parser >> y;
        if (i == 3) x = y;
    }
    return cv::Point2f(x+300, y+100);
}

double getScale(int frameCnt) {
    std::string line;
    int i = 0;
    std::ifstream myfile(POSE_LOCATION);
    double x =0, y=0, z = 0;
    double x_prev, y_prev, z_prev;

    if (myfile.is_open()) {
        while (( getline (myfile,line) ) && (i<=frameCnt)) {
            z_prev = z;
            x_prev = x;
            y_prev = y;
            std::istringstream in(line);
            for (int j=0; j<12; j++)  {
                in >> z ;
                if (j==7) y=z;
                if (j==3)  x=z;
            }
            i++;
        }
        myfile.close();
    }

    else {
        std::cout << "Unable to open file\n";
        return 0;
    }
    return sqrt((x-x_prev)*(x-x_prev) + (y-y_prev)*(y-y_prev) + (z-z_prev)*(z-z_prev)) ;
}
