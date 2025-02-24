#include <iostream>
#include <vector>
#include <limits>
#include "queue"
#include "unordered_map"
#include "map"
#include "cmath"
#include "stack"
#include "algorithm"
#define endl '\n'
#define space ' '
#define inf 2109999999
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, int>>> graph(n+1), reverse_graph(n+1);
    vector<int> indegree(n+1, 0);
    
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        reverse_graph[b].push_back({a, c});
        indegree[b]++;
    }
    
    int start, dest;
    cin >> start >> dest;
    
    vector<int> dist(n+1, 0);
    queue<int> q;
    q.push(start);
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for (auto &edge : graph[cur]) {
            int nxt = edge.first;
            int cost = edge.second;
            if(dist[nxt] < dist[cur] + cost) dist[nxt] = dist[cur] + cost;
            if(--indegree[nxt] == 0) q.push(nxt);
        }
    }
    
    vector<bool> visited(n+1, false);
    queue<int> rq;
    rq.push(dest);
    visited[dest] = true;
    
    int count = 0;
    while(!rq.empty()) {
        int cur = rq.front();
        rq.pop();
        for (auto &edge : reverse_graph[cur]) {
            int prev = edge.first;
            int cost = edge.second;
            if (dist[prev] + cost == dist[cur]) {
                count++;
                if (!visited[prev]) {
                    visited[prev] = true;
                    rq.push(prev);
                }
            }
        }
    }
    
    cout << dist[dest] << endl << count << endl;
    
    return 0;
}

// prov
