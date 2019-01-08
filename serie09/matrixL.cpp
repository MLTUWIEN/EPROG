#include "matrixL.hpp"

using namespace std;

MatrixL::MatrixL(int dim, double init) {
    assert(dim > 0);
    coeff = new double[dim*(dim+1)/2];
    for (int i = 0; i < dim; i++) {
        coeff[i] = init;
    }
}
MatrixL::~MatrixL() {
    delete[] coeff;
}

double MatrixL::getCoefficient(int j, int k) {
    assert(j < dim && k < dim);
    if (k <= j) {
        return coeff[j*(j+1)/2 + k];
    } else {
        return 0;
    }

}

void MatrixL::setCoefficient(int j, int k, double x) {
    assert(k <= j);
    assert(j < dim && k < dim);
    coeff[j*(j+1)/2 + k] = x;
}
int MatrixL::getDim() {
    return dim;
}

void MatrixL::scanMatrixL(int n) {
    double x;
    delete[] coeff;
    coeff = new double[n*(n+1)/2];
    dim = n;
    for (int j = 0; j < n; j++) {
        cout << j << "-te Zeile:" << endl;
        for (int k = 0; k <= j; k++) {
            cin >> x;
            setCoefficient(j,k,x);
        }
    }
}
void MatrixL::printMatrixL() {
    for (int j = 0; j < dim; j++) {
        for (int k = 0; k <= j; k++) {
            cout << getCoefficient(j,k);
        }
        cout << endl;
    }
}
double MatrixL::columnSumNormL() {
    double sum;
    double max = 0;
    for (int k = 0; k < dim; k++) {
        sum = 0;
        for (int j = k; j < dim; j++) {
            sum += fabs(getCoefficient(j,k));
        }
        if (sum > max) {
            max = sum;
        }
    }
    return max;
}
double MatrixL::rowSumNormL() {
    double sum;
    double max = 0;
    for (int j = 0; j < dim; j++) {
        sum = 0;
        for (int k = 0; k <= j; k++) {
            sum += fabs(getCoefficient(j,k));
        }
        if (sum > max) {
            max = sum;
        }
    }
    return max;
}

int main() {
    MatrixL mat(1);
    int n;
    cout << "Dimension eingeben:" << endl;
    cin >> n;
    cout << "Matrix eingeben:" << endl;
    mat.scanMatrixL(n);

    mat.printMatrixL();
    cout << "Spaltennorm: " << mat.columnSumNormL() << endl;
    cout << "Zeilennorm: " << mat.rowSumNormL() << endl;

    return 0;
}