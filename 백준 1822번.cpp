#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    vector<int> B(m);
    
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    
    for (int i = 0; i < m; ++i) {
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<int> difference;
    difference.resize(A.size()); 
    auto it = set_difference(A.begin(), A.end(), B.begin(), B.end(), difference.begin());

    difference.resize(it - difference.begin());

    cout << difference.size() << "\n";
    for (const int& element : difference) {
        cout << element << " ";
    }
    cout << "\n";

    return 0;
}

//왜 실버 문제로 있는 걸까? 진짜 모르겠다

//c++의 algorithm 라이브러리에서 파이썬에서 지원하는 집합 함수들을 대부분 지원하는 것 같다
//set_difference로 날먹할 수 있는 문제
//사실 이러면 파이썬이나 cpp나 뭐가 다른가 싶긴 한데 
//c++보다 더 로우 레벨의 언어로 가면 굉장이 까다로운 문제가 아닐까 싶다
