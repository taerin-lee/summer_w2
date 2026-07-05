#pragma once
#include <iostream>
#include <cstdlib>

namespace LeeTaerin2276249 {

    class timeOfDay {
    private: //private은 안적어도 ok
        int hour{}; //중괄호 안써도 ok. 값을 initialize 해주니까
        int minute;

        void testHour(int h) { //int h (매개변수) 없어도 됨
            if (h < 0 || h > 23) {
                using namespace std; 
                cout << "Wrong hour.\n";
                std::exit(1);
            }
            //혹은 걍 std::exit(1); ? 
        }

        void testMinute(int m) {
            if (m < 0 || m > 59) {
                using namespace std; 
                cout << "Wrong minute.\n";
                std::exit(1);
            }
        }

    public:

        timeOfDay(int h = 0, int m = 0):hour{h}, minute{m} 
        { 
            testHour(h);
            testMinute(m);
        }

        void input() {
            int h, m;
            {
                using namespace std;
                cout << "Enter hour(0~23): ";
                cin >> h;
                cout << "Enter minute(0~59): ";
                cin >> m;
            }
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
            // using namespace std;
            
            // if (hour < 10) cout << "0";
            // cout << hour << ":";
            
            // if (minute < 10) cout << "0";
            // cout << minute;

            if (hour<10) std::cout <<"0";
            std::cout << hour << ":";
            if(minute<10) std::cout <<"0";
            std::cout << minute;
        }

        int getHour() const { return hour; }
        int getMinute() const { return minute; }
    };

} 