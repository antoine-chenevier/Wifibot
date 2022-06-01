#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QWebEngineView>
#include <QUrl>
#include <QNetworkReply>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , robot(parent)
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
    delete ui;
    delete manager;
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

void MainWindow::on_robot_buttom_pressed()
{

}


void MainWindow::on_robot_left_pressed()
{

}


void MainWindow::on_robot_top_pressed()
{

}

void MainWindow::on_robot_right_released()
{

}

void MainWindow::on_robot_buttom_released()
{

}


void MainWindow::on_robot_left_released()
{

}


void MainWindow::on_robot_top_released()
{

}

