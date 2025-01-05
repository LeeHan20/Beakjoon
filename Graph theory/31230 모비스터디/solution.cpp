#include "iostream"
#include "queue"
#include "vector"
#include "set"
#define endl "\n"
#define inf 2e14
using namespace std;

typedef long long ll;

int n, m, a, b;
vector<vector<pair<int, ll>>> linked_list;
vector<ll> dist;
vector<vector<int>> pre;
set<int> answer;

void dijkstra(int start) {
    dist[start] = 0;
    priority_queue<pair<ll, int>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        ll focus_distance = -pq.top().first;
        int focus_node = pq.top().second;
        pq.pop();

        if (dist[focus_node] < focus_distance) {
            continue;
        }
        
        for (auto next : linked_list[focus_node]) {
            int next_node = next.first;
            ll next_cost = next.second;

            if (dist[next_node] > dist[focus_node] + next_cost) {
                dist[next_node] = dist[focus_node] + next_cost;
                pq.push({-dist[next_node], next_node});
                pre[next_node].clear();
                pre[next_node].push_back(focus_node);
            } 
            else if (dist[next_node] == dist[focus_node] + next_cost) {
                pre[next_node].push_back(focus_node);
            }
        }
        
    }
    
    return;
}

void find_all_paths(int goal, set<int>& nodes) {
    queue<int> q;
    q.push(goal);
    nodes.insert(goal);

    while (!q.empty()) {
        int current_node = q.front();
        q.pop();

        for (int prev_node : pre[current_node]) {
            if (!nodes.count(prev_node)) {
                nodes.insert(prev_node);
                q.push(prev_node);
            }
        }
    }
    
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> a >> b;

    linked_list.resize(n + 1);
    dist.resize(n + 1, inf);
    pre.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        linked_list[u].push_back({v, c});
        linked_list[v].push_back({u, c});
    }

    dijkstra(a);

    set<int> nodes;
    find_all_paths(b, nodes);

    cout << nodes.size() << endl;
    for (int node : nodes) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

//prov 31230
