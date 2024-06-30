#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace cv;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Mat image = imread("C:\\Users\\69441\\Pictures\\lesserafim wallpaper\\8625871.jpg", 1);
    namedWindow( "Display window", WINDOW_AUTOSIZE );
    imshow( "Display window", image );
}

void MainWindow::processImage(const cv::Mat &inputImage, cv::Mat &outputImage)
{
    // 检查输入图像是否为空
    if (inputImage.empty()) {
        qDebug() << "Error: Input image is empty!";
        return;
    }

    // 创建一个与输入图像大小相同的输出图像
    outputImage = inputImage.clone();

    // 遍历每个像素
    for (int y = 0; y < inputImage.rows; ++y) {
        for (int x = 0; x < inputImage.cols; ++x) {
            // 获取像素的RGB信息
            cv::Vec3b pixel = inputImage.at<cv::Vec3b>(y, x);

            // 自定义处理函数示例：简单的反转颜色
            pixel[0] = 255 - pixel[0]; // 处理蓝色通道
            pixel[1] = 255 - pixel[1]; // 处理绿色通道
            pixel[2] = 255 - pixel[2]; // 处理红色通道

            // 将处理后的像素值赋给输出图像
            outputImage.at<cv::Vec3b>(y, x) = pixel;
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    // 读取图像
    cv::Mat inputImage = cv::imread("C:\\Users\\69441\\Pictures\\lesserafim wallpaper\\8625871.jpg");

    if (inputImage.empty()) {
        qDebug() << "Error: Unable to read input image!";
        return;
    }

    // 处理图像
    cv::Mat processedImage;
    processImage(inputImage, processedImage);

    // 将OpenCV的Mat转换为QImage以便在Qt中显示
    QImage qImage(processedImage.data, processedImage.cols, processedImage.rows,
                  processedImage.step, QImage::Format_RGB888);

    // 显示处理后的图像在label中（假设有一个QLabel叫做imageLabel）
    ui->imageLabel->setPixmap(QPixmap::fromImage(qImage));
    ui->imageLabel->setScaledContents(true); // 图像自适应大小显示
}

