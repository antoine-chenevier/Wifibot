#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "myrobot.h"
#include <QMainWindow>
#include <qnetworkaccessmanager.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_r_top_pressed();

    void on_r_left_pressed();

    void on_r_buttom_pressed();

    void on_r_right_pressed();

    void on_robot_right_pressed();

    void on_robot_right_released();

    void on_robot_left_pressed();

    void on_robot_top_pressed();

    void on_robot_left_released();

    void on_robot_top_released();

    void on_robot_bottom_pressed();

    void on_robot_bottom_released();

    void on_toggleConnect_clicked();

    void on_update(const QByteArray);

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    MyRobot robot;
    QNetworkAccessManager *manager;
    QNetworkRequest request;
    bool connected;
    int speed;
};
#endif // MAINWINDOW_H
