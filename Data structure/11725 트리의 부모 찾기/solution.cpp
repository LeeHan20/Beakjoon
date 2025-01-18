#include "iostream"
#include "vector"
#include "queue"
#include "deque"
#include "string"
#include "stack"
#define endl '\n'
using namespace std;

int n;
vector<vector<int>> linked_list;
vector<int> result;

void bfs() {
    queue<pair<int, int>> q;
    
    q.push({0, 1});
    //grand parent, parent
    while (!q.empty()) {
        int grand_parent = q.front().first;
        int parent = q.front().second;
        q.pop();
        
        for (int i = 0; i < linked_list[parent].size(); ++i) {
            int child = linked_list[parent][i];
            
            if (child == grand_parent) continue;
            
            q.push({parent, child});
            result[child] = parent;

        }
    }
    
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    linked_list.resize(n + 1);
    result.resize(n + 1);
    
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        
        linked_list[a].push_back(b);
        linked_list[b].push_back(a);
    }
    
    bfs();
    
    for (int i = 2; i < n + 1; ++i) {
        cout << result[i] << endl;
    }

    return 0;
}

// prov


