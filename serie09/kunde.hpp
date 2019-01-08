//
// Created by marku on 08.01.2019.
//

#ifndef KUNDE_KUNDE_HPP
#define KUNDE_KUNDE_HPP

#include <iostream>
#include <string>

class Kunde {

private:
    std::string name;
    double kontostand;
    int pin;

public:
    std::string getName();
    double getKontostand();
    int getPin();
    void setName(std::string);
    void setKontostand(double);
    void setPin(int);

    void printBalance();
    bool checkPIN();
    void drawMoney();
};

#endif //KUNDE_KUNDE_HPP
