#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string input_string, goal_string;
    cin >> input_string >> goal_string;
    
    while (goal_string.size() > input_string.size()) {
        if (goal_string.back() == 'A') {
            goal_string.pop_back();  // 마지막 글자가 A면 그냥 제거
        }
        else if (goal_string.back() == 'B') {
            goal_string.pop_back();  // 마지막 글자가 B면 제거하고 뒤집기
            reverse(goal_string.begin(), goal_string.end());
        }
    }
    
    if (goal_string == input_string) {
        cout << 1 << endl;
    }
    else {
        cout << 0 << endl;
    }
    
    return 0;
}
