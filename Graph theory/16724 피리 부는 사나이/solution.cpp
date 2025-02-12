#include <iostream>
#include <vector>
#include <string>
using namespace std;

int sero, garo;
int group_cnt = 0;
vector<vector<char>> field;
vector<vector<int>> state;

pair<int, int> execute_command(int current_y, int current_x, char command) {
    int ny = current_y, nx = current_x;
    switch (command) {
        case 'L':
            nx = current_x - 1;
            break;
        case 'R':
            nx = current_x + 1;
            break;
        case 'U':
            ny = current_y - 1;
            break;
        case 'D':
            ny = current_y + 1;
            break;
    }
    return {ny, nx};
}

void dfs(int y, int x) {
    state[y][x] = 1;
    auto next = execute_command(y, x, field[y][x]);
    int ny = next.first, nx = next.second;
    
    if (state[ny][nx] == 0) {
        dfs(ny, nx);
    }
    else if (state[ny][nx] == 1) {
        group_cnt++;
    }
    
    state[y][x] = 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> sero >> garo;
    field.resize(sero, vector<char>(garo));
    state.resize(sero, vector<int>(garo, 0));
    
    for (int i = 0; i < sero; ++i) {
        string line;
        cin >> line;
        for (int j = 0; j < garo; ++j) {
            field[i][j] = line[j];
        }
    }
    
    for (int i = 0; i < sero; ++i) {
        for (int j = 0; j < garo; ++j) {
            if (state[i][j] == 0) {
                dfs(i, j);
            }
        }
    }
    
    cout << group_cnt << "\n";
    return 0;
}

