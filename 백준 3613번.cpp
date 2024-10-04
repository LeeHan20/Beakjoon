#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;

bool is_all_small (const string &word) {
    for (char ch : word) {
        if (ch > 96 && ch < 123) {
            return false;
        }
    }
    return true;
}

bool exclude_counterexample(const string &word) {
    //맨 앞 문자가 대문자면 에러
    if (word[0] > 64 && word[0] < 91) {
        return true;
    }
    
    //맨 앞 문자가 '_' 이면 에러
    if (word[0] == '_') {
        return true;
    }
    
    //맨 뒤 문자가 '_' 이면 에러
    if (word[word.size() - 1] == '_') {
        return true;
    }
    
    //'_' 연속 두개면 에러
    for (int i = 1; i < word.size(); ++i) {
        if (word[i - 1] == '_' && word[i] == '_') {
            return true;
        }
    }
    
    return false;
}



int number_of_big(const string &word) {
    int big_number = 0;
    for (char ch : word) {
        if (ch > 64 && ch < 91) {
            big_number++;
        }
    }
    return big_number;
}

int number_of_under_bar(const string &word) {
    int under_bar_number = 0;
    for (char ch : word) {
        if (ch == '_') {
            under_bar_number++;
        }
    }
    return under_bar_number;
}

bool isJavaStyle(const string &word) {
    //'_'가 있으면 안 됨
    for (char ch : word) {
        if (ch == '_') {
            return false;
        }
    }
    if (is_all_small(word)) {
        return false;
    }
    return true;
}

bool is_cpp_style(const string &word) {
    //대문자가 있으면 안 됨
    for (char ch : word) {
        if (ch > 64 && ch < 91) {
            return false;
        }
    }
    if (is_all_small(word)) {
        return false;
    }
    return true;
}

void javaToCpp(string &word) {
    //대문자까지 자르고 그 뒤도 자르고
    //그 사이에 _를 끼워서 +로 이어붙임
    unsigned long repeat =  word.size();
    repeat += number_of_big(word);
    for (int i = 0; i < repeat; ++i) {
        if (word[i] > 64 && word[i] < 91) {
            string before = word.substr(0, i);
            string after = word.substr(i + 1);
            string new_one = "_" + string(1, tolower(word[i]));
            word = before + new_one + after;
        }
    }
    
    cout << word << "\n";
    
    return;
}

void cpp_to_java(string &word) {
    //_가 나오면 그 뒤의 문자를 대문자로 변환
    //_는 빼고 앞, 뒤, 대문자를 이어붙임
    unsigned long repeat = word.size();
    repeat -= number_of_under_bar(word);
    for (int i = 0; i < repeat; ++i) {
        if (word[i] == '_') {
            string before = word.substr(0,i);
            string after = word.substr(i + 2);
            string new_one = string(1, toupper(word[i + 1]));
            word = before + new_one + after;
        }
    }
    
    cout << word << "\n";
    
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string word;
    cin >> word;
    
    if (exclude_counterexample(word)) {
        cout << "Error!" << "\n";
    }
    
    else if (is_all_small(word)) {
        cout << word << "\n";
    }
    
    else if (isJavaStyle(word)) {
        javaToCpp(word);
    }
    
    else if (is_cpp_style(word)) {
        cpp_to_java(word);
    }
    
    else {
        cout << "Error!" << "\n";
    }
    
    return 0;
}

