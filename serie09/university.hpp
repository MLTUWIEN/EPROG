//
// Created by marku on 08.01.2019.
//

#ifndef UNIVERSITY_UNIVERSITY_HPP
#define UNIVERSITY_UNIVERSITY_HPP

#include <iostream>
#include <string>

class University {
private:
    int numStudents;
    std::string city;
    std::string name;
public:
    University(int numStudents = 0, std::string city = "noWhere", std::string name = "noName");

    int getNumStudents();
    std::string getCity();
    std::string getName();

    void setNumStudents(int);
    void setCity(std::string);
    void setName(std::string);

    void graduate(int = 1);
    void newStudent(int = 1);

    void plot();
};

#endif //UNIVERSITY_UNIVERSITY_HPP
