#include "widget.h"
#include "ui_widget.h"

void Widget::onConnected()
{ //connected()信号槽函数
    ui->action_mainText->appendPlainText("**已连接到服务器");
}

void Widget::onDisconnected()
{//disConnected()信号槽函数
    ui->action_mainText->appendPlainText("**已断开与服务器的连接");
}

void Widget::onSocketReadyRead()
{//readyRead()信号槽函数
        QString msg_rec = tcpClient->readLine();
        ui->action_mainText->appendPlainText("[in] "+msg_rec);
        //***************************************
        data_manager(msg_rec);
        //****************************************
}

void Widget::onSocketStateChange(QAbstractSocket::SocketState socketState)
{//stateChange()信号槽函数
    switch(socketState)
    {
    case QAbstractSocket::UnconnectedState:
        ui->action_mainText->appendPlainText("scoket状态：UnconnectedState");
        break;
    case QAbstractSocket::HostLookupState:
        ui->action_mainText->appendPlainText("scoket状态：HostLookupState");
        break;
    case QAbstractSocket::ConnectingState:
        ui->action_mainText->appendPlainText("scoket状态：ConnectingState");
        break;
    case QAbstractSocket::ConnectedState:
        ui->action_mainText->appendPlainText("scoket状态：ConnectedState");
        break;
    case QAbstractSocket::BoundState:
        ui->action_mainText->appendPlainText("scoket状态：BoundState");
        break;
    case QAbstractSocket::ClosingState:
        ui->action_mainText->appendPlainText("scoket状态：ClosingState");
        break;
    case QAbstractSocket::ListeningState:
        ui->action_mainText->appendPlainText("scoket状态：ListeningState");
    }
}

void Widget::printSocketStatus()
{
    if (tcpClient->state() == QAbstractSocket::UnconnectedState)
    {ui->action_mainText->appendPlainText("scoket状态：UnconnectedState");}
    if (tcpClient->state() == QAbstractSocket::HostLookupState)
    {ui->action_mainText->appendPlainText("scoket状态：HostLookupState");}
    if (tcpClient->state() == QAbstractSocket::ConnectingState)
    {ui->action_mainText->appendPlainText("scoket状态：ConnectingState");}
    if (tcpClient->state() == QAbstractSocket::ConnectedState)
    {ui->action_mainText->appendPlainText("scoket状态：ConnectedState");}
    if (tcpClient->state() == QAbstractSocket::BoundState)
    {ui->action_mainText->appendPlainText("scoket状态：BoundState");}
    if (tcpClient->state() == QAbstractSocket::ClosingState)
    {ui->action_mainText->appendPlainText("scoket状态：ClosingState");}
    if (tcpClient->state() == QAbstractSocket::ListeningState)
    {ui->action_mainText->appendPlainText("scoket状态：ListeningState");}
}
