#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
#include <cmath>
#include <stack>
#include <cctype>
#include <queue>
#include <deque>
#include <time.h>
#include <iomanip>
using namespace std;

int main() {
    
    // int loop;
    // cin >> loop;
    
    // int looped = 0;
    // while (true) {
    //     if (looped == loop) {
    //         break;
    //     }
        
    //     string board;
    //     cin >> board;
        
    //     string password = "";
    //     int cursor = 0;
        
    //     for (int i = 0; i < board.size(); ++i) {
    //         //커서를 왼쪽으로 이동
    //         if (board[i] == '<') {
    //             if (cursor) {
    //                 cursor--;
    //             }
    //         }
            
    //         //커서를 오른쪽으로 이동
    //         else if (board[i] == '>') {
    //              if (cursor < password.size()) {
    //                  cursor++;
    //              }
    //         }
            
    //         //커서의 왼쪽에 있는 문자 하나를 지우고 커서를 왼쪽으로 이동
    //         else if (board[i] == '-') {
    //             if (cursor) {
    //                 string before = password.substr(0, cursor - 1);
    //                 string after = password.substr(cursor);
    //                 password = before + after;
    //                 cursor--;
    //             }
    //         }
            
    //         //문자를 커서 오른쪽에 생성하고 커서를 오른쪽으로 이동
    //         else {
    //             string before = password.substr(0, cursor);
    //             string new_one = string(1, board[i]);
    //             string after = password.substr(cursor);
    //             password = before + new_one + after;
    //             cursor++;
    //         }
    //     }
    //     cout << password << endl;
    //     looped++;
    // }

    
    int loop;
    cin >> loop;

    while (loop--) {
        string board;
        cin >> board;

        deque<char> left, right;
        for (char ch : board) {
            if (ch == '<') {
                if (!left.empty()) {
                    right.push_front(left.back());
                    left.pop_back();
                }
            }
            else if (ch == '>') {
                if (!right.empty()) {
                    left.push_back(right.front());
                    right.pop_front();
                }
            }
            else if (ch == '-') {
                if (!left.empty()) {
                    left.pop_back();
                }
            }
            else {
                left.push_back(ch);
            }
        }

        for (char ch : left) cout << ch;
        for (char ch : right) cout << ch;
        cout << endl;
    }
    
    return 0;
}


//prov 5397

//백터로 구현하던가 아니면 string으로 구현
//string이 더 편할 듯? -> 문자열 이어붙이기로 구현해보자
///< > 이동 - 백스페이스

/// <, >는 cursor를 움직이는데 cursor의 범위(0, password.size())를 넘으면 안 됨
//인덱스 고려 해야 함
//백스페이스는 cursor의 위치에 따라 새로 들어오는 board의 요소를 password에 이어붙임
//-> before, after, new로 이어붙이면 될 듯


//prov 5397

//첫 번째 방법인 문자열 이어붙이기로는 시작복잡도가 loop*n^2수준으로 매우매우 복잡하였음

//결국 stack, queue, deque 중 하나를 사용해야 시작복잡도를 해결 가능
//stack은 어려울 것 같고 queue나 deque를 사용해야 할 듯

//cursor를 이용하지 않고 cursor와 같은 기능을 할 수 있도록 두 개의 자료를 이용하여
//cusor의 왼쪽과 오른쪽을 나눠서 pop과 push를 할 수 있으면 좋겠음 -> deque사용

//for conprehension? 저거 표현하는 for문 이름이 있었는데 기억 안 남

