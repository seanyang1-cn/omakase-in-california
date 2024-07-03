#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ui_mainwindow.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void processImage(const cv::Mat &inputImage, cv::Mat &outputImage);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_loadImage_clicked();

private:
    Ui::MainWindow *ui;
    void progressbarInit();
};
#endif // MAINWINDOW_H
