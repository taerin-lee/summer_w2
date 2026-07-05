#pragma once
#include <iostream>
#include <cstdlib>

namespace LeeTaerin2276249 {

    class timeOfDay {
    private: 
        int hour{}; 
        int minute{};

        void testHour(int h) { 
            if (h < 0 || h > 23) {
                std::cout << "Wrong hour.\n";
                std::exit(1);
            }
        }

        void testMinute(int m) {
            if (m < 0 || m > 59) {
                std::cout << "Wrong minute.\n";
                std::exit(1);
            }
        }

    public:
        timeOfDay(int h = 0, int m = 0) : hour{h}, minute{m} { 
            testHour(h);
            testMinute(m);
        }

        void input() {
            int h, m;
            std::cout << "Enter hour(0~23): ";
            std::std::cin >> h;
            std::cout << "Enter minute(0~59): ";
            std::std::cin >> m;
            
            testHour(h);
            testMinute(m);
            hour = h;     
            minute = m;   
        }

        void setHour(int h) {
            testHour(h); 
            hour = h;
        }

        void setMinute(int m) {
            testMinute(m); 
            minute = m;
        }

        void print() const {
            if (hour < 10) std::cout << "0";
            std::cout << hour << ":";
            if (minute < 10) std::cout << "0";
            std::cout << minute;
        }

        int getHour() const { return hour; }
        int getMinute() const { return minute; }
    };

}