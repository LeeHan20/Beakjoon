#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <stack>
#include "string"
#include "algorithm"
#define endl '\n'
#define space ' '
#define INF 2109999999
using namespace std;
typedef long long ll;
//const long long INF = 1LL << 60;
const long long MOD = 1000000007;

int T;

ll modMultiply(ll a, ll b) {
    __int128 res = a;
    res *= b;
    res %= MOD;
    return (long long)res;
}

void testCase() {
    int n;
    cin >> n;
    
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    
    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        pq.push(a);
    }
    
    ll energy = 1;
    
    while (pq.size() != 1) {
        ll silme1 = pq.top();
        pq.pop();
        ll silme2 = pq.top();
        pq.pop();
        
        ll currentSilme = silme1 * silme2;
        
        energy = modMultiply(energy, currentSilme);
        
        pq.push(currentSilme);
        
    }
    
    cout << energy << endl;
    
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;
    
    for (int i = 0; i < T; ++i) {
        testCase();
    }
    
    return 0;
}
