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

#include "iostream"
#include "vector"
#define endl "\n"
using namespace std;

vector<int> seq;
vector<bool> used;
int n, m;

void make_seq(int depth, int last_iter) {
    if (depth == m) {
        for (int i = 0; i < m; i++) {
            cout << seq[i] << ' ';
        }
        cout << endl;
        return;
    }

    for (int i = last_iter; i <= n; i++) {
        if (used[i - 1] == true) {
            continue;
        }

        seq[depth] = i;
        used[i - 1] = true;

        make_seq(depth + 1, i + 1);
        used[i - 1] = false;
    }

    return;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    seq.resize(m);
    used.resize(n);

    make_seq(0, 1);

    return 0;
}

// prov 15650
