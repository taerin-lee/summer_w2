#pragma once
#include <iostream>
#include "timeOfDay.h"

namespace LeeTaerin2276249 {

    class alarm {
    private: //안적어도됨
        timeOfDay wakeTime;
        bool inActive; 

    public:
        alarm() {
            inActive = false;
        }
        alarm(int h, int m, bool active) : wakeTime(h, m) {
            inActive = active;
        }
        //교수님버전 alarm(timeOfDay t=timeOfDay{03:06}, bool a = false):wakeTime{t}, inActive{a}{}
        
        // 여기서는 따로 test 가 안필요하대

        void print() const {
            wakeTime.print();
            
            using namespace std;
            if (inActive) {
                cout << " alarm is on\n";
            } else {
                cout << " alarm is off\n";
            }
        }
        //교수님버전 void print(){ wakeTime.print(); std::cout<<" alarm is "<< ((inActive)? "on" : "off") << "\n";}

        timeOfDay& getWakeTime() {
            return wakeTime;
        }
        //참조 형식 안쓰면
        //timeOfDay getWakeTime(){return wakeTime;}
        //void setWakeTime(timeOfDay t){wakeTime = t;} // 여기 const 붙는거 녹화영상 보기
    };

}