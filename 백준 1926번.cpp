#include "iostream"
#include "vector"
#include "queue"
using namespace std;

int sero, garo;
vector<vector<int>> map;
int wide = 0;

void dfs(int y, int x) {
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    
    map[y][x] = 2;
    wide++;
    
//    cout << "recursive exploration is working " << endl;
    
    for (int i = 0; i < 4; ++i) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if (new_x >= 0 && new_x < garo && new_y >= 0 && new_y < sero && map[new_y][new_x] == 1) {
            dfs(new_y, new_x);
        }
    }
    
    return;
}

void bfs(int y, int x) {
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    
    //bfs가 수행하는 것은 1인 좌표로 들어오는 것에서 얼마나 연결되어 있느냐를 확인하는 것임
    //즉, 1인지 아닌지는 main함수가 판단하고 bfs는 그것의 연결 요소만을 판단함
    queue<pair<int, int>> q;
    q.push({y, x});
    map[y][x] = 2;
    
    while (!q.empty()) {
        wide++;
        pair<int, int> focus_coord = q.front();
        q.pop();
//        map[focus_coord.first][focus_coord.second] = 2;
        
        for (int i = 0; i < 4; ++i) {
            int new_y = focus_coord.first + dy[i];
            int new_x = focus_coord.second + dx[i];
            
            if (new_x >= 0 && new_x < garo && new_y >= 0 && new_y < sero && map[new_y][new_x] == 1) {
                q.push({new_y, new_x});
                map[new_y][new_x] = 2;
            }
        }
    }
    
    
    
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> sero >> garo;
    
    map.resize(sero);
    for (auto &garos : map) {
        garos.resize(garo);
    }
    
    for (int i = 0; i < sero; ++i) {
        for (int j = 0; j < garo; ++j) {
            cin >> map[i][j];
        }
    }
    
    vector<int> wides;
    
    for (int i = 0; i < sero; ++i) {
        for (int j = 0; j < garo; ++j) {
            if (map[i][j] == 1) {
                wide = 0;
//                dfs(i, j);
                bfs(i, j);
                wides.push_back(wide);
//                cout << "the changed map is " << endl;
//                for (auto vec : map) {
//                    for (auto i : vec) {
//                        cout << i << " ";
//                    }
//                    cout << endl;
//                }
            }
        }
    }
    
    if (!wides.size()) {
        cout << 0 << "\n" << 0 << endl;
    }
    else {
        cout << wides.size() << endl;
        cout << *max_element(wides.begin(), wides.end()) << endl;
    }
    
    return 0;
}

//prov 1926

//모두 0이라서 wides의 요소가 없을 때를 처리해줘야 런타임 에러가 나지 않음
//bfs, dfs 둘 다 사용 가능
