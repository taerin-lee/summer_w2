#include <iostream>
#include "timeOfDay.h"
#include "alarm.h"

namespace LeeTaerin2276249 {
    bool compareTimeOfDay(const timeOfDay& t1, const timeOfDay& t2) {
        return (t1.getHour() == t2.getHour()) && (t1.getMinute() == t2.getMinute());
    }
}

int main() {
    using namespace LeeTaerin2276249; 
    
    alarm a1; 
    a1.print();
    
    alarm a2{timeOfDay{11, 44}, true};
    a2.print(); 
    
    if (compareTimeOfDay(a1.getWakeTime(), a2.getWakeTime())) {
        std::cout << "same\n";
    } else {
        std::cout << "different\n";
    }

    return 0;
}