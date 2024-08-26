// 8/26 깃허브 코드

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> people;
    for (int i = 1; i <= N; ++i) {
        people.push_back(i);
    }
    //백터 resize할 필요 없이 그냥 이렇게 넣음
    //resize형식은 c에서만 하자~

    vector<int> result;
    int index = 0;

    while (!people.empty()) {
        index = (index + K - 1) % people.size();
        //%연산을 n진수 연산에서 활용하듯이 사용함
        result.push_back(people[index]);
        people.erase(people.begin() + index);
    }
    //요즘 for문보다 그냥 이렇게 돌려버리면 훨씬 편한 것 같다

    cout << "<";
    for (int i = 0; i < result.size(); ++i) {
        if (i > 0) {
            cout << ", ";
        }
        cout << result[i];
    }
    cout << ">\n";

    return 0;
}

//백준 1158번

//수능에서 미적분을 하긴 했는데 이게 원순열인가?
//아무튼 구현이 그리 어렵지는 않다

//다만 마지막에 구질구질하게 출력 형식을 정해두는 것은 맘에 들지 않는다
