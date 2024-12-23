#include "iostream"
#include "vector"
#define endl "\n"
using namespace std;

vector<vector<int>> subordinate; // 부하 관계
vector<int> scores;
int n, m;

void dfs(int node, int accumulated) {
    scores[node] += accumulated;
    for (int child : subordinate[node]) {
        dfs(child, scores[node]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    subordinate.resize(n);
    scores.resize(n, 0);
    
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a != -1) {
            subordinate[a - 1].push_back(i);
        }
    }
    
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        scores[a - 1] += b;
    }
    
    dfs(0, 0);
    
    for (int i = 0; i < n; ++i) {
        cout << scores[i] << ' ';
    }
    cout << endl;
    
    return 0;
}

// prov 14267
