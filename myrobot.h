#ifndef MYROBOT_H
#define MYROBOT_H

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>
#include <QTimer>
#include <QMutex>
#include "command.h"
#include <stack>
#include <queue>


class MyRobot : public QObject {
    Q_OBJECT
public:
    explicit MyRobot(QObject *parent = 0);
    void doConnect();
    void disConnect();
    void turn_left();
    void turn_right();


    void update(short gspeed, short dspeed, float godometry, float dodometry);

    void rect();


    QByteArray DataToSend;
    QByteArray DataReceived;
    QMutex Mutex;

signals:
    void updateUI(const QByteArray Data);
public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();
    void MyTimerSlot();
    short Crc16(QByteArray Adresse_tab,unsigned int Taille_max);

private:
    QTcpSocket *socket;
    QTimer *TimerEnvoi;

    std::queue<Command> commands;
};

#endif // MYROBOT_H
