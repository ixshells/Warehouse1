//#include <opencv2/opencv.hpp>  
//using namespace std;  
//
//#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")  
//
//int main()  
//{  
//    const char *srcImageName = "E:\\MyPrograming\\OpenCVPainter\\Debug\\QQ图片20131113135738.jpg";  
//    const char *outImageName = "E:\\MyPrograming\\OpenCVPainter\\Debug\\ScaleImage.jpg";
//    const char *srcImageWindowName = "Source Window";
//    const char *outImageWindowName = "Dst Window";
//     
//    double  fScale =3.0;
//    CvSize scaleSize;
//    
//    IplImage* srcImage = cvLoadImage(srcImageName,CV_LOAD_IMAGE_UNCHANGED);
//    IplImage* dstImage = NULL;
//
//    scaleSize.width = (int)srcImage->width*fScale;
//    scaleSize.height = (int)srcImage->height*fScale;
//
//    dstImage = cvCreateImage(scaleSize,srcImage->depth,srcImage->nChannels);
//    cvResize(srcImage,dstImage,CV_INTER_NN  );
//
//    //创建窗口  
//    cvNamedWindow(srcImageWindowName, CV_WINDOW_AUTOSIZE);  
//    cvNamedWindow(outImageWindowName, CV_WINDOW_AUTOSIZE);  
//
//    //在指定窗口中显示图像  
//    cvShowImage(srcImageWindowName, srcImage);  
//    cvShowImage(outImageWindowName, dstImage);  
//
//    cvWaitKey(); 
//
//    cvSaveImage(outImageName, dstImage);  
//
//    cvDestroyWindow(srcImageWindowName);  
//    cvDestroyWindow(outImageWindowName);  
//    cvReleaseImage(&srcImage);  
//    cvReleaseImage(&dstImage);  
// 
//    return 0;  
//}