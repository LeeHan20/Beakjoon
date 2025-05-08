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
#define endl '\n'
#define space ' '
#define INF 2147483647
#define MAX 2501
using namespace std;
typedef long long ll;
//const long long INF = 1LL << 60;
//typedef __int128 ll;

int n, t;
vector<vector<pair<int, int>>> grid;
int max_depth = 0;
int min_weight = INF;
int far_node;

void dfs(int parent, int child, int depth, int weight) {
    if (max_depth < depth) {
        max_depth = depth;
        far_node = child;
        min_weight = weight;
    }
    else if (max_depth == depth && min_weight > weight) {
        min_weight = weight;
        far_node = child;
    }
    
    for (auto node : grid[child]) {
        int focus_node = node.first;
        int spent_time = node.second;
        
        if (focus_node == parent) continue;
        
        dfs(child, focus_node, depth + 1, weight + spent_time);
    }
    
    return;
}

int find_max_weight(int start) {
    
    queue<tuple<int, int, int, int>> q;
    // parent, child, weight, depth
    
    q.push({n + 2, start, 0, 0});
    
    int min_weight = INF;
    int mdepth = 0;
    while (!q.empty()) {
        int parent, current_node, weight, depth;
        tie(parent, current_node, weight, depth) = q.front();
        q.pop();
        
        if (mdepth < depth) {
            mdepth = depth;
            min_weight = weight;
        }
        
        if (depth == mdepth && min_weight > weight) {
            min_weight = weight;
        }
        
        for (auto node : grid[current_node]) {
            int nnode = node.first;
            int nweight = node.second;
            
            if (nnode == parent) continue;
            
            q.push({current_node, nnode, weight + nweight, depth + 1});
        }
    }
    
    return min_weight;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> t;
    grid.resize(n + 1);
    
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        
        grid[a].push_back({b, c});
        grid[b].push_back({a, c});
    }
    
    dfs(n + 2, 1, 0, 0);
    int one_side = far_node;
    max_depth = 0;
    min_weight = INF;
    dfs(n + 2, far_node, 0, 0);
    
    int addition = (min_weight % t) ? 1 : 0;
    
    cout << min_weight / t + addition << endl;
    
    return 0;
}
