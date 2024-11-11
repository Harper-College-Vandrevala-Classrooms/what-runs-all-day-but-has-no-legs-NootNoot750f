//
// Created by nickh on 11/10/2024.
//
#include <thread>

#include "Timer.h"

int main() {
    Timer timer;

    cout << "Timer Started" << endl;
    timer.start();

    this_thread::sleep_for(chrono::seconds(10));

    cout << "Timer Stopped" << endl;
    timer.stop();

    int secondsElapsed = timer.elapsed();
    if(secondsElapsed != -1) {
        cout << "Time Elapsed: " << secondsElapsed << " seconds" << endl;
        timer.pretty_print();

    }


}
