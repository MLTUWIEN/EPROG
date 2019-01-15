//
// Created by marku on 15.01.2019.
//

#ifndef MATRIX_VEKTOR_HPP
#define MATRIX_VEKTOR_HPP


#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>

// The class Vector stores vectors in Rd
class Vector {
private:
    // dimension of the vector
    int dim;
    // dynamic coefficient vector
    double * coeff;
public:
    // constructors and destructor
    Vector();
    Vector(int dim, double init = 0);
    Vector(const Vector& rhs);
    ~Vector();
    // return vector dimension
    int size() const;
    // read and write vector coefficients
    void set(int k, double value);
    double get(int k) const;
    // compute Euclidean norm
    double norm() const;

    Vector& operator=(const Vector& rhs);
};

#endif //MATRIX_VEKTOR_HPP
