#include "iostream"
#include "vector"
#define endl '\n'
using namespace std;

typedef long long ll;

int n;
vector<int> stairs;
vector<ll> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    stairs.resize(n + 1);
    dp.resize(n + 1, 0);
    
    for (int i = 1; i <= n; ++i) {
        cin >> stairs[i];
    }
    
    dp[1] = stairs[1];
    if (n > 1) {
        dp[2] = stairs[1] + stairs[2];
    }
    
    for (int i = 3; i <= n; ++i) {
        dp[i] = max(dp[i - 2], dp[i - 3] + stairs[i - 1]) + stairs[i];
    }
    
    cout << dp[n] << endl;
    return 0;
}
