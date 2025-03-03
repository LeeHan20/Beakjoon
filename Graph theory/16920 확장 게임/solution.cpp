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

int sero, garo, p;
vector<vector<char>> field;
vector<int> move_ability;
queue<pair<int, int>> q;

int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};

bool in_boundary(int y, int x) {
    
    return y >= 0 && y < sero && x >= 0 && x < garo;
}

void semi_bfs(queue<tuple<int, int, int>>& nq, const int& castle) {
    
    while (!nq.empty()) {
        int ny, nx, nability;
        tie(ny, nx, nability) = nq.front();
        nq.pop();
        
        if (nability == 0) {
            q.push({ny, nx});
            continue;
        }
        
//        for (int i = 0; i < sero; ++i) {
//            for (int j = 0; j < garo; ++j) {
//                cout << field[i][j];
//            }
//            cout << endl;
//        }
//        cout << endl;
        
        for (int i = 0; i < 4; ++i) {
            int nny = ny + dy[i];
            int nnx = nx + dx[i];
            
            if (!in_boundary(nny, nnx) || field[nny][nnx] != '.') continue;
            field[nny][nnx] = castle + '0';
            nq.push({nny, nnx, nability - 1});
        }
    }
    
    return;
}

void bfs() {
    
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        int castle = field[y][x] - '0';
        int ability = move_ability[castle];
        q.pop();
        
        queue<tuple<int, int, int>> nq;
        nq.push({y, x, ability});
        
        while (!q.empty() && castle == field[q.front().first][q.front().second] - '0') {
            nq.push({q.front().first, q.front().second, ability});
            q.pop();
        }
//        cout << "is work" << endl;
        
        semi_bfs(nq, castle);
    }
    
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> sero >> garo >> p;
    
    field.resize(sero, vector<char>(garo));
    move_ability.resize(p + 1);
    
    for (int i = 1; i < p + 1; ++i) cin >> move_ability[i];
    
    vector<vector<pair<int, int>>> locations(p + 1);
    
    for (int i = 0; i < sero; ++i) {
        string line;
        cin >> line;
        
        for (int j = 0; j < garo; ++j) {
            field[i][j] = line[j];
            if (field[i][j] != '.' && field[i][j] != '#') {
                locations[field[i][j] - '0'].push_back({i, j});
            }
        }
    }
    
    for (int i = 1; i < p + 1; ++i) for (auto next : locations[i]) q.push(next);
    
    bfs();
    
    vector<int> result(p + 1, 0);
    
    for (int i = 0; i < sero; ++i) {
        for (int j = 0; j < garo; ++j) {
            if (field[i][j] == '#' || field[i][j] == '.') continue;
            result[field[i][j] - '0']++;
        }
    }
    
    for (int i = 1; i < p + 1; ++i) cout << result[i] << ' ';
    cout << endl;

    return 0;
}

// prov

