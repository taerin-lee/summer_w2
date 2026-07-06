#include <iostream>
#include "timeOfDay.h"
#include "alarm.h"

int main() {

    using namespace LeeTaerin2276249;
    using namespace std;

    timeOfDay t1, t2;
    // 1. 객체 2개를 입력연산자(>>)를 이용해서 표준스트림으로 입력
    // (터미널에 입력할 때 예: 10 20 엔터 치면 10시 20분으로 들어감)
    std::cin>> t1;
    std::cin>> t2;

    // 2. 출력연산자(<<)를 이용해서 표준스트림으로 출력
    cout << t1 << "\n";
    cout << t2 << "\n";
    // std::cout <<t1 <<" "<< t2 <<'\n';

    // 3. 두번째 객체에 전위증가연산자(++) 적용한 것을 표준스트림으로 출력
    cout << ++t2 << "\n";

    // 4. 두번째 객체에 후위증가연산자(++) 적용한 것을 표준스트림으로 출력
    cout << t2++ << "\n";

    // 5. 두번째 객체를 표준스트림으로 출력 (후위증가 이후 반영된 결과 확인용)
    cout << t2 << "\n";

    // 6. 두 객체를 비교연산자(==)를 이용하여 비교
    if (t1 == t2) {
        cout << "same\n";
    } else {
        cout << "different\n";
    }

    // 7. 두 객체를 +이항연산자를 이용하여 더한 값을 표준스트림으로 출력
    cout << (t1 + t2) << "\n";
    // std::cout << t1+t2 <<std::endl;
    return 0;
}