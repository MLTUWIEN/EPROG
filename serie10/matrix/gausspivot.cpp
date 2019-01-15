//
// Created by markus on 15.01.2019.
//

#include "matrix.hpp"
#include "vector.hpp"
#include <iostream>

Matrix eliminate(const Matrix& M, Vector& x);
Vector solveU(const Matrix& U, const Vector& x);
void pivot(Matrix& A, Vector& b);

Vector gausspivot(Matrix& M, Vector& x) {
    assert(M.getDimension() == x.size());

    //pivot-Suche
    std::cout << "pivot..." << std::endl;
    pivot(M,x);
    M.printMatrix();
    //Elimination
    std::cout << "eliminate..." << std::endl;
    Matrix A = eliminate(M,x);
    A.printMatrix();
    //Solve
    std::cout << "solve..." << std::endl;
    return solveU(A,x);
}

void pivot(Matrix& A, Vector& b) {
    int n = b.size();
    for (int k = 0; k < n; k++) {
        //betragsgroestes Element auswaehlen
        int p = k;
        for (int j = k; j < n; j++) {
            if (A.getCoefficient(j,k) > A.getCoefficient(p,k)) {
                p = j;
            }
        }
        //Vertauschen
        double btemp = b.get(k);
        b.set(k,b.get(p));
        b.set(p,btemp);
        for (int col = 0; col < n; col++) {
            double temp = A.getCoefficient(k,col);
            A.setCoefficient(k,col,A.getCoefficient(p,col));
            A.setCoefficient(p,col,temp);
        }
    }
}

Matrix eliminate(const Matrix& M, Vector& x) {
    int n = M.getDimension();
    Matrix U('U',n);

    for (int k = 0; k < n; k++) {
        U.setCoefficient(0,k,M.getCoefficient(0,k)); //kopiere 0-te Zeile
    }
    //fuer jede Zeile j wird fuer jede darunterliegende Zeile jo (j*factor) von jo abgezogen
    for (int j = 0; j < n; j++) {
        assert(M.getCoefficient(j,j) != 0);

        for (int jo = j+1; jo < n; jo++) {
            double factor = M.getCoefficient(j,jo)/M.getCoefficient(j,j);

            x.set(jo, x.get(jo) - x.get(j)*factor);
            for (int k = jo; k < n; k++) {
                U.setCoefficient(jo,k,M.getCoefficient(jo,k) - M.getCoefficient(j,k)*factor);
            }
        }
    }

    return U;
}