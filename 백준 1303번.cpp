// 8/30 깃허브 코드

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int N, M;
//전역 변수 선언
//백터로 이렇게 선언하고 싶지만 백터의 사이즈를 정해주는 과정에서 M의 값이 필요하기 때문에 인자의 형태로 전달함
//많은 파일을 가지고 작업할 때 다른 파일에서도 이 전역변수를 사용하고 싶다면 앞에 extern을 붙이고
//다른 파일에서의 사용을 제한하고 싶다면 앞에 static을 붙임
//static int N, M;

int result = 0;

void recursive_exploration(vector<vector<pair<char, int>>> &battlefield, int dx, int dy, char team) {
    battlefield[dy][dx].second = 1;
    result += 1;
    
    if (dx > 0 && battlefield[dy][dx - 1].second == 0 && battlefield[dy][dx - 1].first == team) {
        recursive_exploration(battlefield, dx - 1, dy, team);
    }
    if (dy > 0 && battlefield[dy - 1][dx].second == 0 && battlefield[dy - 1][dx].first == team) {
        recursive_exploration(battlefield, dx, dy - 1, team);
    }
    if (dx < N - 1 && battlefield[dy][dx + 1].second == 0 && battlefield[dy][dx + 1].first == team) {
        recursive_exploration(battlefield, dx + 1, dy, team);
    }
    if (dy < M - 1 && battlefield[dy + 1][dx].second == 0 && battlefield[dy + 1][dx].first == team) {
        recursive_exploration(battlefield, dx, dy + 1, team);
    }
    //indexerror가 나지 않는 범위에서 네 방향을 향해 재귀적으로 탐사함
    return;
}

int main() {
    cin >> N >> M;
    vector<vector<pair<char, int>>> battlefield(M, vector<pair<char, int>>(N));
    
    for (int i = 0; i < M; ++i) {
        string line;
        cin >> line;
        for (int j = 0; j < N; ++j) {
            battlefield[i][j].first = line[j];
            battlefield[i][j].second = 0;
        }
    }
    //line 단위로 쪼개서 입력을 받은 후 line의 각각의 요소를 vector에 할당하는 방식
    //알파벳을 하나하나 쪼개서 받고 싶을 때 좋다

    int W_power_counter = 0;
    int B_power_counter = 0;
    
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (battlefield[i][j].second == 0) {
                result = 0;
                recursive_exploration(battlefield, j, i, battlefield[i][j].first);
                if (battlefield[i][j].first == 'W') {
                    W_power_counter += result * result;
                } else if (battlefield[i][j].first == 'B') {
                    B_power_counter += result * result;
                }
            }
        }
    }
    
    cout << W_power_counter << " " << B_power_counter << endl;
    return 0;
}

//백준 1303번
