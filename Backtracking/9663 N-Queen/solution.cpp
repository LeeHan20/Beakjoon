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
vector<vector<bool>> grid;
int ans = 0;
vector<bool> horizontal_check;
vector<bool> diagonal_check;
vector<bool> antidiagonal_check;

void dfs(int row, int column) {
    if (column >= n) {
        return;
    }
    
    int check1 = column;
    int check2 = row + column;
    int check3 = row - column + n - 1;
    
    bool holding_flag = (!horizontal_check[check1] && !diagonal_check[check2] && !antidiagonal_check[check3]);
    
    if (holding_flag) {
        if (row == n - 1) {
            ans++;
            return;
        }
        
        horizontal_check[column] = true;
        diagonal_check[row + column] = true;
        antidiagonal_check[row - column + n - 1] = true;
        
        dfs(row + 1, 0);
        
        horizontal_check[column] = false;
        diagonal_check[row + column] = false;
        antidiagonal_check[row - column + n - 1] = false;
    }
    
    dfs(row, column + 1);
    
//    if (horizontal_check[column] == true && column < n) {
//        dfs(row, column + 1);
//    } else {
//        horizontal_check[column] = true;
//        diagonal_check[row + column] = true;
//        antidiagonal_check[row - column + n - 1] = true;
//        dfs(row + 1, 0);
//    }
    
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    grid.resize(n, vector<bool>(n, false));
    horizontal_check.resize(n);
    diagonal_check.resize(2 * n - 1, false);
    antidiagonal_check.resize(2 * n - 1, false);
    
    dfs(0, 0);
    
    cout << ans << endl;

    return 0;
}
