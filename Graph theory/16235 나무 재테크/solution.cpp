#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int N, M, K;
vector<vector<int>> bat; // 양분 저장 벡터
vector<vector<int>> addNutrients; // 매년 추가되는 양분
vector<vector<deque<int>>> trees; // 각 좌표에 있는 나무 나이들 (deque로 관리)

// 나무가 번식할 때 8방향으로 번식하기 위한 좌표 변화
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

// 범위 확인 함수
bool inBounds(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

// 봄과 여름: 나무가 양분을 먹고 자람, 양분이 부족한 나무는 죽어서 양분이 됨
void springAndSummer() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (trees[i][j].empty()) continue;

            deque<int> newTrees;  // 새로 자란 나무들
            int deadNutrients = 0; // 죽은 나무로부터 나오는 양분

            // 나이가 어린 나무부터 양분을 먹기 위해 deque을 순서대로 처리
            for (int age : trees[i][j]) {
                if (bat[i][j] >= age) {
                    bat[i][j] -= age;  // 나무가 양분을 먹음
                    newTrees.push_back(age + 1); // 나이 1 증가
                } else {
                    deadNutrients += age / 2; // 죽은 나무는 나이를 2로 나눈 양분을 제공
                }
            }

            trees[i][j] = newTrees; // 살아남은 나무들만 저장
            bat[i][j] += deadNutrients; // 죽은 나무가 제공한 양분 추가
        }
    }
}

// 가을: 나이가 5의 배수인 나무는 번식
void fall() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (trees[i][j].empty()) continue;

            for (int age : trees[i][j]) {
                if (age % 5 == 0) {
                    for (int d = 0; d < 8; ++d) {
                        int nx = i + dx[d];
                        int ny = j + dy[d];

                        if (inBounds(nx, ny)) {
                            trees[nx][ny].push_front(1); // 새로운 나무는 나이가 1인 상태로 앞에 추가
                        }
                    }
                }
            }
        }
    }
}

// 겨울: 추가 양분을 공급
void winter() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            bat[i][j] += addNutrients[i][j]; // 양분 추가
        }
    }
}

int main() {
    cin >> N >> M >> K;
    bat = vector<vector<int>>(N, vector<int>(N, 5));
    addNutrients = vector<vector<int>>(N, vector<int>(N));
    trees = vector<vector<deque<int>>>(N, vector<deque<int>>(N));

    // 각 땅에 추가될 양분 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> addNutrients[i][j];
        }
    }

    // 나무 정보 입력
    for (int i = 0; i < M; i++) {
        int x, y, age;
        cin >> x >> y >> age;
        trees[x - 1][y - 1].push_back(age); // 인덱스를 0 기반으로 맞춤
    }

    // K년 동안 봄-여름-가을-겨울 순환
    for (int year = 0; year < K; year++) {
        springAndSummer();
        fall();
        winter();
    }

    // 최종 나무 개수 계산
    int totalTrees = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            totalTrees += trees[i][j].size(); // 각 좌표에 있는 나무 개수 더하기
        }
    }

    cout << totalTrees << endl;

    return 0; 
}

//prov 16235

//시간초과 3번, 컴파일 에러 4번, 틀렸습니다 1번
