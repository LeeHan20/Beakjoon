#include "iostream"
#include "vector"
#include "queue"
#include "string"
#include "utility"
#include "math.h"
#include "algorithm"
#include "unordered_set"
#include "tuple"
using namespace std;

vector<vector<int>> node_connections;

int bfs(int x) {
    vector<int> check(101);
    int bacon_number = 0;
    
    queue<pair<int, int>> q;
    q.push({x, 0});
    check[x] = true;
    
    while (!q.empty()) {
        pair<int, int> focus_node = q.front();
        int current_depth = focus_node.second;
        q.pop();
        
        bacon_number += current_depth;
        
        for (int next_node : node_connections[focus_node.first]) {
            if (!check[next_node]) {
                check[next_node] = true;
                q.push({next_node, current_depth + 1});
            }
        }
        
    }
    
    return bacon_number;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    node_connections.resize(n + 1);
    
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        
        node_connections[a].push_back(b);
        node_connections[b].push_back(a);
    }
    
    int current_smallest_bacon_number = 99999999;
    int current_bacon_person = 1;
    for (int i = 1; i < n + 1; ++i) {
        int current_number = bfs(i);
        if (current_smallest_bacon_number > current_number) {
            current_bacon_person = i;
            current_smallest_bacon_number = current_number;
        }
    }
    
    cout << current_bacon_person << endl;
    
    return 0;
}

//prov 1389

//탐색은 bfs나 dfs 둘 다 사용해도 상관없음
//sort의 comp를 사용하는 방법과 just for문으로 돌려서 찾는 방법이 있음
//sort는 이분정렬을 해준다고 하는데 그게 전체를 sort해도
//for문으로 돌리면 n이고 이분정렬을 하면 nlongn같은데 그냥 직접 비교가 나을 듯
