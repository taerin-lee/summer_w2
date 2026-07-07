#include <iostream>
#include <string>
#include <array>
#include "alarm.h"

namespace LeeTaerin2276249 {

    void printAlarmArray(const alarm arr[], const int n) {
        for (int i = 0; i < n; ++i) {
            std::cout << arr[i] << "\n";
        }
    }

}

int main() {
    using namespace LeeTaerin2276249;
    const int n{4};

    alarm alarmArray[n];
    alarmArray[0] = alarm{"Morning", {6, 30}, 1};
    alarmArray[1].setName("Class");
    alarmArray[1].setWakeTime(timeOfDay(9, 0));
    alarmArray[1].setActive(1);
    alarmArray[2].input();
    std::cin >> alarmArray[3];

    printAlarmArray(alarmArray, n);

    std::array<alarm, n> alarmStdArray;

    for (int i = 0; i < alarmStdArray.size(); ++i) {
        alarmStdArray.at(i) = alarmArray[i];
    }
    for (const auto& alm : alarmStdArray) {
        alm.print();
    }
    return 0;
}