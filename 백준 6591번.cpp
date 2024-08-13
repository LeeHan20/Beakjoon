#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void combination (int n, int k) {
    unsigned long long result = 1;
    k = min(k, n - k); // 최적화를 위한 몸부림
    for (int i = 1; i <= k; ++i) {
            result *= n - (k - i);
            result /= i;
        }
    
    cout << result << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    while (true) {
        cin >> n >> k;
        if (n == 0 && k == 0) {
            break;
        }
        else {
            combination(n, k);
        }
    }
    return 0;
}

//더 원론적인 부분을 구현할 때는 include하는 라이브러리의 수가 적어지는 모습이다
//파이썬으로 하면 import math의 combination 함수로 날먹이 가능하겠지만 이런 원론적인 문제는 역시 c++이 압도적으로 좋은 모습
//성능이 뛰어나다고는 장담하지 못하지만 math의 com을 구현한 것. 매우 의미 있다

//언젠가 iostream을 구현해보면 좋겠다
