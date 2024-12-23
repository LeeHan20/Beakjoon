#include <iostream>
#include <queue>
#define endl "\n"
using namespace std;

const int MOD = 40000;

struct Fire {
    int first;
    int second;
};

bool compare(const Fire& a, const Fire& b) {
    if (b.first == 0 && b.second == 0) {
        return false;
    }
    if (a.first == 0 && a.second == 0) {
        return true;
    }
    return a.second * b.first < b.second * a.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Fire> fires(n);
    for (int i = 0; i < n; ++i) {
        cin >> fires[i].first >> fires[i].second;
    }

    sort(fires.begin(), fires.end(), compare);

    int time = 0;
    for (const auto& fire : fires) {
        time = ((fire.first + 1) * time + fire.second) % MOD;
    }

    cout << time << endl;

    return 0;
}



// prov 2180

//또 메모리 초과
// 시간초과는 시간복잡도를 배우면 일정 부분 해결되었는데
// 메모리 초과는 메모리 복잡도라는 개념이 있는 것 같다

// 아마 c++로 넘어온 것처럼 c로 넘어가야 하는 상황이 생길 수도 있을 것 같다

// 그냥 vector를 priority queue로 바꿔서 sort도 생략해버리고 pair도 갖다 버리고 struct를 사용한다면?
// -> 이게 c 스타일이긴 한데


