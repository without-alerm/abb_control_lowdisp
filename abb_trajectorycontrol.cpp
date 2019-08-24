#include "widget.h"
#include "ui_widget.h"


void Widget::on_but_abb_dataInput_clicked()
{
    //double accData[3][8] = {{1, 683.16390, 144.374527, 438.939941, 0.800966, -0.385800, 0.198675, 0.412481},
    //                        {0, 607.176650, 208.147607, 438.939941, 0.715564, -0.646440, 0.177466, 0.196441},
    //                        {1, 535.31572, 243.154702, 438.939941, 0.647803, -0.737148, 0.144420, 0.126916}};

    ui->action_mainText->appendPlainText("loading data");
    //tar_mark,0 represents end; 1 for movej;  2 for movel;  3 for movec;
    tar_mark = {1,1,1,1,1,1,1,1,1,1};
    //tar_x = {683.16,670.57,656.41,640.6,624.29,607.18,589.76,571.81,553.66,535.32};
    tar_x = {883.16,870.57,856.41,840.6,824.29,807.18,789.76,771.81,753.66,735.32};
    tar_y = {144.37,159.9,173.98,186.24,197.8,208.15,217.96,226.78,235.2,243.15};
    tar_z = {438.94,438.94,438.94,438.94,438.94,438.94,438.94,438.94,438.94,438.94};
    tar_b = {1,1,1,1,1,1,1,1,1,1};
    tar_a = {0,0,0,0,0,0,0,0,0,0};
    tar_c = {0,0,0,0,0,0,0,0,0,0};
    tar_d = {0,0,0,0,0,0,0,0,0,0};

    //tar_a = {0.801,0.799,0.767,0.764,0.734,0.716,0.685,0.673,0.668,0.648};
    //tar_b = {-0.386,-0.436,-0.553,-0.557,-0.618,-0.646,-0.691,-0.706,-0.712,-0.737};
    //tar_c = {0.199,0.198,0.19,0.192,0.182,0.177,0.164,0.16,0.158,0.144};
    //tar_d = {0.412,0.363,0.264,0.263,0.216,0.196,0.163,0.152,0.149,0.127};
    ui->action_mainText->appendPlainText("data loaded");

    //int length_tar = tar_mark.count();
    //int response = 0;
    int cur_count  = 0;

    while (cur_count<10)
    {

        QString data1= QString::number(tar_mark[cur_count]);
        QString data2= QString::number(tar_x[cur_count]);
        QString data3= QString::number(tar_y[cur_count]);
        QString data4= QString::number(tar_z[cur_count]);
        QString data5= QString::number(tar_a[cur_count]);
        QString data6= QString::number(tar_b[cur_count]);
        QString data7= QString::number(tar_c[cur_count]);
        QString data8= QString::number(tar_d[cur_count]);
        this->repaint();
        msg_send = data1 + "," + data2 + "," + data3 + "," + data4 + "," + data5 + "," + data6 + "," + data7 + "," + data8;
        /**
        msg_send = QString::number(tar_mark[cur_count],2) + "," +
                QString::number(tar_x[cur_count],'f',3) + "," +
                QString::number(tar_y[cur_count],'f',3) + "," +
                QString::number(tar_z[cur_count],'f',3) + "," +
                QString::number(tar_a[cur_count],'f',3) + "," +
                QString::number(tar_b[cur_count],'f',3) + "," +
                QString::number(tar_c[cur_count],'f',3) + "," +
                QString::number(tar_d[cur_count],'f',3);
                **/
        ui->action_mainText->appendPlainText(msg_send);
        QByteArray char_msg_send = msg_send.toUtf8();
        tcpClient->write(char_msg_send);
        cur_count++;
        Widget::Sleep(200);

    }

}

