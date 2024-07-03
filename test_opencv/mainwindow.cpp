#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace cv;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    progressbarInit();
    // Mat image = imread("C:\\Users\\69441\\Pictures\\lesserafim wallpaper\\8625871.jpg", 1);
    // namedWindow( "Display window", WINDOW_AUTOSIZE );
    // imshow( "Display window", image );
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
    progressbarInit();
    // // 读取图像
    // cv::Mat inputImage = cv::imread("C:\\Users\\69441\\Pictures\\lesserafim wallpaper\\8625871.jpg");

    // if (inputImage.empty()) {
    //     qDebug() << "Error: Unable to read input image!";
    //     return;
    // }

    // // 处理图像
    // cv::Mat processedImage;
    // processImage(inputImage, processedImage);

    // // 将OpenCV的Mat转换为QImage以便在Qt中显示
    // QImage qImage(processedImage.data, processedImage.cols, processedImage.rows,
    //               processedImage.step, QImage::Format_RGB888);

    // // 显示处理后的图像在label中（假设有一个QLabel叫做imageLabel）
    // ui->imageLabel->setPixmap(QPixmap::fromImage(qImage));
    // ui->imageLabel->setScaledContents(true); // 图像自适应大小显示



    // 打开视频文件
    VideoCapture video("C:\\Users\\69441\\Downloads\\big-buck-bunny_trailer.mp4");
    if (!video.isOpened())
    {
        qDebug() << "Error: Cannot open video file.";
        return;
    }

    // 获取视频的帧率、宽度和高度
    double frameCount = video.get(CAP_PROP_FRAME_COUNT);
    double fps = video.get(CAP_PROP_FPS);
    int width = video.get(CAP_PROP_FRAME_WIDTH);
    int height = video.get(CAP_PROP_FRAME_HEIGHT);
    qDebug() << width;

    // 创建VideoWriter对象，用于保存处理后的视频
    // VideoWriter writer("output_video.mp4", VideoWriter::fourcc('M','J','P','G'), fps, Size(width, height));
    // VideoWriter writer("output_video.mp4", VideoWriter::fourcc('X','V','I','D'), fps, Size(width, height));
    VideoWriter writer("output_video.mp4", VideoWriter::fourcc('H','2','6','4'), fps, Size(width, height));

    // 处理视频的每一帧
    Mat frame;
    while (video.read(frame))
    {
        static int count = 0;
        // 在这里对frame进行图像处理，例如灰度化
        cvtColor(frame, frame, COLOR_BGR2GRAY);

        // 将处理后的帧写入VideoWriter对象
        writer.write(frame);
        qDebug() << count;
        count++;
        ui->progressBar->setValue((int)(count * 100 / frameCount));

    }

    // 释放VideoCapture和VideoWriter对象
    video.release();
    writer.release();
    qDebug() << "complete";
    return;

}

void MainWindow::progressbarInit()
{
    ui->progressBar->setValue(0);
}


void MainWindow::on_pushButton_loadImage_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));
    std::string filePath_std = filePath.toStdString();
    cv::Mat image = cv::imread(filePath_std, cv::IMREAD_COLOR);
    if (image.empty())
    {
        qDebug() << "Could not open or find the image";
        return;
    }
    qDebug() << "Image loaded: " << image.cols << " x " << image.rows;
    QImage qimg(image.data, image.cols, image.rows, image.step, QImage::Format_RGB888);
    qimg = qimg.rgbSwapped(); // OpenCV uses BGR, QImage uses RGB
    ui->imageLabel_before->setPixmap(QPixmap::fromImage(qimg).scaled(ui->imageLabel_before->size(), Qt::KeepAspectRatio));

    // QImage读取
    // if (!filePath.isEmpty())
    // {
    //     qDebug() << "filePath = "<<filePath;
    //     QImage image(filePath);
    //     if (image.isNull())
    //     {
    //         qDebug() << "Could not open or find the image";
    //         return;
    //     }

    //     ui->imageLabel_before->setPixmap(QPixmap::fromImage(image).scaled(ui->imageLabel_before->size(), Qt::KeepAspectRatio));
    // }
    // else{
    //     qDebug() << "filePath error";
    // }


}

