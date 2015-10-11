/**
 * @file MatchTemplate_Demo.cpp
 * @brief Sample code to use the function MatchTemplate
 * @author OpenCV team
 */
#include "TemplateMatching.h"

/**
 * @function main
 */

int main( int, char** argv )
{
    /// Load image and template
    std::string simg1 = "X3.jpg" ;
    char* img1 = (char *) simg1.c_str();
    std::string simg2 = "tX.png" ;
    char* img2 = (char *) simg2.c_str();

    TemplateMatching A (img1 , img2 );
    /// The OpenCV Template Matching Algorithm
    Point result = A.MatchingMethod( 0 , 0 );

    printf("x:%d \ny:%d\n",result.x,result.y);

    waitKey(0);
    return 0;
}
