#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
#include <tuple>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> scores(n);
    for (int i = 0; i < n; ++i) {
        cin >> scores[i];
    }

    sort(scores.begin(), scores.end());

    long long sum = 0;

    for (int i = 0; i < n; ++i) {
        sum += scores[i];
        if (sum < (long long)i * (i + 1) / 2) {
            cout << -1 << endl;
            return 0;
        }
    }

    if (sum != (long long)n * (n - 1) / 2) {
        cout << -1 << endl;
        return 0;
    }

    cout << 1 << endl;

    return 0;
}

// prov 13560

//조건 분기
// n n-1 / 2가 전체 점수의 합이 되어야 한다
// 각 팀은 최대 n-1의 점수를 가질 수 있다
// 점수가 0인 팀이 두 개 존재할 수는 없음

//랑주의 정리가 있는데 그거 활용하면 됨
//조건분기는 왜인지를 모르겠는데 95%에서 막힘
