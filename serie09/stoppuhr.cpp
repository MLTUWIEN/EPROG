#include "stoppuhr.hpp"
#include <cmath>


Stoppuhr::Stoppuhr() {
    isRunning = false;
    lastTime = 0;
    tstart = 0;
}

void Stoppuhr::pushButtonStartStop() {
    clock_t now;
    if (isRunning) {
        now = clock();
        isRunning = false;
        lastTime += (double) (now-tstart)/CLOCKS_PER_SEC;
    }
    else {
        tstart = clock();
        isRunning = true;
    }
}

void Stoppuhr::pushButtonReset() {
    isRunning = false;
    lastTime = 0;
}

void Stoppuhr::print() {
    double time;
    if (isRunning) {
        clock_t now = clock();
        time = lastTime + (double) (now-tstart)/CLOCKS_PER_SEC;
    } else {
        time = lastTime;
    }
    double hr,min,sec,ms;
    ms = int(time*100) % 100;
    sec = int(time) % 60;
    min = int(time/60) % 60;
    hr = int(time/(60*60));

    if (hr < 10) {
        std::cout << "0" << hr << ":";
    } else {
        std::cout << hr << ":";
    }
    if (min < 10) {
        std::cout << "0" << min << ":";
    } else {
        std::cout << min << ":";
    }
    if (sec < 10) {
        std::cout << "0" << sec << ":";
    } else {
        std::cout << sec << ":";
    }
    if (ms < 10) {
        std::cout << "0" << ms;
    } else {
        std::cout << ms;
    }
    std::cout << std::endl;
}

int main() {
    Stoppuhr S;
    double sum = 0.0;

    std::cout << "1. Summe von 1/j" << std::endl;
    S.pushButtonStartStop();
    for(int j=0; j<100*1000*1000; ++j)
        sum += 1./j;
    S.pushButtonStartStop();
    S.print();
    S.pushButtonReset();


    std::cout << "2. Summe von pow(j,3)" << std::endl;
    S.pushButtonStartStop();
    for(int j=0; j<100*1000*1000; ++j)
        sum += std::pow(j,3);
    S.pushButtonStartStop();
    S.print();
    S.pushButtonReset();

    std::cout << "3. Summe von j*j*j" << std::endl;
    S.pushButtonStartStop();
    for(int j=0; j<100*1000*1000; ++j)
        sum += j*j*j;
    S.pushButtonStartStop();
    S.print();

    return 0;
}