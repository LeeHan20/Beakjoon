#include "iostream"
#include "tuple"
#include "queue"
#include "vector"
#include "deque"
#include "ranges"
#include "numeric"
#include "algorithm"
#include "unordered_map"
#define endl "\n"
using namespace std;

//치즈 유무, 외부 공기 접촉횟수, 방문 여부
vector<vector<int>> map;
vector<vector<int>> exterior_count;
vector<vector<bool>> visited;
int sero, garo;

//치즈 존재 여부
bool cheese_existence() {
    
    for (int i = 0; i < sero; ++i) {
        for (int j = 0; j < garo; ++j) {
            if (map[i][j] == 1) {
                return true;
            }
        }
    }
    
    return false;
}

void bfs(int y, int x) {
    int dy[] = {0, 0, -1, 1};
    int dx[] = {-1, 1, 0, 0};
    
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[0][0] = true;
    
    while (!q.empty()) {
        int focus_y = q.front().first;
        int focus_x = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; ++i) {
            int new_y = focus_y + dy[i];
            int new_x = focus_x + dx[i];
            
            if (new_y >= 0 && new_y < sero && new_x >= 0 && new_x < garo && visited[new_y][new_x] == false) {
                if (map[new_y][new_x] == 1) {
                    exterior_count[new_y][new_x]++;
                }
                else {
                    visited[new_y][new_x] = true;
                    q.push({new_y, new_x});
                }
            }
            
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> sero >> garo;
    
    map.resize(sero, vector<int>(garo));
    exterior_count.resize(sero, vector<int>(garo));
    visited.resize(sero, vector<bool>(garo));
    
    for (int i = 0; i < sero; ++i) {
        for (int j = 0; j < garo; ++j) {
            cin >> map[i][j];
        }
    }
    
    int time = 0;
    while (true) {
        exterior_count = vector<vector<int>>(sero, vector<int>(garo, 0));
        visited = vector<vector<bool>>(sero, vector<bool>(garo, false));
        
        //치즈 없으면 루프 탈출
        if (!cheese_existence()) {
            break;
        }
        
        for (int i = 0; i < sero; ++i) {
            for (int j = 0; j < garo; ++j) {
                
                //세로 부분의 첫 줄과 마지막 줄에서는
                if (i == 0 || i == sero - 1) {
                    //해당 i에 대한 모든 j에 대해 치즈가 존재하지 않으며 방문하지 않았을 시,
                    if (map[i][j] == 0 && visited[i][j] == false) {
                        //해당 모서리는 지금까지 탐사하지 않는 구역이므로 탐사를 진행함
                        bfs(i, j);
                    }
                }
                //세로 줄의 다른 부분에서는
                else {
                    //가로의 첫 부분이나 끝자락일 때에
                    if (j == 0 || j == garo - 1) {
                        //해당 i에 대한 모든 j에 대해 치즈가 존재하지 않으며 방문하지 않았을 시,
                        if (map[i][j] == 0 && visited[i][j] == false) {
                            //해당 모서리는 지금까지 탐사하지 않는 구역이므로 탐사를 진행함
                            bfs(i, j);
                        }
                    }
                    //그 외의 경우 모서리가 아니므로
                    else {
                        //다음 루프로 넘어감
                        continue;
                    }
                }
                
            }
        }
        
        for (int i = 0; i < sero; ++i) {
            for (int j = 0; j < garo; ++j) {
                if (exterior_count[i][j] > 1) {
                    map[i][j] = 0;
                }
            }
        }
        
        time++;
        
    }
    
    cout << time << endl;
    
    return 0;
}

// prov 2638

//아니 다 풀고 개쩌는 생각이 났는데
//이거 그냥 각주 엄청 많은 부분처럼 하지 말고 map 크기를 가로세로 하나씩만 늘리면
//그냥 0, 0에서 bfs 출발해도 지가 알아서 모서리들 다 체크함 ㅋㅋㅋㅋㅋ
