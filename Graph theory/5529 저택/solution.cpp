#include <iostream>
#include <vector>
#include <limits>
#include "queue"
#define endl '\n'
#define space ' '
//#define INF 2109999999
using namespace std;
typedef long long ll;

const long long INF = 1LL << 60;

int M, N, K;
vector<vector<pair<int,int>>> field_row;
vector<vector<pair<int,int>>> field_col;
vector<ll> dist;
vector<pair<int,int>> swc;

void dijkstra() {
    typedef tuple<ll, int, int, bool> State;
    priority_queue<State, vector<State>, greater<State>> pq;
    
    pq.push({0, 0, 0, false});
    
    while (!pq.empty()) {
        ll curTime;
        int r, c;
        bool door;
        // 0 -> 세로이동, 1 -> 가로이동
        tie(curTime, r, c, door) = pq.top();
        pq.pop();
        
        if (r == N - 1 && c == M - 1) {
            cout << curTime << endl;
            return;
        }
        
        if (!door) {
            int curRow = r;
            for (auto &p : field_col[c]) {
                int nr = p.first;
                int idx = p.second;
                ll moveCost = abs(curRow - nr);
                ll newTime = curTime + moveCost;
                
                if (idx != K) {
                    newTime += 1;
                    if (dist[idx] <= newTime - 1) continue;
                    dist[idx] = newTime - 1;
                    int newR = swc[idx].first, newC = swc[idx].second;
                    // 세로 -> 가로
                    pq.push({newTime, newR, newC, true});
                } else {
                    // case destination
                    if (dist[idx] <= newTime) continue;
                    dist[idx] = newTime;
                    int newR = swc[idx].first, newC = swc[idx].second;
                    pq.push({newTime, newR, newC, false});
                }
            }
        }
        
        else {
            int curCol = c;
            for (auto &p : field_row[r]) {
                int nc = p.first;
                int idx = p.second;
                ll moveCost = abs(curCol - nc);
                ll newTime = curTime + moveCost;
                
                if (idx != K) {
                    newTime += 1;
                    if (dist[idx] <= newTime - 1) continue;
                    dist[idx] = newTime - 1;
                    int newR = swc[idx].first, newC = swc[idx].second;
                    pq.push({newTime, newR, newC, false});
                } else {
                    if (dist[idx] <= newTime) continue;
                    dist[idx] = newTime;
                    int newR = swc[idx].first, newC = swc[idx].second;
                    pq.push({newTime, newR, newC, true});
                }
            }
        }
    }
    
    cout << -1 << endl;
    
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> M >> N >> K;
    field_row.resize(N);
    field_col.resize(M);
    dist.resize(K + 1, INF);
    swc.reserve(K + 1);
    
    for (int i = 0; i < K; i++){
        int x, y;
        cin >> x >> y;
        field_row[y - 1].push_back({x - 1, i});
        field_col[x - 1].push_back({y - 1, i});
        swc.push_back({y - 1, x - 1});
    }
    
    field_row[N - 1].push_back({M - 1, K});
    field_col[M - 1].push_back({N - 1, K});
    swc.push_back({N - 1, M - 1});
    
    dijkstra();
    
    return 0;
}

// prov
