#include <iostream>
#include <vector>
using namespace std;

vector<string> star;

// 기본 삼각형 정의
void create_base() {
    star.push_back("  *  ");
    star.push_back(" * * ");
    star.push_back("*****");
}

void expand_triangle(int size) {
    if (size == 3) return;

    int prev_size = size / 2;
    expand_triangle(prev_size);

    vector<string> new_star(size, string(size * 2 - 1, ' '));

    // 이전 삼각형 복사
    for (int i = 0; i < prev_size; i++) {
        new_star[i + prev_size] = star[i] + " " + star[i];
    }
    // 위 삼각형 배치
    for (int i = 0; i < prev_size; i++) {
        int padding = prev_size;
        new_star[i].replace(padding, star[i].size(), star[i]);
    }

    star = new_star;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    create_base();
    expand_triangle(n);

    for (string s : star) {
        cout << s << '\n';
    }

    return 0;
}
