//
// Created by marku on 08.01.2019.
//

#ifndef MATRIXL_MATRIXL_HPP
#define MATRIXL_MATRIXL_HPP


#include <cmath>
#include <iostream>
#include <cassert>

class MatrixL {
private:
    int dim;
    double *coeff;

public:
    MatrixL(int dim, double init = 0);

    ~MatrixL();

    double getCoefficient(int j, int k);

    void setCoefficient(int j, int k, double x);

    int getDim();

    void scanMatrixL(int n);

    void printMatrixL();

    double columnSumNormL();

    double rowSumNormL();
};

#endif //MATRIXL_MATRIXL_HPP
