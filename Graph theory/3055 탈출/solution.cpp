#include "iostream"
#include "vector"
#include "queue"
#include "deque"
#include "string"
#include "stack"
#include "cmath"
#include "tuple"
#define endl '\n'
using namespace std;
typedef long long ll;

struct location {
    int y;
    int x;
    int depth;
    char state;
};

struct destination {
    int y;
    int x;
};

int sero, garo;
destination dest;
vector<vector<char>> map;
deque<location> q;

bool out_of_boundary(int y, int x) {
    
    return y < 0 || y >= sero || x < 0 || x >= garo;
}

void bfs() {
    int dy[] = {0, 0, -1, 1};
    int dx[] = {-1, 1, 0, 0};
    
    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int depth = q.front().depth;
        char state = q.front().state;
        q.pop_front();
        
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (ny == dest.y && nx == dest.x && state == 'S') {
                cout << depth + 1 << endl;
                return;
            }
            
            if (out_of_boundary(ny, nx) || map[ny][nx] != '.') continue;
            
            q.push_back({ny, nx, depth + 1, state});
            map[ny][nx] = state;
        }
        
//        for (int i = 0; i < sero; ++i) {
//            for (int j = 0; j < garo; ++j) {
//                cout << map[i][j];
//            }
//            cout << endl;
//        }
//        cout << endl;
        
    }
    
    cout << "KAKTUS" << endl;
    
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> sero >> garo;
    
    map.resize(sero, vector<char>(garo));
    
    for (int i = 0; i < sero; ++i) {
        string line;
        cin >> line;
        
        for (int j = 0; j < garo; ++j) {
            char allocation_char = line[j];
            map[i][j] = allocation_char;
            
            switch (allocation_char) {
                case 'S':
                    q.push_back({i, j, 0, 'S'});
                    break;
                case '*':
                    q.push_front({i, j, 0, '*'});
                    break;
                case 'D':
                    dest.y = i;
                    dest.x = j;
                    break;
            }
        }
    }
    
    bfs();
    
    return 0;
}

// prov 3055

// D -> 목적지, S -> 출발지, * -> 물
