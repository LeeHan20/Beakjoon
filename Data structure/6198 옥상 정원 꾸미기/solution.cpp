#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int main() {
    int building_number;
    cin >> building_number;
    
    vector<long long> heights(building_number);
    for (int i = 0; i < building_number; ++i) {
        cin >> heights[i];
    }
    
    long long sum_of_can_see = 0;
    stack<int> st;
    
    for (int i = 0; i < building_number; ++i) {
        while (!st.empty() && heights[st.top()] <= heights[i]) {
            st.pop();
        }
        sum_of_can_see += st.size();
        st.push(i);
    }
    
    cout << sum_of_can_see << endl;
    
    return 0;
}
