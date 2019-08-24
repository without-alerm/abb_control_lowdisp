#include "widget.h"
#include "ui_widget.h"
#include <translation.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    tcpClient=new QTcpSocket(this); //创建socket变量

    connect(tcpClient,SIGNAL(connected()),this,SLOT(onConnected()));
    connect(tcpClient,SIGNAL(disconnected()),this,SLOT(onDisconnected()));
    connect(tcpClient,SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this,SLOT(onSocketStateChange(QAbstractSocket::SocketState)));
    connect(tcpClient,SIGNAL(readyRead()),
            this,SLOT(onSocketReadyRead()));


    double p_in_w[7] = {1,2,3,   1,0,0,0};
    double r_in_w[7] = {10,20,30,0,1,0,0};
    conversion_abb(p_in_w,r_in_w);
    ui->action_mainText->appendPlainText("out"+ QString::number(p_in_w[0]) +" "+ QString::number(p_in_w[1])+" "+ QString::number(p_in_w[2])+" "+" "+ QString::number(p_in_w[3])+" "+ QString::number(p_in_w[4])+" "+ QString::number(p_in_w[5])+" "+ QString::number(p_in_w[6]) );
}

Widget::~Widget()
{
    delete ui;
}

void Widget::Sleep(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}


void Widget::data_manager(QString msg)
{
    msg = msg.simplified();
    QStringList data = msg.split(",");
    int count = data.count();
    if (count == 8)
    {
            int mark = data.at(0).toInt();
            switch (mark)
            {
 /**
 * 0:急停
 * 1：导入轨迹,且执行关节空间运动
 * 2：导入轨迹,且执行笛卡尔空间直线运动
 * 3：导入轨迹,且执行笛卡尔空间圆弧运动。圆弧运动轨迹需要两条字符串进行确定
 *
 * 11：读取当前关节角
 * 12：单点设置目标关节角
 * 13：读取当前位置
 * 14：单点设置目标位置
 **/
            case 0:
                ui->action_mainText->appendPlainText("急停");
                break;
            case 1:
                ui->action_mainText->appendPlainText("导入轨迹,且执行关节空间运动");
                break;
            case 2:
                ui->action_mainText->appendPlainText("导入轨迹,且执行关节空间运动");
                break;
            case 3:
                ui->action_mainText->appendPlainText("导入轨迹,且执行关节空间运动");
                break;


            case 11:
                ui->action_mainText->appendPlainText("读取当前关节角");
                ui->cur_joint_1->setText(data.at(1));
                ui->cur_joint_2->setText(data.at(2));
                ui->cur_joint_3->setText(data.at(3));
                ui->cur_joint_4->setText(data.at(4));
                ui->cur_joint_5->setText(data.at(5));
                ui->cur_joint_6->setText(data.at(6));
                break;
            case 12:
                ui->action_mainText->appendPlainText("单点设置目标关节角");
                break;
            case 13:
            {
                ui->action_mainText->appendPlainText("读取当前位置");
                double q1 = data.at(4).toDouble();
                double q2 = data.at(5).toDouble();
                double q3 = data.at(6).toDouble();
                double q4 = data.at(7).toDouble();
                double roll;
                double pitch;
                double yaw;
                toEulerAngle_abb(q1,q2,q3,q4,roll,pitch,yaw);
                ui->cur_pos_x->setText(data.at(1));
                ui->cur_pos_y->setText(data.at(2));
                ui->cur_pos_z->setText(data.at(3));
                ui->cur_pos_rx->setText(QString::number(roll,'f',2));
                ui->cur_pos_ry->setText(QString::number(pitch,'f',2));
                ui->cur_pos_rz->setText(QString::number(yaw,'f',2));
                break;
            }
            case 14:
                ui->action_mainText->appendPlainText("单点设置目标位置");
                break;
            default:
                ui->action_mainText->appendPlainText("通信数据格式错误");
                break;
            }

    }
}



void Widget::on_tic_clicked()
{
//    QString test = ui->actionTime->text();
//    test = test.simplified();
//    QStringList xyz = test.split(",");
//    double x = xyz.at(0).toDouble();
//    double y = xyz.at(1).toDouble();
//    double z = xyz.at(2).toDouble();
//    int count = xyz.count();
//    QString text = QString::number(count,'f',2) + "," +QString::number(x,'f',2) + "," +QString::number(y,'f',2)+ ","+QString::number(z,'f',2);
//    ui->action_mainText->appendPlainText(text);
    double p_in_w[7] = {1,2,3,1,0,0,0};
    double r_in_w[7] = {10,20,30,0,1,0,0};
    conversion_abb(p_in_w,r_in_w);
    ui->action_mainText->appendPlainText("out"+ QString::number(p_in_w[0]) +" "+ QString::number(p_in_w[2])+" "+" "+ QString::number(p_in_w[3])+ QString::number(p_in_w[4])+" "+ QString::number(p_in_w[5])+" "+ QString::number(p_in_w[6]) );
}




