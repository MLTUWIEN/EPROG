//
// Created by marku on 08.01.2019.
//

#ifndef STOPPUHR_STOPUHR_HPP
#define STOPPUHR_STOPUHR_HPP

#include <iostream>
#include <ctime>

class Stoppuhr {
private:
    clock_t tstart;
    double lastTime;
    bool isRunning;

public:
    Stoppuhr();

    void pushButtonStartStop();

    void pushButtonReset();

    void print();
};

#endif //STOPPUHR_STOPUHR_HPP
