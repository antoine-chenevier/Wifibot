#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QWebEngineView>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , robot(parent)
{
    ui->setupUi(this);
    QWebEngineView* view = this->findChild<QWebEngineView*>("view");
    view->load(QUrl("http://192.168.1.106:8080/?action=stream"));
    view->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_connection_clicked()
{
    //ui->connection->
    robot.doConnect();
}


void MainWindow::on_disconnect_clicked()
{
    robot.disConnect();
}


void MainWindow::on_r_top_pressed()
{


}


void MainWindow::on_r_left_pressed()
{

}


void MainWindow::on_r_buttom_pressed()
{

}


void MainWindow::on_r_right_pressed()
{

}

