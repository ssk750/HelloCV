## 一、图像读取与显示
 1.1 图像读取  

#include <opencv2/opencv.hpp>

#include <opencv2/imgproc/imgproc.hpp>

#include <opencv2/highgui/highgui.hpp>

#include <iostream>

using namespace cv;

using namespace std;



int main() {

    // 读取图像 - 不同模式

Mat img_1 = imread("image.jpg~~_**(路径)**_~~",读取标志 );

常用读取标志

IMREAD_COLOR: 彩色图像(3通道BGR)

IMREAD_GRAYSCALE: 灰度图像(1通道)

IMREAD_UNCHANGED: 原样读取(包含alpha通道)

检查是否加载成功

if (img_1.empty()) {

       cout << "无法加载图像!" << endl;

       return -1;}

1.2 图像显示

// 显示图像                                        //窗口大小可调节

imshow("Color Image", img_1);

namedWindow("输入窗口",WINDOW_FREERATIO)

imshow("输入窗口",img_1)

```plain
WINDOW_NORMAL      // 用户可以调整窗口大小
WINDOW_AUTOSIZE    // 自动根据图像大小调整（默认）
WINDOW_FREERATIO   // 用户可以自由调整比例
WINDOW_KEEPRATIO   // 调整时保持图像比例
WINDOW_GUI_NORMAL  // 旧版窗口
WINDOW_GUI_EXPANDED //带状态栏和工具栏
```

// 控制窗口显示

int key = waitKey(0);  // 0表示无限等待，正整数表示等待毫秒数

if (key == 27) {  // ESC键

    destroyAllWindows();}  

1.3 图像保存 // 保存图像

imwrite("output.jpg", img_color);

imwrite("output.png", img_grayscale);  

## 二、图像属性与像素操作 
2.1 图像属性 // 获取图像基本属性

cout << "图像行数(高度): " << img_color.rows 

列数(宽度:.cols              总像素数:.total() 

通道数:r.channels()        图像数据类型:.type() 

2.2 像素访问 

_// 方法1: at<> 方法访问像素_

_// 彩色图像(BGR顺序)_

for (int y = 0; y < img_color.rows; y++) {

    for (int x = 0; x < img_color.cols; x++) {

        Vec3b pixel = img_color.at<Vec3b>(y, x);

        uchar blue = pixel[0];   _// B通道_

        uchar green = pixel[1]; _ // G通道_  

        uchar red = pixel[2];    _// R通道_

        // 修改像素值

        img_color.at<Vec3b>(y,x)=Vec3b(255,0,0); //设为蓝}}

// 对于灰度图像

for (int y = 0; y < img_grayscale.rows; y++) {

    for (int x = 0; x < img_grayscale.cols; x++) {

        uchar pixel = img_grayscale.at<uchar>(y, x);

        img_grayscale.at<uchar>(y,x)=255-pixel;//反色处理}}

// 方法2: ptr<> 指针方法(效率高)

for (int y = 0; y < img_color.rows; y++) {

    Vec3b* row = img_color.ptr<Vec3b>(y);

    for (int x = 0; x < img_color.cols; x++) {

        row[x][0] = 255; // B通道

        row[x][1] = 0;   // G通道

        row[x][2] = 0;   // R通道}} 

视频属性

对象.capture()

CV_CAP_PROP_POS_MSEC // 视频当前位置（毫秒）

CV_CAP_PROP_POS_FRAMES //下一帧的索引（从0开始）

CV_CAP_PROP_POS_AVI_RATIO //视频文件的相对位置（0=开始，1=结束）

CV_CAP_PROP_FRAME_WIDTH    // 视频帧的宽度

CV_CAP_PROP_FRAME_HEIGHT   // 视频帧的高度

CV_CAP_PROP_FPS            // 帧率

CV_CAP_PROP_FOURCC         // 编码器的四字符代码

CV_CAP_PROP_FRAME_COUNT  // 视频文件中的总帧数

CV_CAP_PROP_FORMAT         // 返回的Mat对象的格式

CV_CAP_PROP_MODE           // 后端特定的值，指示当前捕获模式

CV_CAP_PROP_BRIGHTNESS     // 亮度（仅适用于摄像头）

CV_CAP_PROP_CONTRAST       // 对比度（仅适用于摄像头）

CV_CAP_PROP_SATURATION     // 饱和度（仅适用于摄像头）

CV_CAP_PROP_HUE            // 色调（仅适用于摄像头）

CV_CAP_PROP_GAIN           // 增益（仅适用于摄像头）

CV_CAP_PROP_EXPOSURE       // 曝光（仅适用于摄像头）

CV_CAP_PROP_CONVERT_RGB    // 是否将图像转换为RGB

CV_CAP_PROP_WHITE_BALANCE  // 白平衡

CV_CAP_PROP_RECTIFICATION  // 立体摄像机的整流标志

## 三、视频读取与处理
3.1 视频读取 

// 从摄像头读取

VideoCapture cap(0);  // 0表示默认摄像头

:::info
// 从视频文件读取

VideoCapture cap("video.mp4");

if (!cap.isOpened()) {

    cout << "无法打开摄像头" << endl;

    return -1;}

Mat frame;       //创建一个就行，可共享

while (true) {

    cap >> frame; //读取一帧   

    if (frame.empty()) {break;//视频结束}    

    imshow("Camera", frame);

    if (waitKey(1) == 27) { //1ms延迟，ESC键退出

        break;}}

:::

3.2 实时处理

VideoCapture cap(0);

if (!cap.isOpened()){return -1;}

Mat frame, gray_frame, blurred_frame;

while (true) {

    cap >> frame;

    if (frame.empty()){break;}

    

// 高斯滤波

GaussianBlur(frame,blurred_frame, Size(15, 15),0);





:::info
**视频保存**

VideoWriter writer(result.avi",VideoWriter::fourcc('M','J','P','G'),fps,Size(width,height));

**      ** writer.write(frame)    		       <font style="color:#2F4BDA;background-color:#FFFFFF;">编码格式↑               ↑帧率</font>



绘制文本

putText(frame, color, Point(20,40), FONT_HERSHEY_SIMPLEX, 1, Scalar(255,255,255), 2);

**     **                    <font style="color:#2F4BDA;">↑文本string   文本位置			字体类型                           大小              颜色                  粗细</font>

:::

## 四、基础图像处理 
4.1 色彩空间转换 

Mat bgr, gray, hsv, lab;

BGR(伊始读取的格式)转HSV(<font style="color:rgb(15, 17, 21);background-color:rgb(237, 243, 254);">适合颜色检测</font>)

:::info
cvtColor(bgr,~~hsv~~,COLOR_BGR2~~HSV~~);

:::

转LAB/灰度:在~~hsv~~处替换

4.2 滤波算法 Mat src, dst;

// 高斯滤波

GaussianBlur(src, dst, Size(5, 5), 0);

// 中值滤波

medianBlur(src, dst, 5);

// 均值滤波

blur(src, dst, Size(5, 5));

// 双边滤波

bilateralFilter(src, dst, 9, 75, 75); 

4.3 形态学操作 

Mat src_binary, dst_morph;

// 创建结构元素

Mat kernel= 

getStructuringElement(MORPH_RECT, Size(5, 5));

// 腐蚀

erode(src_binary, dst_morph, kernel);

// 膨胀

dilate(src_binary, dst_morph, kernel);

// 开运算(先腐蚀后膨胀)

morphologyEx(src_binary, dst_morph, MORPH_OPEN, kernel);

// 闭运算(先膨胀后腐蚀)

morphologyEx(src_binary, dst_morph, MORPH_CLOSE, kernel);  

## 五、几何变换 
  5.1 图像裁剪与缩放 Mat src, dst;

// 图像裁剪 Rect(x, y, width, height)

Mat cropped = src(Rect(100, 100, 200, 200));

// 图像缩放

resize(src, dst, Size(new_width, new_height));  

// 指定尺寸

resize(src, dst, Size(), 0.5, 0.5);  //按比例缩放

5.2 图形和文字绘制 

Mat img = Mat::zeros(500, 500, CV_8UC3);

// 绘制line/rectangle/circle,尾参数负值表示填充

~~line~~(img,Point(1,1 ),Point(2, 2),Scalar(,,), ~~2~~);			

:::info
putText(img, "Hello OpenCV", Point(100, 400),

FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 255, 255), 2);  			// 绘制文字 

:::

        

5.3 仿射变换 

Mat src, dst;

// 定义三个点进行仿射变换

Point2f srcTri[3];

Point2f dstTri[3];

srcTri[0] = Point2f(0, 0);

srcTri[1] = Point2f(src.cols - 1, 0);

srcTri[2] = Point2f(0, src.rows - 1);

dstTri[0] = Point2f(0, src.rows * 0.33);

dstTri[1] = Point2f(src.cols * 0.85, src.rows * 0.25);

dstTri[2] = Point2f(src.cols * 0.15, src.rows * 0.7);

Mat warp_mat = getAffineTransform(srcTri, dstTri);

warpAffine(src, dst, warp_mat, dst.size());  

5.4 透射变换  

Mat src, dst;

// 定义四个点进行透射变换

Point2f srcQuad[4], dstQuad[4];

srcQuad[0] = Point2f(0, 0);

srcQuad[1] = Point2f(src.cols - 1, 0);

srcQuad[2] = Point2f(src.cols - 1, src.rows - 1);

srcQuad[3] = Point2f(0, src.rows - 1);

dstQuad[0] = Point2f(0, src.rows * 0.1);

dstQuad[1] = Point2f(src.cols * 0.9, 0);

dstQuad[2] = Point2f(src.cols * 0.8, src.rows * 0.9);

dstQuad[3] = Point2f(src.cols * 0.1, src.rows * 0.8);

Mat warp_mat = getPerspectiveTransform(srcQuad, dstQuad);

warpPerspective(src, dst, warp_mat, dst.size());  

## 六、颜色提取与图形提取
:::info
6.1 颜色提取 

Mat src, hsv, mask, result;

// 转换到HSV色彩空间

cvtColor(src, hsv, COLOR_BGR2HSV);

// 创建掩码一般是红色紫色青色

Mat red1,red2;

inRange(hsv,Scalar(0,70,50), Scalar(10,255, 255),red1);       ↑red1下限                ↑red1上限

inRange(hsv,,Scalar(,,), Scalar(,,),red2);

Mat red = red1 | red2;

// 应用掩码

bitwise_and(src, src, result, mask);  

:::



:::info
6.2 图形提取 

Mat src_gray, red_0, contours_img;

// 转换为灰度图并二值化

cvtColor(src, src_gray, COLOR_BGR2GRAY);

threshold(src_gray, binary, 127, 255, THRESH_BINARY);

// 查找轮廓

vector<vector<Point>>red_contours;//声明

~~vector<Vec4i> hierarchy;//存储轮廓层级关系~~

findContours(red_0,red_contours~~,hierarchy~~, RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);

// 绘制轮廓

contours_img = Mat::zeros(src.size(), CV_8UC3);

                          ↓检测到的?色区域数量

for (size_t i = 0; i < contours.size(); i++) {

    drawContours(contours_img, contours, i, Scalar(0, 255, 0), 2);}

// 轮廓分析

for (size_t i = 0; i < contours.size(); i++) {

    double area = contourArea(contours[i]);<font style="color:#74B602;">//计算当前轮廓面积</font>

    Rect rect = boundingRect(contours[i]);<font style="color:#74B602;">记录边界矩形</font>

    if (area > 1000) { <font style="color:#74B602;"> //过滤小轮廓</font>

        rectangle(src, rect, Scalar(255, 0, 0), 2);}}

:::



