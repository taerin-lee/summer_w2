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

    void parVal(timeOfDay v) {v += 1;}   
    void parRef(timeOfDay& r) {r += 1;}
    void parPtr(timeOfDay* p) {if (p) *p += 1;}
    timeOfDay retVal(timeOfDay v) {v += 1; return v;}
    timeOfDay& retRef(timeOfDay& r) {r += 1; return r;}
    timeOfDay* retPtr(timeOfDay* p) {*p += 1; return p;}
}

int main() {
    using namespace LeeTaerin2276249;

    // timeOfDay t1,t2;
    // std::cin >> t1 >> t2;
    // std::cout << t1 << " " << t2 << "\n";
    // ... same , different 처리하는거 어디갔어

    timeOfDay t(10, 30); std::cout << t << "\n";
    parVal(t); std::cout << t << "\n";

    timeOfDay& r_t{t}; std::cout << r_t << "\n";
    parRef(r_t);std::cout << r_t << "\n";

    timeOfDay* p_t = &t; std::cout << *p_t << "\n"; // a=b 나 a{b} 나 같은건가봐
    parPtr(p_t); std::cout << *p_t << "\n";

    t = timeOfDay(15, 45); 
    std::cout << t << " " << retVal(t) << "\n";
    std::cout << r_t << " " << retRef(r_t)<< "\n"; //그대로 잘 나오는지
    std::cout << *p_t << " " << *retPtr(p_t) << "\n";

    timeOfDay* tPtr = new timeOfDay();
    tPtr->setHour(23);
    tPtr->setMinute(59);
    std::cout << *tPtr << "\n";
    delete tPtr;
    return 0;


    // const int n{4};
    // alarm alarmArray[n];
    // alarmArray[0] = alarm{"Morning", {6, 30}, 1};
    // alarmArray[1].setName("Class");
    // alarmArray[1].setWakeTime(timeOfDay(9, 0));
    // alarmArray[1].setActive(1);
    // alarmArray[2].input();
    // std::cin >> alarmArray[3];

    // printAlarmArray(alarmArray, n);

    // std::array<alarm, n> alarmStdArray;

    // for (int i = 0; i < alarmStdArray.size(); ++i) {
    //     alarmStdArray.at(i) = alarmArray[i];
    // }
    // for (const auto& alm : alarmStdArray) {
    //     alm.print();
    // }
    // return 0;
}