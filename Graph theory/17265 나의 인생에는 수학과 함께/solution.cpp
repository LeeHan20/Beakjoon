#include "iostream"
#include "queue"
#include "vector"
#include "cctype"
#define endl "\n"
using namespace std;

vector<vector<char>> map;
int n;
int max_value = -9999999;
int min_value = 9999999;

int dy[] = {0, 1};
int dx[] = {1, 0};

int operation(int a, int b, char oper) {
    switch (oper) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        default: return a;
    }
}

void bfs() {
    queue<tuple<int, int, int, char>> q; 
    // (y, x, current_value, last_operator)
    q.push({0, 0, map[0][0] - '0', '+'});
    
    while (!q.empty()) {
        int y, x, current_value;
        char last_operator;
        tie(y, x, current_value, last_operator) = q.front();
        q.pop();
        
        if (y == n - 1 && x == n - 1) {
            max_value = max(max_value, current_value);
            min_value = min(min_value, current_value);
            continue;
        }
        
        for (int i = 0; i < 2; ++i) {
            int new_y = y + dy[i];
            int new_x = x + dx[i];
            
            if (new_y < n && new_x < n) {
                if (isdigit(map[new_y][new_x])) {
                    int new_value = operation(current_value, map[new_y][new_x] - '0', last_operator);
                    q.push({new_y, new_x, new_value, last_operator});
                } else {
                    q.push({new_y, new_x, current_value, map[new_y][new_x]});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    map.resize(n, vector<char>(n));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> map[i][j];
        }
    }
    
    bfs();
    
    cout << max_value << " " << min_value << endl;
    return 0;
}

// prov 17265
