#include "iostream"
#include "vector"
#include "string"
#include "stack"
using namespace std;

int find_priority(char a) {
    if (a == '+' || a == '-') {
        return 1;
    }
    else if (a == '*' || a == '/') {
        return 2;
    }
    else {
        return 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string formula;
    cin >> formula;
    
    stack<char> st;
    vector<char> result_formula;
    
    for (int i = 0; i < formula.size(); ++i) {
        char focus_char = formula[i];
        
        if (isalpha(focus_char)) {
            result_formula.push_back(focus_char);
        }
        else if (focus_char == '(') {
            st.push(focus_char);
        }
        else if (focus_char == ')') {
            while (!st.empty() && st.top() != '(') {
                result_formula.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else {
            int current_priority = find_priority(focus_char);
            while (!st.empty() && find_priority(st.top()) >= current_priority) {
                result_formula.push_back(st.top());
                st.pop();
            }
            st.push(focus_char);
        }
    }
    
    while (!st.empty()) {
        result_formula.push_back(st.top());
        st.pop();
    }
    
    for (int i = 0; i < result_formula.size(); ++i) {
        cout << result_formula[i];
    }
    cout << endl;
    
    return 0;
}
