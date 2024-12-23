#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#define endl "\n"
using namespace std;

int n, k, s, x, y;
vector<vector<int>> lab;
vector<tuple<int, int, int, int>> viruses; // (virus, time, x, y)

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void bfs() {
    queue<tuple<int, int, int, int>> q; // (virus, time, x, y)
    for (auto v : viruses) {
        q.push(v);
    }

    while (!q.empty()) {
        int virus, time, cx, cy;
        tie(virus, time, cx, cy) = q.front();
        q.pop();

        if (time == s) break;

        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && lab[nx][ny] == 0) {
                lab[nx][ny] = virus;
                q.push(make_tuple(virus, time + 1, nx, ny));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    lab.resize(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> lab[i][j];
            if (lab[i][j] != 0) {
                viruses.push_back(make_tuple(lab[i][j], 0, i, j));
            }
        }
    }

    cin >> s >> x >> y;

    sort(viruses.begin(), viruses.end());

    bfs();

    cout << lab[x - 1][y - 1] << endl;

    return 0;
}
