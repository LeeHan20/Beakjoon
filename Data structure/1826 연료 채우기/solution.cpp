#include "iostream"
#include "vector"
#include "queue"
#include "deque"
#include "string"
#include "stack"
#include "map"
#define endl '\n'
using namespace std;

typedef long long ll;

int n, village, fuel, cnt = 0;
map<int, int> oilbanks;

void fill_fuel(priority_queue<int>& pq) {
    
    while (!pq.empty() && fuel < 0) {
        int refill_oil = pq.top();
        pq.pop();
        
//        cout << "current fuel is " << fuel << endl;
//        cout << "refill oil value is " << refill_oil << endl;
        
        fuel += refill_oil;
        cnt++;
    }
    
    return;
}

void go_village() {
    
    priority_queue<int> pq;
    // fuel only
    // each idx used only one time
    // so, it dont need to keep idx
    
    int last_oilbank = 0;
    for (auto oilbank : oilbanks) {
        int moving_distance = oilbank.first - last_oilbank;
        int current_oil = oilbank.second;
        last_oilbank = oilbank.first;
        
        fuel -= moving_distance;
        
//        cout << "moving distanve is " << moving_distance << " current oilbank is " << oilbank.first << endl;
        
        fill_fuel(pq);
        
        if (fuel < 0) {
            cout << -1 << endl;
            return;
        }
        
        pq.push(current_oil);
        
    }
    
    cout << cnt << endl;
    
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        oilbanks[a] = b;
    }
    
    cin >> village >> fuel;
    
    oilbanks[village] = 0;
    
    go_village();
    
    return 0;
}

// prov
