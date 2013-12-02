#include <opencv2/opencv.hpp>  
using namespace std;  

#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")  

int main()  
{  
    const char *pstrImageName = "���˴�ʦ��001.jpg";  
    const char *pstrWindowsTitle = "OpenCV��һ������(http://blog.csdn.net/MoreWindows)";  

    //���ļ��ж�ȡͼ��  
    IplImage *pImage = cvLoadImage(pstrImageName, CV_LOAD_IMAGE_UNCHANGED);  

    //��������  
    cvNamedWindow(pstrWindowsTitle, CV_WINDOW_AUTOSIZE);  

    //��ָ����������ʾͼ��  
    cvShowImage(pstrWindowsTitle, pImage);  

    //�ȴ������¼�  
    cvWaitKey();  

    cvDestroyWindow(pstrWindowsTitle);  
    cvReleaseImage(&pImage);  
    return 0;  
}