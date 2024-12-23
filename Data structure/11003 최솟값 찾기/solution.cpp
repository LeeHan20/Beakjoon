#include "iostream"
#include "tuple"
#include "queue"
#include "vector"
#include "deque"
#include "ranges"
#include "numeric"
#include "algorithm"
#define endl "\n"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, l;
    cin >> n >> l;
    
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    
    deque<int> dq;
    
    for (int i = 0; i < n; ++i) {
        if (!dq.empty() && dq.front() < i - l + 1) {
            dq.pop_front();
        }
        
        while (!dq.empty() && numbers[dq.back()] >= numbers[i]) {
            dq.pop_back();
        }
        
        dq.push_back(i);
        
        cout << numbers[dq.front()] << ' ';
    }
    
    cout << endl;
    
    return 0;
}

// prov 11003

//방법 1번
// *min_element를 이용하여 반복자 부분에 일반식을 넣어 출력한다

//방법 2번
// 덱의 가장 앞자리에 최소인 인덱스가 오도록 하고 새로운 인덱스가 최소라면 새로운 인덱스를 출력한다
// 그 뒤로 가장 작은 원소의 인덱스가 대기한다
