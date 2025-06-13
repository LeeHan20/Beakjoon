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
#include <set>
#define endl '\n'
#define space ' '
#define INF 2147483647
#define MAX 2501
using namespace std;
typedef long long ll;
//const long long INF = 1LL << 60;
//typedef __int128 ll;
//#define RANDRANGE(a,b) ((rand() % ((b)-(a))) + (a))

int n;
vector<vector<int>> grid;
vector<bool> antidiagonal_check;
int max_bishop = 0;

bool in_boundary(int y, int x) {
    
    return y >= 0 && y < n && x >= 0 && x < n;
}

void dfs(int row, int column, int bishop) {
    int check1 = row + column;
    int check2 = row - column + n - 1;
    
    max_bishop = max(max_bishop, bishop);
    if (!in_boundary(row, column)) return;
    
    if (bishop + (2 * n - 1) - check1 <= max_bishop) {
        return;
    }
    
    bool condi = grid[row][column] == 1 && antidiagonal_check[check2] == false;
    
//    cout << "row is " << row << " column is " << column << " bishop is " << bishop << endl;
    
    if (condi) {
        antidiagonal_check[check2] = true;
        
        if (check1 < n - 1) {
            dfs(check1 + 1, 0, bishop + 1);
        } else {
            dfs(n - 1, check1 - n + 2, bishop + 1);
        }
        
        antidiagonal_check[check2] = false;
    }
    
    if (column == n - 1) {
        dfs(n - 1, check1 - n + 2, bishop);
    } else if (row == 0) {
        dfs(check1 + 1, 0, bishop);
    } else {
        dfs(row - 1, column + 1, bishop);
    }
    
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    grid.resize(n, vector<int>(n, 0));
    antidiagonal_check.resize(2 * n - 1, false);
    // i - j + n - 1로 검사
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    
    dfs(0, 0, 0);
    
    cout << max_bishop << endl;

    return 0;
}
