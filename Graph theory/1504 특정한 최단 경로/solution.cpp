#include "iostream"
#include "vector"
#include "queue"
#include "deque"
#include "string"
#include "stack"
#include "cmath"
#include "tuple"
#define endl '\n'
#define inf 2147483647
using namespace std;
typedef long long ll;

int n, k;
int x, y;
vector<vector<pair<int, int>>> linked_list;
//dist, node

int dijkstra(int start, int goal) {
//    cout << start << goal << endl;
    vector<int> dist(n + 1, inf);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // distance, node
    
    pq.push({0, start});
    dist[start] = 0;
    
    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();
        
//        cout << current_node << ' ' << current_dist << endl;
        
        if (current_node == goal) return current_dist;
        
        for (auto next : linked_list[current_node]) {
            int next_dist = current_dist + next.first;
            int next_node = next.second;
            
            if (next_dist < dist[next_node]) {
                dist[next_node] = next_dist;
                pq.push({next_dist, next_node});
            }
        }
    }
    
    return -1;
}

void find_better_way() {
    int first_way[] = {1, x, y, n};
    int second_way[] = {1, y, x ,n};
    
    int first_cost = 0;
    int second_cost = 0;
    
    for (int i = 0; i < 3; ++i) {
        int a = dijkstra(first_way[i], first_way[i + 1]);
        int b = dijkstra(second_way[i], second_way[i + 1]);
        
        if (a == -1 || b == -1) {
            cout << -1 << endl;
            return;
        }
        
        first_cost += a;
        second_cost += b;
    }
    
    cout << min(first_cost, second_cost) << endl;
    
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> k;
    
    linked_list.resize(n + 1);
    
    for (int i = 0; i < k; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        
        linked_list[a].push_back({c, b});
        linked_list[b].push_back({c, a});
    }
    
    cin >> x >> y;
    // 경유지
    
    find_better_way();
    
    return 0;
}

// prov 1504

// 1번 노드에서 두 경유지 중 어느 경유지를 먼저 가는 것이 빠른지 구하고
// 1번 노드 - 1번 경유지 - 2번 경유지 - n번 노드 순으로 다익스트라를 세 번, 여섯 번 돌리면 될 것 같다
