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
#define MAX 10007
using namespace std;
typedef long long ll;
//const long long INF = 1LL << 60;

int n;
vector<int> command;
int dp[100002][5][5];
// dp[index][left][right] = force

int find_similarity(int goal, int step) {
    int basic = 3;
    
    if (step == 0) {
        return 2;
    }
    
    if (step == goal) {
        return 1;
    }
    
    if (abs(step - goal) % 2 == 1) {
        return 3;
    } else {
        return 4;
    }

    return basic;
}

int recursion(int index, int left, int right) {
    if (dp[index][left][right] != 0) {
        return dp[index][left][right];
    }
    
    int goal = command[index];
    int force;
    
    if (index == n - 1) {
        force = min(find_similarity(goal, left), find_similarity(goal, right));
        dp[index][left][right] = force;
        return force;
    }
    
    int nforce = min(recursion(index + 1, goal, right) + find_similarity(goal, left), recursion(index + 1, left, goal) + find_similarity(goal, right));
    
    dp[index][left][right] = nforce;
    
    return nforce;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int input = 1;
    
    while (true) {
        cin >> input;
        
        if (input == 0) break;
        
        command.push_back(input);
    }
    
    n = (int)command.size();
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    int ans = recursion(0, 0, 0);
    
    cout << ans << endl;
    
    return 0;
}

// prov
