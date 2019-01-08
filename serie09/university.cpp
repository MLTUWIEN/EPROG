#include "university.hpp"

using namespace std;

University::University(int numStudents, string city, string name) {
    this->numStudents = numStudents;
    this->city = city;
    this->name = name;
}

int University::getNumStudents() {
    return numStudents;
}
string University::getCity() {
    return city;
}
string University::getName() {
    return name;
}
void University::setNumStudents(int numStudents) {
    this->numStudents = numStudents;
}
void University::setCity(string city) {
    this->city = city;
}
void University::setName(string name) {
    this->name = name;
}


void University::graduate(int n) {
    numStudents -= n;
}
void University::newStudent(int n) {
    numStudents += n;
}

void University::plot() {
    cout << "University " << name << " in " << city << " has " << numStudents << " Students" << endl;
}

int main(int argc, char const *argv[]) {
    string name, city;
    int numStudents,x;
    cout << "name:";
    cin >> name;
    cout << "city:";
    cin >> city;
    cout << "numStudents:";
    cin >> numStudents;

    University uni = University(numStudents,city,name);
    uni.plot();

    cout << "graduate:";
    cin >> x;
    uni.graduate(x);
    cout << uni.getNumStudents() << endl;

    cout << "new:";
    cin >> x;
    uni.newStudent(x);

    uni.plot();

    return 0;
}