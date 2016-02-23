//
//  Point3D.cpp
//  PZ90WGS84
//
//  Created by v144 on 17.11.15.
//  Copyright © 2015 v144. All rights reserved.
//

#include "Point3D.hpp"
double Point3D::getX()
{
    return x;
}
double Point3D::getY()
{
    return y;
}
double Point3D::getZ()
{
    return z;
}
void Point3D::setX(double a)
{
    x=a;
}
void Point3D::setY(double a)
{
    y=a;
}
void Point3D::setZ(double a)
{
    z=a;
}

Point3D::Point3D()
{
    x=0;
    y=0;
    z=0;
}
Point3D::Point3D(double a,double b,double c)
{
    x=a;
    y=b;
    z=c;
}
Point3D::Point3D(const Point3D &a)
{
    x=a.x;
    y=a.y;
    z=a.z;
}


Point3D& Point3D::operator=(const Point3D &a)
{
    x=a.x;
    y=a.y;
    z=a.z;
    return *this;
}