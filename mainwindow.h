#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "myrobot.h"
#include <QMainWindow>

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
    void on_connection_clicked();

    void on_disconnect_clicked();

    void on_r_top_pressed();

    void on_r_left_pressed();

    void on_r_buttom_pressed();

    void on_r_right_pressed();

private:
    Ui::MainWindow *ui;
    MyRobot robot;
};
#endif // MAINWINDOW_H
