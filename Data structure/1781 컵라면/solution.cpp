#include "iostream"
#include "vector"
#include "queue"
#include "deque"
#include "string"
#include "stack"
#include "cmath"
#include "tuple"
#define endl '\n'
using namespace std;
typedef long long ll;

int n;
int cnt = 0;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> task;
//deadline, ramen

void find_max_ramen() {
    priority_queue<int, vector<int>, greater<int>> pq;
    
    while (!task.empty()) {
        int current_deadline = task.top().first;
        int current_compensation = task.top().second;
        task.pop();
        
        pq.push(current_compensation);
        
        if (pq.size() > current_deadline) {
            pq.pop();
        }
    }
    
    while (!pq.empty()) {
        cnt += pq.top();
//        cout << pq.top() << endl;
        pq.pop();
    }
    
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        int a, b;
        // deadline, ramen
        cin >> a >> b;
        task.push({a, b});
    }
    
    find_max_ramen();
    
    cout << cnt << endl;
    
    return 0;
}

// prov 1781
