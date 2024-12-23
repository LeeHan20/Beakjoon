#include "iostream"
#include "tuple"
#include "queue"
#include "vector"
#include "deque"
#include "ranges"
#include "numeric"
#include "algorithm"
#include "unordered_map"
#define endl "\n"
using namespace std;

vector<vector<char>> map;
int sero, garo;
bool pretty_flag = true;

struct side {
    int y;
    int x;
};

void bfs(int y, int x) {
    int dy[] = {0, 0, -1, 1};
    int dx[] = {-1, 1, 0, 0};
    
    char focus_char = map[y][x];

    int min_y = y, max_y = y;
    int min_x = x, max_x = x;

    queue<pair<int, int>> q;
    q.push({y, x});
    map[y][x] = '.';

    vector<pair<int, int>> visited_cells;
    visited_cells.push_back({y, x});

    while (!q.empty()) {
        int focus_y = q.front().first;
        int focus_x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int new_y = focus_y + dy[i];
            int new_x = focus_x + dx[i];

            if (new_y >= 0 && new_y < sero && new_x >= 0 && new_x < garo && map[new_y][new_x] == focus_char) {
                q.push({new_y, new_x});
                map[new_y][new_x] = '.';
                visited_cells.push_back({new_y, new_x});
                
                if (new_y < y || new_x < x) {
                    pretty_flag = false;
                    return;
                }

                min_y = min(min_y, new_y);
                max_y = max(max_y, new_y);
                min_x = min(min_x, new_x);
                max_x = max(max_x, new_x);
            }
        }
    }

    for (const auto& cell : visited_cells) {
        int cell_y = cell.first;
        int cell_x = cell.second;

        if (cell_y < min_y || cell_y > max_y || cell_x < min_x || cell_x > max_x) {
            pretty_flag = false;
            return;
        }
    }

    for (int i = min_y; i <= max_y; ++i) {
        for (int j = min_x; j <= max_x; ++j) {
            if (map[i][j] != '.' && map[i][j] != focus_char) {
                pretty_flag = false;
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
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
            if (map[i][j] != '.') {
                bfs(i, j);
            }
        }
    }
    
    if (pretty_flag == true) {
        cout << "dd" << endl;
    }
    else {
        cout << "BaboBabo" << endl;
    }
    
    return 0;
}

// prov 26598

