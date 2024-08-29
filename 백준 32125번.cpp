// 8/29 깃허브 코드

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;

void test_case() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    
    vector<pair<int, int>> people(N);
    for (int i = 0; i < N; ++i) {
        cin >> people[i].first;  // 작업 유형 (1 또는 2)
    }
    for (int i = 0; i < N; ++i) {
        cin >> people[i].second; // 능률
    }
    
    // 해시맵을 이용하여 조건을 만족하는 구간을 카운팅
    unordered_map<int, unordered_map<long long, int>> prefix_map;
    prefix_map[0][0] = 1; // 초기 상태 (balance=0, efficiency_diff=0)
    
    int balance = 0;
    long long efficiency_sum1 = 0;
    long long efficiency_sum2 = 0;
    int result = 0;

    for (int i = 0; i < N; ++i) {
        if (people[i].first == 1) {
            balance++;
            efficiency_sum1 += people[i].second;
        } else {
            balance--;
            efficiency_sum2 += people[i].second;
        }
        
        long long efficiency_diff = efficiency_sum1 - efficiency_sum2;

        if (prefix_map.find(balance) != prefix_map.end()) {
            auto& inner_map = prefix_map[balance];
            for (auto& [prev_diff, count] : inner_map) {
                if (abs(efficiency_diff - prev_diff) <= K) {
                    result += count;
                    
                }
            }
        }

        // 현재 balance와 efficiency_diff를 prefix_map에 기록
        prefix_map[balance][efficiency_diff]++;
    }

    cout << result << "\n";
}



int main() {
    int test;
    cin >> test;
    for (int i = 0; i < test; ++i) {
        test_case();
    }
    return 0;
}

//백준 32125번, LGCPC 예선 B번

//21점 부분점수를 받을 수 있는 코드임
//어떤 반례에서 걸린 것 같은데 풀이가 나오면 찾아볼 예정

//8/24 LGCPC 예선 당일 푼 코드
//A번이 더 쉬워 보이기는 하는데 연산자들?을 이해 못 해서 손도 못 댐
//매크로나 간단한 게임을 구현하는 것을 제외하고 어떤 알고리즘을 다뤄야 하는 때면 파이썬은 갖다 버리도록 하자
