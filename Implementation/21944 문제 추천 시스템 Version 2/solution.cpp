#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <cmath>
#include <tuple>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;
typedef long long ll;
#define endl '\n'
#define inf 2147483647

int n, m;
unordered_map<string, int> commands = {
    {"recommend", 1},
    {"recommend2", 2},
    {"recommend3", 3},
    {"add", 4},
    {"solved", 5}
};

struct Problem {
    int id;
    int level;
    int group;
};

struct ProblemCompare {
    bool operator()(const Problem &a, const Problem &b) const {
        if(a.level != b.level)
            return a.level < b.level;
        return a.id < b.id;
    }
};

class prov_set {
private:
    set<Problem, ProblemCompare> problems;
    unordered_map<int, Problem> problemById;
    
public:
    // 분류 g에 대해 난이도가 가장 낮은 문제 출력 (recommend -1)
    void recommend1_negative(int g) {
        for (auto it = problems.begin(); it != problems.end(); ++it) {
            if (it->group == g) {
                cout << it->id << endl;
                return;
            }
        }
    }
    
    // 분류 g에 대해 난이도가 가장 높은 문제 출력 (recommend 1)
    void recommend1_positive(int g) {
        for (auto it = problems.rbegin(); it != problems.rend(); ++it) {
            if (it->group == g) {
                cout << it->id << endl;
                return;
            }
        }
    }
    
    // 전체 문제 중 난이도가 가장 낮은 문제 출력 (recommend2 -1)
    void recommend2_negative() {
        if (!problems.empty())
            cout << problems.begin()->id << endl;
    }
    
    // 전체 문제 중 난이도가 가장 높은 문제 출력 (recommend2 1)
    void recommend2_positive() {
        if (!problems.empty())
            cout << problems.rbegin()->id << endl;
    }
    
    // 난이도 기준, l 미만인 문제 중 가장 높은 난이도를 가진 문제 출력 (recommend3 -1)
    void recommend3_negative(int l) {
        auto it = problems.lower_bound({0, l, 0});
        if(it == problems.begin()){
            cout << -1 << endl;
            return;
        }
        it--;
        cout << it->id << endl;
    }
    
    // 난이도 기준, l 이상인 문제 중 가장 낮은 난이도를 가진 문제 출력 (recommend3 1)
    void recommend3_positive(int l) {
        auto it = problems.lower_bound({0, l, 0});
        if(it == problems.end()){
            cout << -1 << endl;
            return;
        }
        cout << it->id << endl;
    }
    
    void add_prov(int p, int l, int g) {
        Problem pr = {p, l, g};
        problems.insert(pr);
        problemById[p] = pr;
    }
    
    void solve_prov(int p) {
        if(problemById.find(p) != problemById.end()){
            Problem pr = problemById[p];
            problems.erase(pr);
            problemById.erase(p);
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    prov_set ps;
    
    for (int i = 0; i < n; ++i) {
        int p, l, g;
        // prov, level, classification
        cin >> p >> l >> g;
        ps.add_prov(p, l, g);
    }
    
    cin >> m;
    
    for (int i = 0; i < m; ++i) {
        string command;
        cin >> command;
        int cmd = commands[command];
        if (cmd == 1) { // recommend
            int g, x;
            cin >> g >> x;
            if (x == -1) ps.recommend1_negative(g);
            else if (x == 1) ps.recommend1_positive(g);
        } else if (cmd == 2) { // recommend2
            int x;
            cin >> x;
            if (x == -1) ps.recommend2_negative();
            else if (x == 1) ps.recommend2_positive();
        } else if (cmd == 3) { // recommend3
            int x, l;
            cin >> x >> l;
            if (x == -1) ps.recommend3_negative(l);
            else if (x == 1) ps.recommend3_positive(l);
        } else if (cmd == 4) { // add
            int p, l, g;
            cin >> p >> l >> g;
            ps.add_prov(p, l, g);
        } else if (cmd == 5) { // solved
            int p;
            cin >> p;
            ps.solve_prov(p);
        }
    }
    
    return 0;
}

// prov 21944
