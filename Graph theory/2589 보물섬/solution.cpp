#include "iostream"
#include "tuple"
#include "queue"
#include "vector"
#include "deque"
#define endl "\n"
using namespace std;

int sero, garo;
int real_max_depth = 0;

void bfs(int y, int x, vector<vector<char>> map) {
    int dy[] = {0, 0, -1, 1};
    int dx[] = {-1, 1, 0, 0};
    int max_depth = 0;
    
    //y, x, depth
    queue<tuple<int, int, int>> q;
    q.push({y, x, 0});
    map[y][x] = 'W';
    
    while (!q.empty()) {
        int focus_y, focus_x, current_depth;
        tie(focus_y, focus_x, current_depth) = q.front();
        q.pop();
        
        if (max_depth < current_depth) {
            max_depth = current_depth;
        }
        
        for (int i = 0; i < 4; ++i) {
            int new_y = focus_y + dy[i];
            int new_x = focus_x + dx[i];
            
            if (new_y >= 0 && new_y < sero && new_x >= 0 && new_x < garo && map[new_y][new_x] == 'L') {
                q.push({new_y, new_x, current_depth + 1});
                map[new_y][new_x] = 'W';
            }
        }
    }
    
    if (real_max_depth < max_depth) {
        real_max_depth = max_depth;
    }
    
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<vector<char>> map;

    cin >> sero >> garo;
    
    map.resize(sero, vector<char>(garo));
    
    for (int i = 0; i < sero; ++i) {
        string line;
        cin >> line;
        
        for (int j = 0; j < garo; ++j) {
            map[i][j] = line[j];
        }
    }
    
    for (int i = 0; i < sero; ++i) {
        for (int j = 0; j < garo; ++j) {
            if (map[i][j] == 'L') {
                bfs(i, j, map);
            }
        }
    }
    
    cout << real_max_depth << endl;

    
    return 0;
}

// prov 2589
