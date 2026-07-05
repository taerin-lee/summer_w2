#pragma once
#include <iostream>
#include "timeOfDay.h"

namespace LeeTaerin2276249 {

    class alarm {
    private:
        timeOfDay wakeTime;
        bool inActive; 

    public:

        alarm(timeOfDay t = timeOfDay(0, 0), bool a = false) : wakeTime(t), inActive(a) {}

        void print() const {
            wakeTime.print();
            std::cout << " alarm is " << (inActive ? "on" : "off") << "\n";
        }

        timeOfDay& getWakeTime() {
            return wakeTime;
        }
    };

}