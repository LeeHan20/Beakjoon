#include "iostream"
#include "vector"
#include "queue"
#include "string"
#include "stack"
#define endl '\n'
using namespace std;

int n;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<int> top(n);
    vector<int> result(n);
    stack<pair<int, int>> accumulated_numbers;
    //index, height
    
    for (int i = 0; i < n; ++i) {
        cin >> top[i];
    }
    
    accumulated_numbers.push({0, top[0]});
    result[0] = 0;
    
    for (int i = 1; i < n; ++i) {
        int focus_number = top[i];
        
        if (accumulated_numbers.top().second < focus_number) {
            
            while (true) {
                
                if (accumulated_numbers.empty()) {
                    result[i] = 0;
                    accumulated_numbers.push({i, focus_number});
                    break;
                }
                
                if (accumulated_numbers.top().second < focus_number) {
                    accumulated_numbers.pop();
                }
                else  if (accumulated_numbers.top().second > focus_number) {
                    result[i] = accumulated_numbers.top().first + 1;
                    //1-base index
                    accumulated_numbers.push({i, focus_number});
                    break;
                }
                else {
                    result[i] = accumulated_numbers.top().first + 1;
                    //1-base index
                    accumulated_numbers.pop();
                    accumulated_numbers.push({i, focus_number});
                    break;
                }
                
            }
            
        }
        else {
            result[i] = accumulated_numbers.top().first + 1;
            //1-base index
            accumulated_numbers.push({i, focus_number});
        }
    }
    
    for (int i = 0; i < n; ++i) {
        cout << result[i] << ' ';
    }
    cout << endl;

    return 0;
}

// prov


