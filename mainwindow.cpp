#include <iostream>
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
    ,speed(120)
    ,MaxSpeed(0)
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

    connect(&robot, &MyRobot::updateUI, this, &MainWindow::on_update);

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
    int s1=speed/128;
    int s2=speed%128;
    robot.DataToSend[2] = speed;
    robot.DataToSend[3] = MaxSpeed;
    robot.DataToSend[4] = speed;
    robot.DataToSend[5] = MaxSpeed;
    robot.DataToSend[6] = 64; // ajouter 128+32 pour asservissement
    short crc = robot.Crc16(robot.DataToSend, 7);

    char low = crc;
    char high = crc >> 8;
    robot.DataToSend[7] = low;
    robot.DataToSend[8] = high;
}


void MainWindow::on_robot_left_pressed()
{
     robot.DataToSend[2] = speed;
     robot.DataToSend[3] = MaxSpeed;
     robot.DataToSend[4] = speed;
     robot.DataToSend[5] = MaxSpeed;
     robot.DataToSend[6] = 16; // ajouter 128+32 pour asservissement
     short crc = robot.Crc16(robot.DataToSend, 7);

     char low = crc;
     char high = crc >> 8;
     robot.DataToSend[7] = low;
     robot.DataToSend[8] = high;

}


void MainWindow::on_robot_top_pressed()
{
    robot.DataToSend[2] = speed;
    robot.DataToSend[3] = MaxSpeed;
    robot.DataToSend[4] = speed;
    robot.DataToSend[5] = MaxSpeed;
    robot.DataToSend[6] = 64 + 16; // ajouter 128+32 pour asservissement
    short crc = robot.Crc16(robot.DataToSend, 7);

    char low = crc;
    char high = crc >> 8;
    robot.DataToSend[7] = low;
    robot.DataToSend[8] = high;


}

void MainWindow::on_robot_bottom_pressed()
{
    robot.DataToSend[2] = speed;
    robot.DataToSend[3] = MaxSpeed;
    robot.DataToSend[4] = speed;
    robot.DataToSend[5] = MaxSpeed;
    robot.DataToSend[6] = 0+0; // ajouter 128+32 pour asservissement
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


void MainWindow::on_robot_top_released()
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





void MainWindow::on_robot_bottom_released()
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

void MainWindow::turn_left(){
    robot.DataToSend[2] = 0;
    robot.DataToSend[3] = 0;
    robot.DataToSend[4] = speed;
    robot.DataToSend[5] = speed;
    robot.DataToSend[6] = 16;
    short crc = robot.Crc16(robot.DataToSend, 7);

    char low = crc;
    char high = crc >> 8;
    robot.DataToSend[7] = low;
    robot.DataToSend[8] = high;
}
void MainWindow::turn_right(){
    robot.DataToSend[2] = speed;
    robot.DataToSend[3] = speed;
    robot.DataToSend[4] = 0;
    robot.DataToSend[5] = 0;
    robot.DataToSend[6] = 64;
    short crc = robot.Crc16(robot.DataToSend, 7);

    char low = crc;
    char high = crc >> 8;
    robot.DataToSend[7] = low;
    robot.DataToSend[8] = high;
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



void MainWindow::on_update(const QByteArray Data) {

    int speed = (int) (Data[0] + (Data[1] << 8));




    float odometrie_g = (float) (((long) Data[8] << 24) + ((long) Data[7] << 16) + ((long) Data[6] << 8) + ((long) Data[5]));
    float odometrie_l = (float) (((long) Data[16] << 24) + ((long) Data[15] << 16) + ((long) Data[14] << 8) + ((long) Data[14]));
    std::cout << speed << std::endl;
    std::cout << "odométrie: " << std::endl << odometrie_g << std::endl << odometrie_l << std::endl;
    std::cout << " received" << std::endl;


    short crc = robot.Crc16(Data, 19);
    short received_crc = (short) (Data[19] + (Data[20] << 8));


    if (crc == received_crc) {
        std::cout << "valid crc" << std::endl;
    } else {
        std::cout << "invalid crc" << std::endl;
    }

    unsigned char batterie = Data[2];
    QProgressBar* batterie_bar = findChild<QProgressBar*>("batterie");
    if (batterie > 125) {
        //batterie_bar->setValue(100);
    } else {
        batterie_bar->setValue(batterie * 100 / 128);
    }


    //robot.update()
}


void MainWindow::on_MaxSpeed_clicked(bool checked)
{
    if(checked==true){
        MaxSpeed=1;
    }
    else{
        MaxSpeed=0;
    }
}

