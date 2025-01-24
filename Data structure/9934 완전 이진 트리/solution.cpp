#include "iostream"
#include "vector"
#include "queue"
#include "deque"
#include "string"
#include "stack"
#include "cmath"
#define endl '\n'
using namespace std;
typedef long long ll;

int n;
vector<int> sequence;
vector<int> quantity_node(11);
vector<pair<int, int>> results;
// stratification, node

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    
    quantity_node[1] = 1;
    for (int i = 2; i < 11; ++i) {
        quantity_node[i] = 2 * quantity_node[i - 1] + 1;
    }
    
    int size = quantity_node[n];
    
    sequence.resize(size + 1);
    for (int i = 1; i < size + 1; ++i) {
        cin >> sequence[i];
    }
    
    for (int i = 0; i < n; ++i) {
        int starting_point = 1 << i;
        int gap = 1 << (i + 1);
        
        for (int j = starting_point; j <= size; j += gap) {
            results.push_back({i, sequence[j]});
        }
    }
    
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < size; ++j) {
            if (results[j].first == i) {
                cout << results[j].second << ' ';
            }
        }
        cout << endl;
    }
    
    
    return 0;
}

// prov perfect binary tree

// 무조건 완전 이진 트리로 이루어져 있음
