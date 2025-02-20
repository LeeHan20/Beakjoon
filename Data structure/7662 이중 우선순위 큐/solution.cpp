#include <iostream>
#include <vector>
#include <limits>
#include "queue"
#include "unordered_map"
#include "map"
#define endl '\n'
#define space ' '
#define inf 2109999999
using namespace std;
typedef long long ll;

int t;
 
void test_case() {
    int k;
    cin >> k;
    
    map<int, int> mymap;
    
    for (int i = 0; i < k; ++i) {
        char command;
        int number;
        cin >> command >> number;
        
        if (command == 'I') {
            mymap[number]++;
        }
        else if (command == 'D') {
            if (mymap.empty()) continue;
            if (number == 1) {
                auto it = prev(mymap.end());
                if (it->second == 1)
                    mymap.erase(it);
                else
                    it->second--;
            }
            else if (number == -1) {
                auto it = mymap.begin();
                if (it->second == 1)
                    mymap.erase(it);
                else
                    it->second--;
            }
        }
    }
    
    if (mymap.empty())
        cout << "EMPTY" << endl;
    else {
        int max_val = prev(mymap.end())->first;
        int min_val = mymap.begin()->first;
        cout << max_val << space << min_val << endl;
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> t;
    for (int i = 0; i < t; ++i) {
        test_case();
    }
    
    return 0;
}

// prov
