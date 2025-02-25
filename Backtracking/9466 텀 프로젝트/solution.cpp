#include <iostream>
#include <vector>
#include <limits>
#include "queue"
#include "unordered_map"
#include "map"
#include "cmath"
#include "stack"
#include "algorithm"
#define endl '\n'
#define space ' '
#define inf 2109999999
using namespace std;
typedef long long ll;

int t;
vector<int> field;
vector<int> visited;
// 0이면 방문 안 함, 1이면 팀이 정해졌음, 2면 팀에 속하지 못하였음
vector<bool> progress_visit;
vector<int> progress;

void recursive_exploration(int node) {
    if (visited[node] != 0) return;
    
    visited[node] = 2;
    progress_visit[node] = true;
    progress.push_back(node);
    
    int designation = field[node];
    if (node == designation) {
        visited[node] = 1;
        return;
    }
    
    bool in_progress_designated = progress_visit[designation];
    
    if (in_progress_designated == true) {
        bool team_make = false;
        
        for (int teammate : progress) {
            if (teammate == designation) team_make = true;
            if (team_make == false) continue;
            
            visited[teammate] = 1;
        }
        return;
    }
    
    recursive_exploration(designation);
    
    return;
}

void test_case() {
    int n;
    cin >> n;
    
    field.assign(n + 1, 0);
    visited.assign(n + 1, 0);
    
    for (int i = 1; i < n + 1; ++i) cin >> field[i];
    
    for (int i = 1; i < n + 1; ++i) {
        if (visited[i] != 0) continue;
        
        progress_visit.assign(n + 1, false);
        progress.clear();
        
        recursive_exploration(i);
    }
    
    int out_of_group = 0;
    for (int i = 1; i < n + 1; ++i) if (visited[i] != 1) out_of_group++;
    
    cout << out_of_group << endl;
    
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> t;
    
    for (int i = 0; i < t; ++i) test_case();
    
    return 0;
}

// prov
