#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , robot(parent)
{
    ui->setupUi(this);
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

