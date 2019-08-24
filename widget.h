#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QByteArray>
#include <QTime>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void printSocketStatus();
    double abbData[3][8];
    void data_manager(QString);
    void Sleep(int msec);

private slots:
    void on_but_abb_dataInput_clicked();
    void on_but_agv_connect_clicked();
    void    onConnected();
    void    onDisconnected();
    void    onSocketStateChange(QAbstractSocket::SocketState socketState);
    void    onSocketReadyRead();//读取socket传入的数据
//
    void on_but_abb_dicconnect_clicked();

    void on_but_abb_detect_clicked();

    void on_but_abb_connect_clicked();

    void on_but_set_target_pos_clicked();

    void on_but_read_cur_pos_clicked();

    void on_tic_clicked();

    void on_but_read_cur_joint_clicked();

    void on_but_set_tar_joint_clicked();

    void on_but_stop_clicked();

    void on_but_act_clicked();

    void on_but_pause_clicked();

    void on_but_reset_clicked();

    void on_but_save_clicked();


private:
    Ui::Widget *ui;

    QVector<int> tar_mark;
    QVector<double> tar_x;
    QVector<double> tar_y;
    QVector<double> tar_z;
    QVector<double> tar_a;
    QVector<double> tar_b;
    QVector<double> tar_c;
    QVector<double> tar_d;

    double cur_x;
    double cur_y;
    double cur_z;
    double cur_a;
    double cur_b;
    double cur_c;
    double cur_d;

    double cur_tar_x;
    double cur_tar_y;
    double cur_tar_z;
    double cur_tar_a;
    double cur_tar_b;
    double cur_tar_c;
    double cur_tar_d;

    QString msg_send;
    QString msg_rece;

    QTcpSocket  *tcpClient;  //socket

};

#endif // WIDGET_H
