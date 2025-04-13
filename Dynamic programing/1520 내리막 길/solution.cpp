#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <stack>
#include "string"
#include "algorithm"
#include <string>
#define endl '\n'
#define space ' '
#define INF 2109999999
#define MAX 10001
using namespace std;
typedef long long ll;
//const long long INF = 1LL << 60;

int sero, garo;
vector<vector<int>> field;
vector<vector<int>> dp (501, vector<int>(501, -1));
// dp[sero][garo] = branch

int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};

bool in_boundary(int y, int x) {
    
    return y >= 0 && y < sero && x >= 0 && x < garo;
}

int dfs(int y, int x, int height) {
    if (dp[y][x] != -1) {
        return dp[y][x];
    }
    
    if (y == sero - 1 && x == garo - 1) {
        return 1;
    }
    
    int cnt = 0;
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (!in_boundary(ny, nx)) continue;
        int nheight = field[ny][nx];
        if (nheight >= height) continue;
        
        int temp =  dfs(ny, nx, nheight);
        dp[ny][nx] = temp;
        cnt += temp;
    }
    
    dp[y][x] = cnt;
    
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> sero >> garo;
    
    field.resize(sero, vector<int>(garo));
    
    for (int i = 0; i < sero; ++i) {
        for (int j = 0; j < garo; ++j) {
            cin >> field[i][j];
        }
    }
    
    int ans = dfs(0, 0, field[0][0]);
    
    cout << ans << endl;
    
    return 0;
}

// prov
