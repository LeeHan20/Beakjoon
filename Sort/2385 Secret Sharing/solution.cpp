#include "iostream"
#include "tuple"
#include "queue"
#include "vector"
#include "deque"
#include "ranges"
#include "numeric"
#define endl "\n"
using namespace std;

typedef long long ll;

bool cmp(string a, string b) {
    
    return a + b < b + a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    deque<string> numbers;
    
    for (int i = 0; i < n; ++i) {
        string a;
        cin >> a;
        numbers.push_back(a);
        
    }
    
    sort(numbers.begin(), numbers.end(), cmp);
    
    if (numbers[0][0] == '0') {
        
        
//        cout << "before sort : \n";
//        for (int i = 0; i < numbers.size(); ++i) {
//            cout << numbers[i] << ' ';
//        }
//        cout << endl;
        
        
        vector<string> connection_numbers;
               
        //가장 앞 자리가 0이 아닌 원소들에 대해서 그 원소들을 빼서 덱의 가장 앞에 뒀을 때 가장 작은 값이 되는 것을 찾아야 한다
        for (int i = 1; i < numbers.size(); ++i) {
            if (numbers[i][0] != '0') {
                deque<string> temp_numbers = numbers;
                
                string chosen = temp_numbers[i];
                temp_numbers.erase(temp_numbers.begin() + i);
                temp_numbers.push_front(chosen);
                       
                string temp_result = accumulate(temp_numbers.begin(), temp_numbers.end(), string(""));
                connection_numbers.push_back(temp_result);
            }
        }
               
        // 모든 가능한 연결 결과 중에서 가장 작은 것을 선택하여야 함
        if (!connection_numbers.empty()) {
            string min_result = *min_element(connection_numbers.begin(), connection_numbers.end());
//            cout << "after sort : \n";
//            for (int i = 0; i < numbers.size(); ++i) {
//                cout << numbers[i] << ' ';
//            }
//            cout << endl;
            cout << min_result << endl;
            return 0;
        } else {
            cout << "INVALID" << endl;
            return 0;
        }
    }
    else {
//        for (int i = 0; i < numbers.size(); ++i) {
//            cout << numbers[i] << endl;
//        }
        
        string result = accumulate(numbers.begin(), numbers.end(), string(""));
        cout << result << endl;
        return 0;
    }
    
    return 0;
}

// prov 2385
