#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int sero, garo;
int max_depth = 0;
vector<string> field;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

inline bool inBoundary(int y, int x) {
    return (y >= 0 && y < sero && x >= 0 && x < garo);
}

void dfs(int y, int x, int visited, int depth) {
    max_depth = max(max_depth, depth);

    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (!inBoundary(ny, nx)) continue;
        
        int letterIndex = field[ny][nx] - 'A';
        
        if (visited & (1 << letterIndex)) continue;
        
        dfs(ny, nx, visited | (1 << letterIndex), depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> sero >> garo;
    field.resize(sero);
    
    for (int i = 0; i < sero; ++i) {
        cin >> field[i];
    }
    
    int initial = 1 << (field[0][0] - 'A');
    dfs(0, 0, initial, 1);
    
    cout << max_depth << "\n";
    return 0;
}
