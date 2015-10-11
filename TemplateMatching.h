//
// Created by taher on 10/11/15.
//

#ifndef IMAGEMATCHING_TEMPLATEMATCHING_H
#define IMAGEMATCHING_TEMPLATEMATCHING_H

#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;



class TemplateMatching {

public:
    /// Global Variables

    Mat img; Mat templ; Mat result;
    const char* image_window = "Source Image";
    const char* result_window = "Result window";

    int match_method;
    int max_Trackbar = 5;

    Point targetResult;

    /// Function Headers
    Point MatchingMethod( int, void* );
    TemplateMatching(char* , char* , int  = 5);


};


#endif //IMAGEMATCHING_TEMPLATEMATCHING_H
