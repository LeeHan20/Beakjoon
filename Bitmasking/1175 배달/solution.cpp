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
#include "signal.h"
#define endl '\n'
#define space ' '
#define INF 2147483647
#define MAX 2501
using namespace std;
typedef long long ll;
//const long long INF = 1LL << 60;
//typedef __int128 ll;

int sero, garo;
vector<vector<char>> grid;
vector<vector<int>> location_id;
int visited[1 << 2][4][51][51];
// visited[mask][ditection][y][x]

bool in_boundary(int y, int x) {
    
    return y >= 0 && y < sero && x >= 0 && x < garo;
}

void bfs(int sy, int sx) {
    int dy[4] = {0, 0, -1, 1};
    int dx[4] = {-1, 1, 0, 0};
    
    queue<tuple<int, int, int, int, int>> q;
    // mask, direction, y, x, depth
    
    q.push({0, 4, sy, sx, 0});
    
    while (!q.empty()) {
        int mask, direction, y, x, depth;
        tie(mask, direction, y, x, depth) = q.front();
        q.pop();
        
        if (mask == (1 << 2) - 1) {
            cout << depth << endl;
            return;
        }
        
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (direction == i || !in_boundary(ny, nx) || grid[ny][nx] == '#') continue;
            
            int nmask = mask;
            if (grid[ny][nx] == 'C') {
                int id = location_id[ny][nx];
                nmask |= (1 << id);
            }

            if (visited[nmask][i][ny][nx]) continue;
            visited[nmask][i][ny][nx] = true;
            q.push({nmask, i, ny, nx, depth + 1});
        }
    }
    
    cout << -1 << endl;
    
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> sero >> garo;
    grid.resize(sero, vector<char>(garo));
    location_id.resize(sero, vector<int>(garo, -1));
    
    int sy = 0, sx = 0;
    int plus_mask = 0;
    
    for (int i = 0; i < sero; ++i) {
        string line;
        cin >> line;
        for (int j = 0; j < garo; ++j) {
            grid[i][j] = line[j];
            
            if (line[j] == 'S') {
                sy = i;
                sx = j;
            }
            
            if (grid[i][j] == 'C') location_id[i][j] = plus_mask++;
        }
    }
    
    bfs(sy, sx);
    
    return 0;
}

// prov
