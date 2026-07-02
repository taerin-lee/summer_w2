#include <iostream>
#include "timeOfDay.h"// <<이건 알람에서 include 해서 안적어도됨
#include "alarm.h"

namespace LeeTaerin2276249 {

    // 두 객체의 시간이 같은지 비교하는 비멤버 함수
    bool compareTimeOfDay(const timeOfDay& t1, const timeOfDay& t2) {
        return (t1.getHour() == t2.getHour()) && (t1.getMinute() == t2.getMinute());
    }

}

// 교수님버전 int main(){ using namespace LeeTaerin2276249; alarm a1; a1.print();
//                                          alarm a2{timeOfDay{11,44}, 1}; a2.print(); 
//                                          if (compareTimeOfDay(a1.getWakeTime(), a2.getWakeTime())) std::cout<<"same\n";
//                                          else std::cout<<"different\n";}
int main() {
    using namespace std;
    using namespace LeeTaerin2276249;

    cout << "객체 1 생성, 초기 상태 출력\n";
    alarm obj1; 
    obj1.print();

    cout << "\n객체1 입력\n";
    obj1.getWakeTime().input(); 

    cout << "\n객체 2 생성 (알람: 07:30)\n";
    alarm obj2(7, 30, true);
    obj2.print();

    cout << "\n객체 확인\n";
    cout << "객체 1: "; obj1.print();
    cout << "객체 2: "; obj2.print();

    cout << "\n시간 비교 결과\n";
    if (compareTimeOfDay(obj1.getWakeTime(), obj2.getWakeTime())) {
        cout << "same\n";
    } else {
        cout << "different\n";
    }

    return 0;
}