#include "iostream"
#include "tuple"
#include "queue"
#include "vector"
#include "deque"
#include "ranges"
#include "numeric"
#include "algorithm"
#include "unordered_map"
#define endl "\n"
using namespace std;

vector<int> seq;
vector<bool> used;
int n, m;

void make_seq(int pt) {

    if (pt == m) {
        for (int i = 0; i < m; i++) {
            cout << seq[i] << ' ';
        }
        cout << endl;
        return;
    }
    for (int i = 1; i < n + 1; i++) {
        if (used[i - 1] == true) {
            continue;
        }
        
        seq[pt] = i;
        used[i - 1] = true;
        
        make_seq(pt + 1);

        used[i - 1] = false;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    
    seq.resize(m);
    used.resize(n + 1);

    make_seq(0);

    return 0;
}

// prov 15649
