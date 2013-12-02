#include <opencv2/opencv.hpp>
#include "stdio.h"
using namespace std;

//#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")  

const char* srcImageFilePath = "E:\\MyPrograming\\OpenCVPainter\\Debug\\QQ图片20131113135738.jpg";;
IplImage* srcImage  = NULL;
IplImage* dstImage = NULL;
IplImage* srcImageY = NULL;
IplImage* handleImage = NULL;

void callBack(int value)
{
    cvThreshold(srcImage, dstImage, value, 255, CV_THRESH_BINARY);  

    unsigned char* rowDst =  (unsigned char*)dstImage->imageData;
    unsigned char* rowSrc =  (unsigned char*)srcImageY->imageData;
    unsigned char* rowHandle = (unsigned char*)handleImage->imageData;

    for(int h=0;h<dstImage->height;h++)
    {
        rowDst = (unsigned char*)(dstImage->imageData + dstImage->widthStep*h);
        rowSrc = (unsigned char*)(srcImageY->imageData + srcImageY->widthStep*h);
        rowHandle = (unsigned char*)(handleImage->imageData + handleImage->widthStep*h);
        for(int w=0;w<dstImage->width;w++)
        {
            int idx = w*3;
            //for(int i=0;i<3;i++)
            //{
            //    printf("%d,",dstImage[idx+i]);
            //}
            rowHandle[idx] = rowSrc[idx];
            rowHandle[idx+1] = rowSrc[idx+1];
            rowHandle[idx+2] = rowSrc[idx+2];

            if(rowDst[w] == 0)
            {
                rowHandle[idx] = 255;
                rowHandle[idx+1]=255;
                rowHandle[idx+2] = 255;
            }
        }
    }

    CvMemStorage *pcvMStorage = cvCreateMemStorage();  
    CvSeq *pcvSeq = NULL;  
    cvFindContours(dstImage, pcvMStorage, &pcvSeq, sizeof(CvContour), CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cvPoint(0, 0));  

    // 画轮廓图  
    IplImage *pOutlineImage = cvCreateImage(cvGetSize(srcImage), IPL_DEPTH_8U, 3);  
    int nLevels = 5;  
    // 填充成白色  
    cvRectangle(pOutlineImage, cvPoint(0, 0), cvPoint(pOutlineImage->width, pOutlineImage->height), CV_RGB(255, 255, 255), CV_FILLED);  
    cvDrawContours(pOutlineImage, pcvSeq, CV_RGB(255,0,0), CV_RGB(0,255,0), nLevels, 2); 

    cvNamedWindow("lunkuo", CV_WINDOW_AUTOSIZE);  
    cvShowImage("lunkuo", pOutlineImage);  

    //cvShowImage("DstCandy", dstImage);  
    cvShowImage("DstCandy", handleImage); 

    cvNamedWindow("二值化图",CV_WINDOW_AUTOSIZE);
    cvShowImage("二值化图",dstImage);
}

int main()
{
    srcImage = cvLoadImage(srcImageFilePath,CV_LOAD_IMAGE_GRAYSCALE);
    dstImage = cvCreateImage(cvGetSize(srcImage),srcImage->depth,srcImage->nChannels);
    srcImageY = cvLoadImage(srcImageFilePath,CV_LOAD_IMAGE_UNCHANGED);
    handleImage = cvCreateImage(cvGetSize(srcImageY),srcImageY->depth,srcImageY->nChannels);

    int value = 10;
    cvNamedWindow("Candy",CV_WINDOW_AUTOSIZE);
    cvNamedWindow("DstCandy",CV_WINDOW_AUTOSIZE);
    cvCreateTrackbar("candySlider","DstCandy",&value,255,callBack);
    callBack(88);

   
    unsigned char* rowDst =  (unsigned char*)dstImage->imageData;
    unsigned char* rowSrc =  (unsigned char*)srcImageY->imageData;
    unsigned char* rowHandle = (unsigned char*)handleImage->imageData;

    for(int h=0;h<dstImage->height;h++)
    {
        rowDst = (unsigned char*)(dstImage->imageData + dstImage->widthStep*h);
        rowSrc = (unsigned char*)(srcImageY->imageData + srcImageY->widthStep*h);
        rowHandle = (unsigned char*)(handleImage->imageData + handleImage->widthStep*h);
        for(int w=0;w<dstImage->width;w++)
        {
            int idx = w*3;
            //for(int i=0;i<3;i++)
            //{
            //    printf("%d,",dstImage[idx+i]);
            //}
            rowHandle[idx] = rowSrc[idx];
            rowHandle[idx+1] = rowSrc[idx+1];
            rowHandle[idx+2] = rowSrc[idx+2];

            if(rowDst[w] == 0)
            {
                rowHandle[idx] = 255;
                rowHandle[idx+1]=255;
                rowHandle[idx+2] = 255;
            }
        }
    }

    
    cvShowImage("Candy", srcImageY);  
    cvShowImage("DstCandy", dstImage);  

    cvWaitKey(); 
    cvDestroyWindow("Candy");
    //cvDestroyWindow("DstCandy");
    cvReleaseImage(&srcImage);
    cvReleaseImage(&dstImage);
    cvReleaseImage(&srcImageY);
    cvReleaseImage(&handleImage);

    return 1;
}