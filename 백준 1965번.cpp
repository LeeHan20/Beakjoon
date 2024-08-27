// 8/27 깃허브 코드

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(const vector<int> &list) {
    cout << "[";
    for (int i : list) {
        cout << i << ",";
    }
    cout << "]" << "\n";
    return;
}

int counter(vector<int> &box_sizes, int box_number) {
    vector<int> dp(box_number, 1);

    for (int i = 1; i < box_number; ++i) {
        for (int j = 0; j < i; ++j) {
            if (box_sizes[j] < box_sizes[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
                print(dp);
                //백준에 넣으려면 이 부분은 지워야 한다
                //dp, max도 중요하지만 인덱스 부분이 가장 중요하다
                //box_size 백터의 첫 부분부터 접근하지 않고 각 요소에 대해 하나하나 접근한다
                //결국 답이 나오는 부분수열의 마지막 원소에 해당하는 dp 테이블의 원소가 정답이 되는 구조
            }
        }
    }
    int result = *max_element(dp.begin(), dp.end());
    //왜 굳이 이렇게 돌아가게 만든 건지는 잘 모르겠다
    //이게 포인터라는 것인가
    return result;
}

int main() {
    int box_number;
    cin >> box_number;
    vector<int> box_sizes(box_number);

    for (int i = 0; i < box_number; ++i) {
        cin >> box_sizes[i];
    }

    cout << counter(box_sizes, box_number) << endl;

    return 0;
}

//백준 1965번
