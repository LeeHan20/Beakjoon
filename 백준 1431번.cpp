#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isdecimal (char number) {
    
    vector<int> numbers = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    
    for (int i = 0; i < 10; ++i) {
        if (number == numbers[i]) {
            return true;
        }
    }
    return false;
}

int sum_of_numbers (string str) {
    int sum = 0;
    for (int i = 0; i < str.size(); ++i) {
        if (isdecimal(str[i])) {
            sum += (str[i] - '0');
        }
    }
    return sum;
}


bool compare(const string &a, const string &b) {
    if (a.size() == b.size()) {
        if (sum_of_numbers(a) == sum_of_numbers(b)) {
            return a < b;
        }
        else {
            return sum_of_numbers(a) < sum_of_numbers(b);
        }
    }
    else {
        return a.size() < b.size();
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int guitar_number;
    cin >> guitar_number;
    vector<string> serial_numebrs(guitar_number);
    
    for (int i = 0; i < guitar_number; ++i) {
        cin >> serial_numebrs[i];
    }
    
    sort(serial_numebrs.begin(), serial_numebrs.end(), compare);
    
    for (int i = 0; i < serial_numebrs.size(); ++i) {
        cout << serial_numebrs[i] << "\n";
    }
    
    return 0;
}

//백준 1431번

//sort함수의 사용을 배울 수 있다

//isdigit은 왜인지 모르겠는데 다 걸러버려서 믿을 수가 없다
//isdecimal 굿굿
