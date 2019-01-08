#include "triangle.hpp"

using namespace std;

bool Triangle::isEqual(double a, double b) {
    double precision = 0.0000001;
    return ( a <= b+precision && b <= a+precision );
}

void Triangle::setX(double x0, double x1) {
    x[0] = x0;
    x[1] = x1;
}
void Triangle::setY(double y0, double y1) {
    y[0] = y0;
    y[1] = y1;
}
void Triangle::setZ(double z0, double z1) {
    z[0] = z0;
    z[1] = z1;
}

double Triangle::getArea() {
    return 0.5*( fabs( (y[0]-x[0]) * (z[1]-x[1]) - (z[0]-x[0]) * (y[1]-x[1]) ) );
}

double Triangle::getPerimeter() {
    double a = sqrt( (x[0]-y[0])*(x[0]-y[0]) + (x[1]-y[1])*(x[1]-y[1]) );
    double b = sqrt( (y[0]-z[0])*(y[0]-z[0]) + (y[1]-z[1])*(y[1]-z[1]) );
    double c = sqrt( (z[0]-x[0])*(z[0]-x[0]) + (z[1]-x[1])*(z[1]-x[1]) );

    return a+b+c;
}

bool Triangle::isEquilateral() {
    double a = (x[0]-y[0])*(x[0]-y[0]) + (x[1]-y[1])*(x[1]-y[1]);
    double b = (y[0]-z[0])*(y[0]-z[0]) + (y[1]-z[1])*(y[1]-z[1]);
    double c = (z[0]-x[0])*(z[0]-x[0]) + (z[1]-x[1])*(z[1]-x[1]);

    return isEqual(a,b)&&isEqual(b,c);
}


/*
 * Testcase:
 *
 * x = (0,0)
 * y = (2,0)
 * z = (1, 1.73205080757)
 *
 */

int main() {
    Triangle T= Triangle();
    double a,b;
    cout << "Punkt X:" << endl;
    cin >> a;
    cin >> b;
    T.setX(a,b);
    cout << "Punkt Y:" << endl;
    cin >> a;
    cin >> b;
    T.setY(a,b);
    cout << "Punkt Z:" << endl;
    cin >> a;
    cin >> b;
    T.setZ(a,b);

    cout << "Flaeche: " << T.getArea() << endl;
    cout << "Umfang: " << T.getPerimeter() << endl;
    if (T.isEquilateral()) {
        cout << "gleichseitig" << endl;
    } else {
        cout << "nicht gleichseitig" << endl;
    }
    return 0;
}