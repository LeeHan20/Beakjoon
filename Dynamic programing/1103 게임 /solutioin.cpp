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
#define INF 2147483647
#define MAX 2501
using namespace std;
typedef long long ll;
//const long long INF = 1LL << 60;

int sero, garo;
vector<vector<int>> field;
vector<vector<int>> dp(51, vector<int>(51, -1));
// dp[y][x] = 여기에서 가장 많이 움직일 수 있는 값이 얼마냐
bool recursion_flag = false;

int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};

bool in_boundary(int y, int x) {
    
    return y >= 0 && y < sero && x >= 0 && x < garo;
}

int dfs(int y, int x, int depth) {
    if (dp[y][x] != -1) {
        return dp[y][x];
    }
    
    if (recursion_flag == true) return 0;
    if (depth > MAX) {
        recursion_flag = true;
        return 0;
    }
    
    int moving_ability = field[y][x];
    
//    cout << "y is " << y << " x is " << x << endl;
//    cout << "moving ability is " << moving_ability << endl;
    
    int branch = 1;
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i] * moving_ability;
        int nx = x + dx[i] * moving_ability;
        
//        cout << ny << ' ' << nx << endl;
        
        if (!in_boundary(ny, nx)) continue;
        if (field[ny][nx] == 'H' - '0') continue;
        
//        cout << "is working" << endl;
        
        int temp = dfs(ny, nx, depth + 1) + 1;
//        dp[ny][nx] = temp;
        
        branch = max(branch, temp);
    }
    
    dp[y][x] = branch;
    return branch;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> sero >> garo;
    
    field.resize(sero, vector<int>(garo));
    
    for (int i = 0; i < sero; ++i) {
        string line;
        cin >> line;
        
        for (int j = 0; j < garo; ++j) {
            field[i][j] = line[j] - '0';
        }
    }
    
    int ans = dfs(0, 0, 0);
    
    cout << (recursion_flag ? -1 : ans) << endl;
    
    return 0;
}

// prov

// (int) 'H' = 72
// 재귀 통제를 해야 함
