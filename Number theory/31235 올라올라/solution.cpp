#include "iostream"
#include "queue"
#include "vector"
#include "set"
#define endl "\n"
#define inf 10E16
using namespace std;

int n;
vector<int> vec;

bool is_upper(int k) {
    deque<int> dq;
    int current_max_value = 0;

    for (int i = 0; i < n; ++i) {
        if (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }

        while (!dq.empty() && vec[dq.back()] <= vec[i]) {
            dq.pop_back();
        }
        dq.push_back(i);

        if (i >= k - 1) {
            int boundary_max = vec[dq.front()];
            if (current_max_value < boundary_max) {
                current_max_value = boundary_max;
            } else if (current_max_value > boundary_max) {
                return false;
            }
        }
    }

    return true;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vec.resize(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    
    int mid, low = 1, high = n;
    
    while (low <= high) {
        mid = (high + low) / 2;
        
        if (is_upper(mid)) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    
    cout << low << endl;

    return 0;
}


// prov 31235

//N = 5

//K = 1; length = 5; loop = 5; search_boundary = 1;
//K = 2; length = 4; loop = 4; search_boundarty = 2;

//So, in general length of series b is n - k + 1, loop is same, boundary of search is k
