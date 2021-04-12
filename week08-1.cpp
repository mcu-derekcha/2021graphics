#include <opencv/highgui.h>
int main()
{
    IplImage * img=cvLoadImage("puipui.jpg");
    cvShowImage("week08-1¨q¹Ï",img);
    cvWaitKey(0);
    CvCapture*cap=cvCreateCameraCaptrue(0);
    while(1)
    {
        img=cvQueryFrame(cap);
        cvShowImage("camera",img);
        int key=cvwaitKey(33);
        if(key==27)break;
    }
    cvReleseCapture(&cap);
}
