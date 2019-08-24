#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    Widget::broadcast("begin");

    tcpClient=new QTcpSocket(this); //创建socket变量

    connect(tcpClient,SIGNAL(connected()),this,SLOT(onConnected()));
    connect(tcpClient,SIGNAL(disconnected()),this,SLOT(onDisconnected()));
    connect(tcpClient,SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this,SLOT(onSocketStateChange(QAbstractSocket::SocketState)));
    connect(tcpClient,SIGNAL(readyRead()),
            this,SLOT(onSocketReadyRead()));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::broadcast(QString msg){
    ui->action_mainText->appendPlainText(msg);
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
                Widget::broadcast("急停");
                break;
            case 1:
                Widget::broadcast("导入轨迹,且执行关节空间运动");
                break;
            case 2:
                Widget::broadcast("导入轨迹,且执行关节空间运动");
                break;
            case 3:
                Widget::broadcast("导入轨迹,且执行关节空间运动");
                break;

            case 6:
                Widget::broadcast("轨迹执行完毕");
                break;


            case 11:
                Widget::broadcast("读取当前关节角");
                ui->cur_joint_1->setText(data.at(1));
                ui->cur_joint_2->setText(data.at(2));
                ui->cur_joint_3->setText(data.at(3));
                ui->cur_joint_4->setText(data.at(4));
                ui->cur_joint_5->setText(data.at(5));
                ui->cur_joint_6->setText(data.at(6));
                break;
            case 12:
                Widget::broadcast("单点设置目标关节角");
                break;
            case 13:
            {
                Widget::broadcast("读取当前位置");
                ui->cur_pos_x->setText(data.at(1));
                ui->cur_pos_y->setText(data.at(2));
                ui->cur_pos_z->setText(data.at(3));
                ui->cur_pos_rx->setText(data.at(4));
                ui->cur_pos_ry->setText(data.at(5));
                ui->cur_pos_rz->setText(data.at(6));
                break;
            }
            case 14:
                Widget::broadcast("单点设置目标位置");
                break;
            default:
                Widget::broadcast("通信数据格式错误");
                break;
            }

    }
}



void Widget::on_tic_clicked()
{

}




