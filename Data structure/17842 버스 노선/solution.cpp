#include <iostream>
#include <vector>
#include <limits>
#include "queue"
#define endl '\n'
#define space ' '
#define inf 2109999999
using namespace std;

int n;
vector<vector<int>> linked_list;
vector<bool> visited;
int max_distance = 0, farthest_node = 0;
int number_of_ceil = 1;

void dfs(int node, int distance) {
    if (distance > max_distance) {
        max_distance = distance;
        farthest_node = node;
    }

    for (int next_node : linked_list[node]) {

        if (visited[next_node] == true) continue;
        
        visited[next_node] = true;
        dfs(next_node, distance + 1);
    }
    
    return;
}

void bfs() {
    
    vector<int> visited(n, 0);
    visited[farthest_node] = true;
    int condition_branch = 1;
    
    queue<int> q;
    q.push(farthest_node);
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        int loop_detection = 0;
        for (int next : linked_list[node]) {
            if (visited[next] == 1) continue;
            
            visited[next] = 1;
            q.push(next);
            loop_detection++;
        }
        
        if (loop_detection == 0) number_of_ceil++;
    
    }
    
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    
    linked_list.resize(n);
    
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        
        linked_list[b].push_back(a);
        linked_list[a].push_back(b);
    }
    
    int pick = n / 2;
    
    visited.assign(n + 1, false);
    visited[pick] = true;
    dfs(pick, 0);
    
    max_distance = 0;
    visited.assign(n + 1, false);
    visited[farthest_node] = true;
    dfs(farthest_node, 0);
    
    bfs();
    
//    cout << "farthest node is " << farthest_node << endl;
    
    int ans = number_of_ceil % 2 == 0 ? number_of_ceil / 2 : number_of_ceil / 2 + 1;
    
    cout << ans << endl;
    
    return 0;
}

// prov 17842

// 우선 트리의 지름을 구함
// 그 후 가장자리에 있는 노드로부터
