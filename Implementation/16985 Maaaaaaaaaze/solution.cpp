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
//const long long INF = 1LL << 60;
//typedef __int128 ll;
//#define RANDRANGE(a,b) ((rand() % (b - a)) + (a))

vector<vector<vector<int>>> grid;
vector<vector<vector<int>>> temporary_field (5);
int n = 5;
int min_path = INF;

int dx[] = {0, 0, 0, 0, -1, 1};
int dy[] = {0, 0, -1, 1, 0, 0};
int dz[] = {-1, 1, 0, 0, 0, 0};

void roration(int platform) {
    
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < i; ++j) {
            swap(temporary_field[platform][i][j], temporary_field[platform][j][i]);
        }
    }
    
    reverse(temporary_field[platform].begin(), temporary_field[platform].end());
    
    return;
}

bool in_boundary(int x, int y, int z) {
    
    return x >= 0 && x < n && y >= 0 && y < n && z >= 0 && z < n;
}

int bfs() {
    if (temporary_field[0][0][0] != 1 || temporary_field[n-1][n-1][n-1] != 1) {
        return -1;
    }
    
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(n, vector<bool>(n, false)));
    queue<tuple<int, int, int, int>> q;
    
    visited[0][0][0] = true;
    q.push({0, 0, 0, 0});
    
    while (!q.empty()) {
        int x, y, z, depth;
        tie(x, y, z, depth) = q.front();
        q.pop();
        
        if (x == n - 1 && y == n - 1 && z == n - 1) return depth;
        
        for (int i = 0; i < 6; ++i) {
            int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
            
            if (!in_boundary(nx, ny, nz)) continue;
            if (temporary_field[nx][ny][nz] == 0) continue;
            if (visited[nx][ny][nz] == true) continue;
            
            visited[nx][ny][nz] = true;
            q.push({nx, ny, nz, depth + 1});
        }
    }
    
    return -1;
}

void claculate_cases() {
    
    for (int r0 = 0; r0 < 4; ++r0)
    for (int r1 = 0; r1 < 4; ++r1)
    for (int r2 = 0; r2 < 4; ++r2)
    for (int r3 = 0; r3 < 4; ++r3)
    for (int r4 = 0; r4 < 4; ++r4) {
        vector<int> rotation_command = {r0, r1, r2, r3, r4};
        vector<int> perm = {0, 1, 2, 3, 4};
        do {
            for (int i = 0; i < n; ++i) {
                temporary_field[i] = grid[perm[i]];
            }
            
            for (int i = 0; i < n; ++i) {
                int r = rotation_command[i];
                for (int j = 0; j < r; ++j) roration(i);
            }
            
            int current_path = bfs();
            if (min_path > current_path && current_path != -1) {
                min_path = current_path;
            }
        } while (next_permutation(perm.begin(), perm.end()));
    }

    
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    grid.resize(n, vector<vector<int>>(n, vector<int>(n)));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                cin >> grid[i][j][k];
            }
        }
    }
    
    claculate_cases();
    
    if (min_path == INF) {
        cout << -1 << endl;
    } else {
        cout << min_path << endl;
    }
    
    return 0;
}


