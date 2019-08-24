#include "widget.h"
#include "ui_widget.h"

void Widget::on_but_agv_connect_clicked()
{

    Widget::broadcast("on_but_agv_connect_clicked");
}

void Widget::on_but_abb_dicconnect_clicked()
{
    if (tcpClient->state()==QAbstractSocket::ConnectedState)
        tcpClient->disconnectFromHost();
    Widget::broadcast("disconnected");

}

void Widget::on_but_abb_detect_clicked()
{
    Widget::printSocketStatus();
}

void Widget::on_but_abb_connect_clicked()
{
    QString IP = ui->abbIP->text();
    tcpClient->connectToHost(IP,8885);
    Widget::broadcast("try to connect "+ IP +" , default port 8885");
}

void Widget::on_but_stop_clicked()
{
    QString tar_pos_mark = "0";
    Widget::broadcast("急停");
    msg_send = tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark;
    Widget::broadcast(msg_send);
    QByteArray char_msg_send = msg_send.toUtf8();
    tcpClient->write(char_msg_send);
}

void Widget::on_but_act_clicked()
{
    QString tar_pos_mark = "6";
    Widget::broadcast("开始加工");
    msg_send = tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark;
    Widget::broadcast(msg_send);
    QByteArray char_msg_send = msg_send.toUtf8();
    tcpClient->write(char_msg_send);
}

void Widget::on_but_pause_clicked()
{
    QString tar_pos_mark = "7";
    Widget::broadcast("暂停加工");
    msg_send = tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark;
    Widget::broadcast(msg_send);
    QByteArray char_msg_send = msg_send.toUtf8();
    tcpClient->write(char_msg_send);
}

void Widget::on_but_reset_clicked()
{
    QString tar_pos_mark = "8";
    Widget::broadcast("复位");
    msg_send = tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark;
    Widget::broadcast(msg_send);
    QByteArray char_msg_send = msg_send.toUtf8();
    tcpClient->write(char_msg_send);
}

void Widget::on_but_save_clicked()
{
    QString tar_pos_mark = "9";
    Widget::broadcast("保存加工数据");
    msg_send = tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark;
    Widget::broadcast(msg_send);
    QByteArray char_msg_send = msg_send.toUtf8();
    tcpClient->write(char_msg_send);
}
