//
// Created by marku on 08.01.2019.
//

#ifndef TRIANGLE_TRIANGLE_HPP
#define TRIANGLE_TRIANGLE_HPP


#include <iostream>
#include <cmath>

class Triangle {

private:
    double x[2];
    double y[2];
    double z[2];

    bool isEqual(double a, double b);

public:
    void setX(double, double);
    void setY(double, double);
    void setZ(double, double);

    double getArea();
    double getPerimeter();
    bool isEquilateral();
};



#endif //TRIANGLE_TRIANGLE_HPP
