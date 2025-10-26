#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include<vector>
using namespace cv;
using namespace std;
string check(Mat& mat,Rect& light);
void End(Mat& mat,const string& color,const Rect& rect);

int main(){
    VideoCapture cap("../TrafficLight.mp4");
    if (!cap.isOpened()) {
        cout << "无法打开摄像头!" << endl;
        return -1;}

    int width=cap.get(CAP_PROP_FRAME_WIDTH);
    int height=cap.get(CAP_PROP_FRAME_HEIGHT);
    double fps=cap.get(CAP_PROP_FPS);

    VideoWriter writer("result.avi",
        VideoWriter::fourcc('M','J','P','G'),
        fps,Size(width,height));

    Mat frame;
    while (true) {
        cap >> frame;   
        if (frame.empty()){
            break;} 
        Rect light;
        string color=check(frame,light);
        if(light.area()>0){
            End(frame,color,light);}
        Scalar wordColor;
        if(color=="red"){
            wordColor=Scalar(0,0,255);
        }else{
            wordColor=Scalar(0,255,0);
        }

        putText(frame,color,Point(150,170),
                FONT_HERSHEY_SIMPLEX,8,wordColor,10);

        namedWindow("交通灯视频结果", WINDOW_NORMAL);
        resizeWindow("交通灯视频结果", 800, 600);   
        imshow("交通灯视频结果", frame);
        writer.write(frame);
        if (waitKey(30) == 27) {
            break;}}
    cap.release();
    writer.release();
    destroyAllWindows();  
}
string check(Mat& frame,Rect& light){
    Mat hsv;
    cvtColor(frame,hsv,COLOR_BGR2HSV);

    Mat red_1,red_2,red_0,green;
    inRange(hsv,Scalar(0,150,100),Scalar(10,255,255),red_1);
    inRange(hsv,Scalar(170,150,100),Scalar(180,255,255),red_2);
    red_0=red_1|red_2;
    inRange(hsv,Scalar(40,80,80),Scalar(90,255,255),green);  
    //声明轮廓集合.   单个轮廓：vector<Point> contour
    vector<vector<Point>> red_contours,green_contours;
    findContours(red_0,red_contours,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
    findContours(green,green_contours,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);

    double max_area=0;
    string check_color="?";
    light=Rect();
    if(!red_contours.empty()){
        for(size_t i=0;i<red_contours.size();i++){
            double area=contourArea(red_contours[i]);
            if(area>max_area&&area>150){
                max_area=area;
                light=boundingRect(red_contours[i]);
                check_color="red";
            }
        }
    }
    for(size_t i=0;i<green_contours.size();i++){
        double area=contourArea(green_contours[i]);
        if(area>max_area&&area>100){
            max_area=area;
            light=boundingRect(green_contours[i]);
            check_color="green";
        }
    }
    return check_color;
}
void End(Mat& mat,const string& color,const Rect& rect){
    Scalar borderColor;
    if(color=="red"){
        borderColor=Scalar(0,0,255);
    }else{
        borderColor=Scalar(0,255,0);
    }
    rectangle(mat,rect,borderColor,15);
}