//
//  transsformation.cpp
//  PZ90WGS84
//
//  Created by v144 on 17.11.15.
//  Copyright © 2015 v144. All rights reserved.
//

#include "transsformation.hpp"
#include "Point3D.hpp"
#include <vector>
#include <iostream>
#include <math.h>
Point3D reverseTransformPoint(double xOld,double yOld,double zOld,const double dx,const double dy,const double dz,const double rx,const double ry,const double rz,const double M)
{
    Point3D result;
    double xNew=(1-M)*(xOld-rz*yOld+ry*zOld)-dx;
    double yNew=(1-M)*(rz*xOld+yOld-rx*zOld)-dy;
    double zNew=(1-M)*(-ry*xOld+rx*yOld+zOld)-dz;
    result.setX(xNew);
    result.setY(yNew);
    result.setZ(zNew);
    return result;
}
Point3D transformPoint(double xOld,double yOld,double zOld,const double dx,const double dy,const double dz,const double rx,const double ry,const double rz,const double M)
{
    Point3D result;
    double xNew=(1+M)*(xOld+rz*yOld-ry*zOld)+dx;
    double yNew=(1+M)*(-rz*xOld+yOld+rx*zOld)+dy;
    double zNew=(1+M)*(+ry*xOld-rx*yOld+zOld)+dz;
    result.setX(xNew);
    result.setY(yNew);
    result.setZ(zNew);
    return result;
}
Point3D transformPointWGS84ToPZ90(double xOld,double yOld,double zOld)
{
    Point3D result=reverseTransformPoint(xOld, yOld, zOld, -1.1, -0.3,-0.9,0, 0, -0.00000082, 0.00000012);
    return result;
    
}
Point3D transformPointPZ90ToWGS84(double xOld,double yOld,double zOld)
{
    Point3D result=transformPoint(xOld, yOld, zOld, -1.1, -0.3,-0.9,0, 0, -0.00000082, 0.00000012);
    return result;
}
std::vector<Point3D> transformVecPointPZ90ToWGS84(std::vector<Point3D> &initDate)
{
    std::vector<Point3D> result;
    for (int i=0;i<initDate.size();i++)
    {
        result.insert(result.end(), transformPointPZ90ToWGS84(initDate[i].getX(), initDate[i].getY(), initDate[i].getZ()));
    }
    return result;
}
std::vector<Point3D> transformVecPointWGS84toPZ90(std::vector<Point3D> &initDate)
{
    std::vector<Point3D> result;
    for (int i=0;i<initDate.size();i++)
    {
        result.insert(result.end(), transformPointWGS84ToPZ90(initDate[i].getX(), initDate[i].getY(), initDate[i].getZ()));
    }
    return result;
}
void output(std::vector<Point3D> init,std::vector<Point3D> result,int a)
{
    if (a==84)
    {
        std::cout<<"1-PZ90 2-WGS84"<<std::endl;
    }
    if (a==90)
    {
        std::cout<<"1-WGS84 2-PZ90"<<std::endl;
    }
        for (int i=0;i<result.size();i++)
        {
            std::cout<<"1: x="<<init[i].getX()<<" y="<<init[i].getY()<<" z="<<init[i].getZ()<<std::endl;
            std::cout<<"2: x="<<result[i].getX()<<" y="<<result[i].getY()<<" z="<<result[i].getZ()<<std::endl;
        }
}
Point3D ToMetres(double lat, double lon)
{
    lat *= 3.14159265359 / 180;
    lon *= 3.14159265359 / 180;
    Point3D a;
    a.setX( 6371000 * cos(lat) * cos(lon));
    a.setY( 6371000 * cos(lat) * sin(lon));
    a.setZ(6371000 * sin(lat));
    return a;
}
void ToLat(Point3D &a)
{
    double R=6371000;
    double Pi=3.14159265359;
    double lat = asin(a.getZ() / R);
    double lon = atan2(a.getY(), a.getX());
    a.setX(lat*180/Pi);
    a.setY(lon*180/Pi);
    a.setZ(-1);
}


