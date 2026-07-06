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
            std::cin >> h;
            std::cout << "Enter minute(0~59): ";
            std::cin >> m;
            
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

    // 1. 전위 증가 연산자 (++t) : 1분을 먼저 더하고 나를 반환
        timeOfDay& operator++() {
            minute++;
            if (minute >= 60) {
                minute = 0;
                hour++;
                if (hour >= 24) {
                    hour = 0;
                }
            }
            return *this; // 내 원본 객체 자체를 리턴

        // ++minute;
        // if (minute==60) {minute=0;++hour;}
        // if (hour==24){hour=0;}
        // return timeOfDay{hour, minute};
        }

        // 2. 후위 증가 연산자 (t++) : 현재 상태를 복사해두고, 1분 더한 뒤, 복사본 반환
        // (괄호 안에 의미 없는 'int'를 적어주는 게 전위랑 구별하는 C++의 약속!)
        timeOfDay operator++(int) {
            timeOfDay temp = *this; // 바뀌기 전 현재 상태 저장 (복사생성자 작동)
            
            // 위에 만든 전위 증가 함수를 재활용해서 1분 올리기
            ++(*this); 
            
            return temp; // 1분 올라가기 전의 옛날 상태를 리턴

        // timeOfDay temp{hour,minute};
        // ++minute;
        // if (minute==60) {minute=0;++hour;}
        // if (hour==24){hour=0;}
        // return temp;

        }

        // 3. 입력 연산자 (>>): std::cin >> t; 할 때 작동
        friend std::istream& operator>>(std::istream& in, timeOfDay& t) {
            int h, m;
            in >> h >> m;
            t.testHour(h);
            t.testMinute(m);
            t.hour = h;
            t.minute = m;
            return in;
        // std::cout<<"Enter hour(0~23): "; in>>t.hour; t.testHour();
        // std::cout<<"Enter minute(0~59): "; in>>t.minute; t.testMinute();
        // return is;

        }

        // 4. 출력 연산자 (<<): std::cout << t; 할 때 작동
        friend std::ostream& operator<<(std::ostream& out, const timeOfDay& t) {
            if (t.hour < 10) out << "0";
            out << t.hour << ":";
            if (t.minute < 10) out << "0";
            out << t.minute;
            return out;
            

        }

        // 5. 이항 연산자 (==): 두 시간이 같은지 비교
        friend bool operator==(const timeOfDay& t1, const timeOfDay& t2) {
            return (t1.hour == t2.hour) && (t1.minute == t2.minute);
        }

        // 6. 이항 연산자 (+): 두 시간을 더한 새로운 객체 반환
        friend timeOfDay operator+(const timeOfDay& t1, const timeOfDay& t2) {
            int totalMinute1 = t1.minute + t2.minute;
            int totalHours = t1.hour + t2.hour + (totalMinutes / 60);
            
            totalMinutes %= 60;
            totalHours %= 24; // 24시가 넘어가면 하루 순환 처리

        // int minute1{t1.minute+t1.hour*60};
        // int minute2{t2.minute+t2.hour*60};
        // int totalMinutes{minute1+minute2};
        // int newMinute{totalMinutes%60};
        // int newHour{totalMinte/60};
        // if (newHour >24)newHour = newHour%24;
        // return timeOfDay{newHour, newMinute};
            
            return timeOfDay(totalHours, totalMinutes);
        }
    };
}