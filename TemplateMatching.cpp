//
// Created by taher on 10/11/15.
//

#include "TemplateMatching.h"


TemplateMatching::TemplateMatching(char * image, char * templateImage, int method )
{
    /// Load image and template
    img = imread( image, 1 );
    templ = imread( templateImage, 1 );


    /**
    Avilable Methodes :

     0: SQDIFF
     1: SQDIFF NORMED
     2: TM CCORR
     3: TM CCORR NORMED
     4: TM COEFF
     5: TM COEFF NORMED

     **/


    /// Set Matching Methode
    match_method = method ;
}

/**
 * @function MatchingMethod
 * @brief Trackbar callback
 */
Point TemplateMatching::MatchingMethod(int, void *)
{
    /// Source image to display
    Mat img_display;
    img.copyTo( img_display );

    /// Create the result matrix
    int result_cols =  img.cols - templ.cols + 1;
    int result_rows = img.rows - templ.rows + 1;

    result.create( result_rows, result_cols, CV_32FC1 );

    /// Do the Matching and Normalize
    matchTemplate( img, templ, result, match_method );
    normalize( result, result, 0, 1, NORM_MINMAX, -1, Mat() );

    /// Localizing the best match with minMaxLoc
    double minVal; double maxVal; Point minLoc; Point maxLoc;
    Point matchLoc;

    minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );


    /// For SQDIFF and SQDIFF_NORMED, the best matches are lower values. For all the other methods, the higher the better
    if( match_method  == TM_SQDIFF || match_method == TM_SQDIFF_NORMED )
    { matchLoc = minLoc; }
    else
    { matchLoc = maxLoc; }

    /// Show me what you got

    //  rectangle( result, matchLoc, Point( matchLoc.x + templ.cols , matchLoc.y + templ.rows ), Scalar::all(0), 2, 8, 0 );
    targetResult = Point( matchLoc.x + templ.cols , matchLoc.y + templ.rows );

    return targetResult;
}