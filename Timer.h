//
// Created by nickh on 11/10/2024.
//

#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

class Timer {

public:
    Timer() : elapsedTime(0), running(false) {}

    void start() {
        if (running == true) {
            cout << "The timer is running" << endl;
            return;

        }
        startTime = steady_clock::now();
        running = true;
    }

    void stop() {
        if(running == false) {
            cout << "The timmer is not running" << endl;
            return;
        }
        elapsedTime += duration_cast<seconds>(steady_clock::now() - startTime).count();
        running = false;
    }

    int elapsed() {
        if(running) {
            auto currentDirection = duration_cast<seconds>(steady_clock::now() - startTime).count();
            return elapsedTime + currentDirection;
        }
        return elapsedTime;
    }
    void pretty_print() {
        if(elapsedTime == 0) {
            cout << "No time has passed." << endl;
            return;
        }
        int hours = elapsedTime / 3600;
        int minutes = elapsedTime / 60 % 60;
        int seconds = elapsedTime % 60;

        if(hours > 0) {
            cout << hours << " hours" << endl;

        }
        if(minutes > 0) {
            cout << minutes << " minutes" << endl;
        }
        cout << seconds << " seconds" << endl;
    }

private:
    steady_clock::time_point startTime;
    bool running;
    int elapsedTime;
};



#endif //TIMER_H
