#include <iostream>
#include "timeOfDay.h"
#include "alarm.h"

namespace LeeTaerin2276249 {
    // 두 객체의 시간이 같은지 비교하는 비멤버 함수
    bool compareTimeOfDay(const timeOfDay& t1, const timeOfDay& t2) {
        return (t1.getHour() == t2.getHour()) && (t1.getMinute() == t2.getMinute());
    }
}

int main() {
    using namespace std;
    using namespace LeeTaerin2276249;

    alarm obj1; 
    obj1.print();

    alarm obj2(11, 44, true);
    obj2.print();

    if (compareTimeOfDay(obj1.getWakeTime(), obj2.getWakeTime())) {
        cout << "same\n";
    } else {
        cout << "different\n";
    }

    return 0;
}