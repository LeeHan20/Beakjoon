// 8/24 깃허브 코드

#include <iostream>
using namespace std;

unsigned long long modular_exponentiation(int base, int exponent, int divisor) {
    unsigned long long result = 1;
    unsigned long long current_base = base % divisor;

    while (exponent > 0) {
        if (exponent % 2 == 1) {  
            result = (result * current_base) % divisor;
        }
        current_base = (current_base * current_base) % divisor;
        exponent /= 2;
    }

    return result;
}

int main() {
    int base, exponent, divisor;
    cin >> base >> exponent >> divisor;
    
    unsigned long long result = modular_exponentiation(base, exponent, divisor);
    cout << result << endl;
    
    return 0;
}

//백준 1629번

//곱셈이 실버에 있을 때부터 알아봤어야 했는데

//컴퓨터개론 시간에 배운 숫자의 이진수 변환을 exponent에 적용하여 계산량을 줄인 것

//알고리즘 명칭은 Exponentiation by Squaring이고 효율성이 굉장이 좋다
//이걸 함수로 정의해놓고 앞으로 제곱할 일이 있으면 참조해도 좋을 것 같다
