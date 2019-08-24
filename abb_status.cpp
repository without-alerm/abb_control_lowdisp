#include "widget.h"
#include "ui_widget.h"

void Widget::on_but_read_cur_joint_clicked()
{
    QString tar_pos_mark = "11";
    ui->action_mainText->appendPlainText("获取当前关节角");
    msg_send = tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark;
    ui->action_mainText->appendPlainText(msg_send);
    QByteArray char_msg_send = msg_send.toUtf8();
    tcpClient->write(char_msg_send);
    //接收

    //分解

    //显示
}

void Widget::on_but_set_tar_joint_clicked()
{
    QString tar_joint_1 = ui->tar_joint_1->text();
    QString tar_joint_2 = ui->tar_joint_2->text();
    QString tar_joint_3 = ui->tar_joint_3->text();
    QString tar_joint_4 = ui->tar_joint_4->text();
    QString tar_joint_5 = ui->tar_joint_5->text();
    QString tar_joint_6 = ui->tar_joint_6->text();

    QString tar_pos_mark = "12";

    ui->action_mainText->appendPlainText("单点位置控制");
    msg_send = tar_pos_mark+","+tar_joint_1+","+tar_joint_2+","+tar_joint_3+","+tar_joint_4+","+tar_joint_5+","+tar_joint_6+","+tar_pos_mark;
    ui->action_mainText->appendPlainText(msg_send);
    QByteArray char_msg_send = msg_send.toUtf8();
    tcpClient->write(char_msg_send);
}

void Widget::on_but_read_cur_pos_clicked()
{
    QString tar_pos_mark = "13";
    ui->action_mainText->appendPlainText("获取当前位置");
    msg_send = tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark+","+tar_pos_mark;
    ui->action_mainText->appendPlainText(msg_send);
    QByteArray char_msg_send = msg_send.toUtf8();
    tcpClient->write(char_msg_send);
}

void Widget::on_but_set_target_pos_clicked()
{
    QString tar_pos_x = ui->tar_pos_x->text();
    QString tar_pos_y = ui->tar_pos_y->text();
    QString tar_pos_z = ui->tar_pos_z->text();
    QString tar_pos_rx = ui->tar_pos_rx->text();
    QString tar_pos_ry = ui->tar_pos_ry->text();
    QString tar_pos_rz = ui->tar_pos_rz->text();

    QString tar_pos_mark = "14";

    ui->action_mainText->appendPlainText("单点位置控制");
    msg_send = tar_pos_mark+","+tar_pos_x+","+tar_pos_y+","+tar_pos_z+","+tar_pos_rx+","+tar_pos_ry+","+tar_pos_rz+","+tar_pos_mark;
    ui->action_mainText->appendPlainText(msg_send);
    QByteArray char_msg_send = msg_send.toUtf8();
    tcpClient->write(char_msg_send);
}
