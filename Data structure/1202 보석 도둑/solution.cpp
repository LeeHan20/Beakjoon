#include <iostream>
#include <vector>
#include <limits>
#include "queue"
#include "unordered_map"
#include "map"
#include "cmath"
#include "stack"
#include "algorithm"
#include "set"
#define endl '\n'
#define space ' '
#define inf 2109999999
using namespace std;
typedef long long ll;

int n,k;
ll stored_value = 0;

struct cmp {
    bool operator() (const pair<int, int>& p1, const pair<int, int>& p2) {
        int first_weight = p1.first, first_value = p1.second;
        int second_weight = p2.first, second_value = p2.second;
        
        if (first_weight != second_weight) return first_value < second_value;
        return first_weight > second_weight;
    }
};
// value 기준 정렬

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
multiset<int> bags;

void find_max_value() {
    while (!pq.empty()) {
        int weight = pq.top().first;
        int value = pq.top().second;
        pq.pop();
        
        auto it = bags.lower_bound(weight);
        if (it != bags.end()) {
            bags.erase(it);
            stored_value += value;
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> k;
    
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        // weight, value
        
        pq.push({a, b});
    }
    
    for (int i = 0; i < k; ++i) {
        int a;
        cin >> a;
        bags.insert(a);
    }
    
//    cout << pq.top().first << ' ' << pq.top().second << endl;
    
    find_max_value();
    
    cout << stored_value << endl;

    return 0;
}

// prov 1202

