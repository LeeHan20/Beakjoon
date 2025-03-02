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

int n, m;
vector<vector<tuple<int, int, int>>> field;
// source to destination, cost, food value
vector<pair<pair<int, int>, pair<int, int>>> dist;
// destination, after eat{distance, max value}, before eat{distance, max value}

struct cmp {
    bool operator() (tuple<int, int, int> const& t1, tuple<int, int, int> const& t2) {
        int dist, node, value;
        int ndist, nnode, nvalue;
        tie(dist, node, value) = t1;
        tie(ndist, nnode, nvalue) = t2;
        
        // 1순위 : dist - value
        // 2순위 : dist
        // 3순위 : value
        // 4순위 : node
        
        if (dist - node != ndist - nnode) return dist - value > ndist - nvalue;
        if (dist != ndist) return dist > ndist;
        if (value != nvalue) return value > nvalue;
        return node > nnode;
    }
};

void dijkstra() {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, cmp> pq;
    // distance, node, max value
    
    pq.push({0, 1, 0});
    dist[1] = {{0, 0}, {0, 0}};
    
    while (!pq.empty()) {
        int distance, node, value;
        tie(distance, node, value) = pq.top();
        pq.pop();
        
//        cout << "node is : " << node << " and distance is : " << distance << " and value is : " << value << endl;
        
        for (auto next : field[node]) {
            int ndistance, nnode, nvalue;
            tie(nnode, ndistance, nvalue) = next;
            nvalue = max(value, nvalue);
            ndistance = ndistance + distance;
            
            if (ndistance < dist[nnode].second.first) {
                dist[nnode].second = {ndistance, nvalue};
                pq.push({ndistance, nnode, nvalue});
            }
            // 정렬 기준에서 dist - value를 1순위로 하고 있기 때문에 distance가 같고 value가 더 큰 상황은 올 수 없음
            if (ndistance - nvalue < dist[nnode].first.first - dist[nnode].first.second) {
                dist[nnode].first = {ndistance, nvalue};
                pq.push({ndistance, nnode, nvalue});
            }
        }
    }
    
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    
    dist.resize(n + 1, {{inf, 0}, {inf, 0}});
    field.resize(n + 1);
    
    for (int i = 0; i < m; ++i) {
        int u, v, w, f;
        cin >> u >> v >> w >> f;
        
        field[u].push_back({v, w, f});
        field[v].push_back({u, w, f});
    }
    
    dijkstra();
    
    for (int i = 2; i < n + 1; ++i) {
        cout << dist[i].first.first - dist[i].first.second << endl;
    }
    
    return 0;
}

// prov

