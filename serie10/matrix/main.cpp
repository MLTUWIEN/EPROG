//
// Created by markus on 15.01.2019.
//

#include "matrix.hpp"
#include "vector.hpp"

#include <iostream>

using namespace std;

Vector solve(const Matrix& U, Vector& x);
Vector gausspivot(Matrix& M, Vector& x);

int main() {
    // Matrix m1('L',5,3.75);
    // Matrix m2('U',4,2.5);
    // m2.printMatrix();
    // //m1.scanMatrix('L',3);
    // m1.printMatrix();
    // cout << "Eintrag (2,2): " << m1.getCoefficient(2,2) << endl;
    // cout << "columnSumNorm: " << m1.columnSumNorm() << endl;
    // cout << "rowSumNorm: " << m1.rowSumNorm() << endl;
    // Vector v(m1.getDimension(),2);
    // cout << "v*M[2]: " << (m1*v).get(2);
    // Matrix ran('L',4,5,10);
    // ran.printMatrix();
    Matrix M;
    Vector x(3,2);
    M.scanMatrix('F',3);
    M.printMatrix();
    Vector r = gausspivot(M,x);
    cout << "Result: " << endl;
    for (int i = 0; i < 3; i++) {
        cout << r.get(i) << endl;
    }
    return 0;
}