#include "iostream"
#include "vector"
#include "queue"
#include "string"
#define endl '\n'
using namespace std;

int n, m;
vector<vector<int>> map;

void bfs() {
    int dy[] = {0, 0, -1, 1};
    int dx[] = {-1, 1, 0, 0};
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(2, false)));
    
    queue<tuple<int, int, int, bool>> q;
    q.push({0, 0, 1, true});
    visited[0][0][1] = true;

    while (!q.empty()) {
        int y, x, depth;
        bool wall_break;
        tie(y, x, depth, wall_break) = q.front();
        q.pop();

        if (y == n - 1 && x == m - 1) {
            cout << depth << endl;
            return;
        }

        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

            if (map[ny][nx] == 0 && !visited[ny][nx][wall_break]) {
                q.push({ny, nx, depth + 1, wall_break});
                visited[ny][nx][wall_break] = true;
            } else if (map[ny][nx] == 1 && wall_break && !visited[ny][nx][0]) {
                q.push({ny, nx, depth + 1, false});
                visited[ny][nx][0] = true;
            }
        }
    }

    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    map.resize(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        string line;
        cin >> line;

        for (int j = 0; j < m; ++j) {
            map[i][j] = line[j] - '0';
        }
    }

    bfs();

    return 0;
}

// prov 2206

//주안점
// 벽을 부순 상태와 부수지 않았을 때의 상태를 따로 관리해야 한다
