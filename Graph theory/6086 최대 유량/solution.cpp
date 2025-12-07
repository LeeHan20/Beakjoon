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
#include "map"
#include <set>
#define endl '\n'
#define space ' '
#define INF 2147483647
#define MAX 2501
using namespace std;
typedef long long ll;

int capacity[52][52];
int flow[52][52];
vector<int> graph[52];

int s = 0; // 'A'
int t = 25; // 'Z'

int idxFromChar(char ch) {
    if (ch >= 'A' && ch <= 'Z') return ch - 'A';
    if (ch >= 'a' && ch <= 'z') return 26 + (ch - 'a');
    return -1; // invalid
}

bool bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    queue<int> q;
    q.push(s);
    parent[s] = -2; // source marker
    int N = 52;
    vector<int> minCap(N, 0);
    minCap[s] = INF;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : graph[u]) {
            int residual = capacity[u][v] - flow[u][v];
            if (parent[v] == -1 && residual > 0) {
                parent[v] = u;
                minCap[v] = min(minCap[u], residual);
                if (v == t) {
                    return true; // found path; minCap[t] is available via parent tracing if needed
                }
                q.push(v);
            }
        }
    }
    return false;
}

int edmonds_karp(int s, int t) {
    int total = 0;
    vector<int> parent(52);
    while (bfs(s, t, parent)) {
        // find bottleneck
        int bottleneck = INF;
        int v = t;
        while (v != s) {
            int u = parent[v];
            int residual = capacity[u][v] - flow[u][v];
            bottleneck = min(bottleneck, residual);
            v = u;
        }
        // augment
        v = t;
        while (v != s) {
            int u = parent[v];
            flow[u][v] += bottleneck;
            flow[v][u] -= bottleneck;
            v = u;
        }
        total += bottleneck;
    }
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        char a, b;
        int c;
        cin >> a >> b >> c;

        int u = idxFromChar(a);
        int v = idxFromChar(b);
        if (u == -1 || v == -1) {
            // 잘못된 노드 라벨은 무시하거나 에러 처리
            continue;
        }
        capacity[u][v] += c; // 중복 간선 누적
        capacity[v][u] += c; // 양방향 용량 동일
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << edmonds_karp(s, t) << endl;

    return 0;
}
