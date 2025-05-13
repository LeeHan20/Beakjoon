#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <stack>
#include "string"
#include "algorithm"
#include "cmath"
#include "unordered_map"
#include <string>
#include "unordered_set"
#define endl '\n'
#define space ' '
#define INF 2147483647
#define MAX 2501
using namespace std;
typedef long long ll;
//const long long INF = 1LL << 60;
//typedef __int128 ll;

int v, e;
vector<vector<pair<int, int>>> grid;
vector<bool> visited;
bool flag = false;

void prim() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    for (auto edge : grid[1]) {
        pq.push(edge);
    }
    visited[1] = true;
    
    int edge_used = 1;
    int total_weight = 0;
    while (!pq.empty() && edge_used < v) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if (visited[node] == true) continue;
        visited[node] = true;
        
//        cout << node << ' ' << weight << ' ' << edge_used << ' ' << total_weight << endl;
        
        edge_used++;
        total_weight += weight;
        
        for (auto edge : grid[node]) {
            pq.push(edge);
        }
    }
    
    if (edge_used == v) {
        flag = true;
        cout << total_weight << endl;
    }
    
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> v >> e;
    grid.resize(v + 1);
    visited.resize(v + 1);
    
    for (int i = 0; i < e; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        
        grid[a].push_back({c, b});
        grid[b].push_back({c, a});
    }
    
    for (int i = 1; i < v + 1; ++i) {
        if (flag == true) break;
        prim();
    }

    return 0;
}
