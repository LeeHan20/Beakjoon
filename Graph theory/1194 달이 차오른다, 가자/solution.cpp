#include <iostream>
#include <queue>
#include <cctype>
#define MAX 50
using namespace std;

int N, M;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int visited[MAX][MAX][1 << 6];
char grid[MAX][MAX];

int BFS(int startRow, int startCol) {
    queue<pair<pair<int,int>, int>> q;
    q.push({{startRow, startCol}, 0});
    visited[startRow][startCol][0] = 1;
    
    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int keys = q.front().second;
        q.pop();
        
        if (grid[r][c] == '1') {
            return visited[r][c][keys] - 1;
        }
        
        for (int i = 0; i < 4; i++){
            int nr = r + dy[i];
            int nc = c + dx[i];
            if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
            
            if (grid[nr][nc] == '#' || visited[nr][nc][keys] != 0)
                continue;
            
            if (islower(grid[nr][nc])) {
                int newKeys = keys | (1 << (grid[nr][nc] - 'a'));
                if (visited[nr][nc][newKeys] == 0) {
                    visited[nr][nc][newKeys] = visited[r][c][keys] + 1;
                    q.push({{nr, nc}, newKeys});
                }
            }
            
            else if (isupper(grid[nr][nc])) {
                if (keys & (1 << (grid[nr][nc] - 'A'))) {
                    visited[nr][nc][keys] = visited[r][c][keys] + 1;
                    q.push({{nr, nc}, keys});
                }
            }
            
            else {
                visited[nr][nc][keys] = visited[r][c][keys] + 1;
                q.push({{nr, nc}, keys});
            }
        }
    }
    
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> grid[i][j];
        }
    }
    
    int startRow = 0, startCol = 0;
    bool foundStart = false;
    for (int i = 0; i < N && !foundStart; i++){
        for (int j = 0; j < M && !foundStart; j++){
            if (grid[i][j] == '0') {
                startRow = i;
                startCol = j;
                foundStart = true;
            }
        }
    }
    
    cout << BFS(startRow, startCol) << "\n";
    return 0;
}
