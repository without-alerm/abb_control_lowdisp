#include "widget.h"
#include "ui_widget.h"

void Widget::onConnected()
{ //connected()信号槽函数
    Widget::broadcast("**已连接到服务器");
}

void Widget::onDisconnected()
{//disConnected()信号槽函数
    Widget::broadcast("**已断开与服务器的连接");
}

void Widget::onSocketReadyRead()
{//readyRead()信号槽函数
        QString msg_rec = tcpClient->readLine();
        Widget::broadcast("[in] "+msg_rec);
        //***************************************
        data_manager(msg_rec);
        //****************************************
}

void Widget::onSocketStateChange(QAbstractSocket::SocketState socketState)
{//stateChange()信号槽函数
    switch(socketState)
    {
    case QAbstractSocket::UnconnectedState:
        Widget::broadcast("scoket状态：UnconnectedState");
        break;
    case QAbstractSocket::HostLookupState:
        Widget::broadcast("scoket状态：HostLookupState");
        break;
    case QAbstractSocket::ConnectingState:
        Widget::broadcast("scoket状态：ConnectingState");
        break;
    case QAbstractSocket::ConnectedState:
        Widget::broadcast("scoket状态：ConnectedState");
        break;
    case QAbstractSocket::BoundState:
        Widget::broadcast("scoket状态：BoundState");
        break;
    case QAbstractSocket::ClosingState:
        Widget::broadcast("scoket状态：ClosingState");
        break;
    case QAbstractSocket::ListeningState:
        Widget::broadcast("scoket状态：ListeningState");
    }
}

void Widget::printSocketStatus()
{
    if (tcpClient->state() == QAbstractSocket::UnconnectedState)
    {Widget::broadcast("scoket状态：UnconnectedState");}
    if (tcpClient->state() == QAbstractSocket::HostLookupState)
    {Widget::broadcast("scoket状态：HostLookupState");}
    if (tcpClient->state() == QAbstractSocket::ConnectingState)
    {Widget::broadcast("scoket状态：ConnectingState");}
    if (tcpClient->state() == QAbstractSocket::ConnectedState)
    {Widget::broadcast("scoket状态：ConnectedState");}
    if (tcpClient->state() == QAbstractSocket::BoundState)
    {Widget::broadcast("scoket状态：BoundState");}
    if (tcpClient->state() == QAbstractSocket::ClosingState)
    {Widget::broadcast("scoket状态：ClosingState");}
    if (tcpClient->state() == QAbstractSocket::ListeningState)
    {Widget::broadcast("scoket状态：ListeningState");}
}
