//
//  Point3D.hpp
//  PZ90WGS84
//
//  Created by v144 on 17.11.15.
//  Copyright © 2015 v144. All rights reserved.
//

#ifndef Point3D_hpp
#define Point3D_hpp

#include <stdio.h>
class Point3D {
    private :
    double x;
    double y;
    double z;
public:
    double getX();
    double getY();
    double getZ();
    void setX(double a);
    void setY(double a);
    void setZ(double a);
    Point3D();
    Point3D(double a,double b,double c);
    Point3D(const Point3D &a);
    Point3D& operator=(const Point3D &a);
};
#endif /* Point3D_hpp */
