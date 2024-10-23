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
    
    int loop;
    cin >> loop;
    
    int looped = 0;
    while (true) {
        if (looped == loop) {
            break;
        }
        
        string board;
        cin >> board;
        
        string password = "";
        int cursor = 0;
        
        for (int i = 0; i < board.size(); ++i) {
            //커서를 왼쪽으로 이동
            if (board[i] == '<') {
                if (cursor) {
                    cursor--;
                }
            }
            
            //커서를 오른쪽으로 이동
            else if (board[i] == '>') {
                 if (cursor < password.size()) {
                     cursor++;
                 }
            }
            
            //커서의 왼쪽에 있는 문자 하나를 지우고 커서를 왼쪽으로 이동
            else if (board[i] == '-') {
                if (cursor) {
                    string before = password.substr(0, cursor - 1);
                    string after = password.substr(cursor);
                    password = before + after;
                    cursor--;
                }
            }
            
            //문자를 커서 오른쪽에 생성하고 커서를 오른쪽으로 이동
            else {
                string before = password.substr(0, cursor);
                string new_one = string(1, board[i]);
                string after = password.substr(cursor);
                password = before + new_one + after;
                cursor++;
            }
        }
        
        cout << password << endl;
        
    
        
        looped++;
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

