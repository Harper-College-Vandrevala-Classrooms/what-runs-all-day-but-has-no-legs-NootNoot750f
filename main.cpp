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

    int expectedTime = duration_cast<seconds>(steady_clock::now().time_since_epoch()).count();
    cout<< "Elapsed Time: " << secondsElapsed << " secpnds" << endl;
    cout << "Expected Time:" << expectedTime << " seconds" << endl;

    if(secondsElapsed == expectedTime) {
        cout << "The Test Was Passed:" << endl;
    }else {
        cout << "The test failed. Not synced/correct with computer time" << endl;

        if(secondsElapsed != -1) {
            cout << "Time Elapsed:" << secondsElapsed << " Seconds" << endl;
            timer.pretty_print();
        }

    }


}
