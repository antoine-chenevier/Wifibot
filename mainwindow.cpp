#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QWebEngineView>
#include <QUrl>
#include <QNetworkReply>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , robot(parent)
    , connected(false)
{
    ui->setupUi(this);
    QWebEngineView* view = this->findChild<QWebEngineView*>("view");
    view->load(QUrl("http://192.168.1.106:8080/?action=stream"));
    view->show();

    manager = new QNetworkAccessManager();
    QObject::connect(manager, &QNetworkAccessManager::finished,
          this, [=](QNetworkReply *reply) {
              if (reply->error()) {
                  qDebug() << reply->errorString();
                  return;
              }
              QString answer = reply->readAll();

              qDebug() << answer;
    });

}

MainWindow::~MainWindow()
{
    if (connected) {
        robot.disconnect();
    }
    delete ui;
    delete manager;
}


void MainWindow::on_r_top_pressed()
{
    request.setUrl(QUrl("http://192.168.1.106:8080/?action=command&dest=0&plugin=0&id=10094853&group=1&value=-200"));
        manager->get(request);

}


void MainWindow::on_r_left_pressed()
{
    request.setUrl(QUrl("http://192.168.1.106:8080/?action=command&dest=0&plugin=0&id=10094852&group=1&value=200"));
            manager->get(request);
}


void MainWindow::on_r_buttom_pressed()
{
    request.setUrl(QUrl("http://192.168.1.106:8080/?action=command&dest=0&plugin=0&id=10094853&group=1&value=200"));
        manager->get(request);

}


void MainWindow::on_r_right_pressed()
{
    request.setUrl(QUrl("http://192.168.1.106:8080/?action=command&dest=0&plugin=0&id=10094852&group=1&value=-200"));
            manager->get(request);
}


void MainWindow::on_robot_right_pressed()
{

}


void MainWindow::on_robot_left_pressed()
{

}


void MainWindow::on_robot_top_pressed()
{
    robot.DataToSend[2] =100;
    robot.DataToSend[3] = 0;
    robot.DataToSend[4] =100;
    robot.DataToSend[5] = 0;
    robot.DataToSend[6] = 64 + 16; // ajouter 128+32 pour asservissement
    short crc = robot.Crc16(robot.DataToSend, 7);

    char low = crc;
    char high = crc >> 8;
    robot.DataToSend[7] = low;
    robot.DataToSend[8] = high;


}

void MainWindow::on_robot_right_released()
{
    robot.DataToSend[2] = 0;
    robot.DataToSend[3] = 0;
    robot.DataToSend[4] = 0;
    robot.DataToSend[5] = 0;
    robot.DataToSend[6] = 0;
    short crc = robot.Crc16(robot.DataToSend, 7);

    char low = crc;
    char high = crc >> 8;
    robot.DataToSend[7] = low;
    robot.DataToSend[8] = high;
}


void MainWindow::on_robot_left_released()
{

}


void MainWindow::on_robot_top_released()
{
    robot.DataToSend[3] =0;
    robot.DataToSend[5] =0;
}


void MainWindow::on_robot_bottom_pressed()
{

}


void MainWindow::on_robot_bottom_released()
{

}


void MainWindow::on_toggleConnect_clicked()
{
       QPushButton *toggle = findChild<QPushButton*>("toggleConnect");
       QPushButton *top = findChild<QPushButton*>("robot_top");
       QPushButton *left = findChild<QPushButton*>("robot_left");
       QPushButton *right = findChild<QPushButton*>("robot_right");
       QPushButton *bottom = findChild<QPushButton*>("robot_bottom");

       if (connected) {
           robot.disConnect();
           connected = false;

           toggle->setText("Connect");
           top->setDisabled(true);
           left->setDisabled(true);
           right->setDisabled(true);
           bottom->setDisabled(true);
       } else {
           robot.doConnect();
           connected = true;

           toggle->setText("Disconnect");
           top->setDisabled(false);
           left->setDisabled(false);
           right->setDisabled(false);
           bottom->setDisabled(false);
       }
}

