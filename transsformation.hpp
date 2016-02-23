//
//  transsformation.hpp
//  PZ90WGS84
//
//  Created by v144 on 17.11.15.
//  Copyright © 2015 v144. All rights reserved.
//

#ifndef transsformation_hpp
#define transsformation_hpp

#include <stdio.h>
#include "Point3D.hpp"
#include <vector>
Point3D reverseTransformPoint(double xOld,double yOld,double zOld,const double dx,const double dy,const double dz,const double rx,const double ry,const double rz,const double M);
Point3D transformPoint(double xOld,double yOld,double zOld,const double dx,const double dy,const double dz,const double rx,const double ry,const double rz,const double M);
Point3D transformPointWGS84ToPZ90(double xOld,double yOld,double zOld);
Point3D transformPointPZ90ToPWGS84(double xOld,double yOld,double zOld);
std::vector<Point3D> transformVecPointPZ90ToWGS84(std::vector<Point3D> &initDate);
std::vector<Point3D> transformVecPointWGS84toPZ90(std::vector<Point3D> &initDate);
void output(std::vector<Point3D> init,std::vector<Point3D> result,int a);
Point3D ToMetres(double lat, double lon);
void ToLat(Point3D &a);
#endif /* transsformation_hpp */
