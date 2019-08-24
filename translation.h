#ifndef TRANSLATION_H
#define TRANSLATION_H

#include <math.h>
#include <Eigen/Eigen>
using namespace Eigen;

//知乎收录，通过参数引用返回值
static void toEulerAngle_abb(double q1,double q2,double q3,double q4,double& roll, double& pitch, double& yaw)
{
    Eigen::Quaterniond q(q1,q2,q3,q4);

    // roll (x-axis rotation)
    static double sinr_cosp = +2.0 * (q.w() * q.x() + q.y() * q.z());
    static double cosr_cosp = +1.0 - 2.0 * (q.x() * q.x() + q.y() * q.y());
    roll = atan2(sinr_cosp, cosr_cosp);

    // pitch (y-axis rotation)
    static double sinp = +2.0 * (q.w() * q.y() - q.z() * q.x());
    if (fabs(sinp) >= 1)
        pitch = copysign(M_PI / 2, sinp); // use 90 degrees if out of range
    else
        pitch = asin(sinp);

    // yaw (z-axis rotation)
    static double siny_cosp = +2.0 * (q.w() * q.z() + q.x() * q.y());
    static double cosy_cosp = +1.0 - 2.0 * (q.y() * q.y() + q.z() * q.z());
    yaw = atan2(siny_cosp, cosy_cosp);

    roll = roll*180/3.1415926;
    pitch = pitch*180/3.1415926;
    yaw = yaw*180/3.1415926;

}

//通过修改指针指向的地址的值返回值
static void conversion_abb(double *p_in_w, double r_in_w[7])
{
    //提取点在世界坐标系下的信息，并生成齐次矩阵
    double x1 = p_in_w[0];
    double y1 = p_in_w[1];
    double z1 = p_in_w[2];
    double a1 = p_in_w[3];
    double b1 = p_in_w[4];
    double c1 = p_in_w[5];
    double d1 = p_in_w[6];
    Quaterniond r1(a1,b1,c1,d1);
    Vector3d p1(x1,y1,z1);
    Isometry3d t1 = Isometry3d::Identity();
    t1.rotate(r1);
    t1.pretranslate(p1);


    //提取机器人在世界坐标系下的信息，并生成齐次矩阵
    double x0 = r_in_w[0];
    double y0 = r_in_w[1];
    double z0 = r_in_w[2];
    double a0 = r_in_w[3];
    double b0 = r_in_w[4];
    double c0 = r_in_w[5];
    double d0 = r_in_w[6];
    Vector3d p0(x0,y0,z0);
    Quaterniond r0(a0,b0,c0,d0);
    Isometry3d t0= Isometry3d::Identity();
    t0.rotate(r0);
    t0.pretranslate(p0);

    //坐标变换并传递值
    Isometry3d t2;
    t2 = t0.inverse()*t1;

    Matrix3d rMat = t2.rotation();
    Quaterniond r2(rMat);
    Vector3d p2 = t2.translation();
    p_in_w[0] = p2[0];
    p_in_w[1] = p2[1];
    p_in_w[2] = p2[2];
    p_in_w[3] = r2.x();
    p_in_w[4] = r2.y();
    p_in_w[5] = r2.z();
    p_in_w[6] = r2.w();




}


#endif // TRANSLATION_H

