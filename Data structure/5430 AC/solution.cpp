#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
#include <cmath>
#include <stack>
#include <cctype>
#include <queue>
#include <time.h>
#include <iomanip>
using namespace std;

int main() {
    int loop;
    cin >> loop;
        
    for (int looped = 0; looped < loop; ++looped) {
        string command;
        cin >> command;
        
        int number_arr;
        cin >> number_arr;
        
        string unprocessed_arr;
        cin >> unprocessed_arr;
        
        deque<int> arr;
        string temp = "";
        
        for (int i = 0; i < unprocessed_arr.size(); ++i) {
            if (isdigit(unprocessed_arr[i])) {
                temp += unprocessed_arr[i];
            } else if (unprocessed_arr[i] == ',' || unprocessed_arr[i] == ']') {
                if (!temp.empty()) {
                    arr.push_back(stoi(temp));
                    temp = "";
                }
            }
        }
        
        bool isReversed = false;
        bool errorOccurred = false;
        // 명령어를 쳐
        for (int i= 0; i < command.size(); ++i) {
            if (command[i] == 'R') {
                isReversed = !isReversed;
            } else if (command[i] == 'D') {
                if (arr.empty()) {
                    cout << "error" << "\n";
                    errorOccurred = true;
                    break;
                } else {
                    if (isReversed) {
                        arr.pop_back();
                    } else {
                        arr.pop_front();
                    }
                }
            }
        }
 
        if (!errorOccurred) {
            cout << '[';
            if (!arr.empty()) {
                if (isReversed) {
                    for (auto it = arr.rbegin(); it != arr.rend(); ++it) {
                        if (it != arr.rbegin()) cout << ',';
                        cout << *it;
                    }
                } else {
                    for (auto it = arr.begin(); it != arr.end(); ++it) {
                        if (it != arr.begin()) cout << ',';
                        cout << *it;
                    }
                }
            }
            cout << ']' << "\n";
        }
    }
    return 0;
}

//prov 5430

//대괄호와 comma, comma와 comma, comma와 대활호 사이의 두 자리 수 이상의 수를 고려해야 함

//신기하게도 stack, queue는 reverse가 없는데 deque은 반복자가 있음
//게다가 []접근도 가능함
//deque이거 그냥 성능이 미쳤음

//근데 reverse쓰면 시간초과 난다..

//처음 파싱 단계는 무난히 넘겼다고 쳐도
//reverse를 구현하는 단계에서 덱 특징을 잘 활용해야 함
