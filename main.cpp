//
//  main.cpp
//  PZ90WGS84
//
//  Created by v144 on 17.11.15.
//  Copyright © 2015 v144. All rights reserved.
//

#include <iostream>
#include "Point3D.hpp"
#include "transsformation.hpp"
#include <vector>
#include <iostream>
#include <cmath>
int main(int argc, const char * argv[]) {
    std::vector<Point3D> test;
    Point3D res;
    res.setX(127);
    res.setY(250);
    res=ToMetres(res.getX(), res.getY());
    test.insert(test.end(), Point3D(res.getX(),res.getY(),res.getZ()));
    std::vector<Point3D> test1=transformVecPointWGS84toPZ90(test);
    output(test, test1, 90);
    auto test2=transformVecPointPZ90ToWGS84(test1);
    output(test1, test2, 84);
    double diffX=((test1[0].getX()-test2[0].getX())*(test1[0].getX()-test2[0].getX()));
    double diffY=((test1[0].getY()-test2[0].getY())*(test1[0].getY()-test2[0].getY()));
    double diffZ=((test1[0].getZ()-test2[0].getZ())*(test1[0].getZ()-test2[0].getZ()));
    //std::cout<<"diff x "<<sqrt((test1[0].getX()-test2[0].getX())*(test1[0].getX()-test2[0].getX()))<<std::endl;
    //std::cout<<"diff y "<<sqrt((test1[0].getY()-test2[0].getY())*(test1[0].getY()-test2[0].getY()))<<std::endl;
    //std::cout<<"diff z "<<sqrt((test1[0].getZ()-test2[0].getZ())*(test1[0].getZ()-test2[0].getZ()))<<std::endl;
    std::cout<<"diff metres"<<sqrt(diffX+diffY+diffZ)<<std::endl;
    Point3D result;
    result.setY(diffY);
    result.setX(diffX);
    result.setZ(diffZ);
    ToLat(result);
    ToLat(test1[0]);
    ToLat(test2[0]);
    //std::cout<<result.getX()<<std::endl;
    //std::cout<<result.getY()<<std::endl;
    //std::cout<<(test1[0].getX()-55)*3600<<" "<<(test1[0].getY()-37)*3600<<std::endl;
    std::cout<<test1[0].getX()<<" "<<test1[0].getY()<<std::endl;
    int a=5;
    a=a & 3;
    std::cout<<1/0 <<std::endl;
    
    return 0;
}
