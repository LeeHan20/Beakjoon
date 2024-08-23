// 8/23 깃허브 코드

#include <iostream>
using namespace std;

const int MOD = 1000000;
//1000000을 계속 쓰기 귀찮으니 모듈러를 하나 정의함
//이렇게 하라는데 솔직히 그냥 1000000 계속 쓰는 것도 그리 불편하지 않을 듯

int main() {
    int semester_days;
    cin >> semester_days;

    int dp[1001][2][3] = {};
    //dp[일 수][지각의 개수][연속하는 결석의 수]
    dp[1][0][0] = 1; // 출석
    dp[1][1][0] = 1; // 지각
    dp[1][0][1] = 1; // 결석
    //현하킴 교수님식 초기값 설정

    for (int i = 2; i <= semester_days; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                dp[i][j][0] = (dp[i][j][0] + dp[i-1][j][k]) % MOD;
                //출력에서 mod로 나누라고 했는데 어차피 몫연산이라 계속 확인해도 상관없음
            }
        }
        //출석

        for (int k = 0; k < 3; ++k) {
            dp[i][1][0] = (dp[i][1][0] + dp[i-1][0][k]) % MOD;
        }
        //지각

        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                dp[i][j][k+1] = (dp[i][j][k+1] + dp[i-1][j][k]) % MOD;
            }
        }
        //결석
    }

    int result = 0;
    for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 3; ++k) {
            result = (result + dp[semester_days][j][k]) % MOD;
        }
    }

    cout << result << endl;
    //'\n' 쓸 필요 없음

    return 0;
}

//백준 1563번

//또 dp 문제

//티어가 높아질수록 컴퓨터과학에 가깝게 접근하는 문제가 많아지는 것 같다
//틀만 짜놓고 세밀한 인덱스 설정은 gpt에 맡기는 편이 정신건강에 좋다
