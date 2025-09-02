#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <stack>
#include "string"
#include "algorithm"
#include "cmath"
#include "unordered_map"
#include <string>
#include "unordered_set"
#include "map"
#include <set>
#include "deque"
#include <iomanip>
#define endl '\n'
#define space ' '
#define INF 2147483647
#define MAX 1000000007
using namespace std;
typedef long long ll;
//const long long INF = 1LL << 60;
//typedef __int128 ll;
//#define RANDRANGE(a,b) ((rand() % (b - a)) + (a))

int n, k;
vector<int> words;
unordered_map<int, bool> um;

int calculate_possible_words(int bit_field) {
    int cnt = 0;
    
    for (int word : words) {
        cnt += (word == (word & bit_field));
    }
    
    return cnt;
}

int recursion(int bit_field, int target, int activated) {
    if (activated == k + 1) {
        return calculate_possible_words(bit_field);
    }
    
    bit_field |= (1 << target);
    int current = 0;
    
    if (um[bit_field] == true) {
        return 0;
    }
    
    um[bit_field] = true;
    
    for (int i = 0; i < 26; ++i) {
        int mask = (1 << i);
        if (mask == (bit_field & mask)) {
            continue;
        }
        
        current = max(current, recursion(bit_field, i, activated + 1));
    }
    
    return current;
}

int negative_recursion(int bit_field, int target, int deleted) {
    if (deleted == 26 - k) {
        return calculate_possible_words(bit_field);
    }
    
    bit_field &= ~(1 << target);
    int current = 0;
    
    if (um[bit_field] == true) {
        return 0;
    }
    
    um[bit_field] = true;
    
    for (int i = 0; i < 26; ++i) {
        if (i == 0 || i == 2 || i == 8 || i == 13 || i == 19) {
            continue;
        }
        int mask = ~(1 << i);
        if (bit_field == (bit_field & mask)) {
            continue;
        }
        
        current = max(current, negative_recursion(bit_field, i, deleted + 1));
    }
    
    return current;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> k;
    
    for (int i = 0; i < n; ++i) {
        string line;
        cin >> line;
        
        int bit_field = 0;
        
        for (char alpha : line) {
            int shift = (int)alpha - 97;
            
            bit_field = bit_field | (1 << shift);
        }
        
        words.push_back(bit_field);
    }
    
    if (k < 5) {
        cout << 0 << endl;
        return 0;
    } else if (k == 26) {
        cout << n << endl;
        return 0;
    }
    
    int base = 0;
    
    base = base | (1 << ('a' - 97));
    base = base | (1 << ('n' - 97));
    base = base | (1 << ('t' - 97));
    base = base | (1 << ('i' - 97));
    base = base | (1 << ('c' - 97));
    
    int learned_word = 0;
    
    for (int i = 0; i < 26; ++i) {
        if (i == 0 || i == 2 || i == 8 || i == 13 || i == 19) {
            continue;
        }
        
        if (k < 15) {
            learned_word = max(learned_word, recursion(base, i, 6));
        } else {
            learned_word = max(learned_word, negative_recursion((1 << 26) - 1, i, 0));
        }
        
    }
    
    cout << learned_word << endl;
    
    return 0;
}

//starting with "anta", and end with "tica"

// 즉, a, n, t, i, c는 반드시 alpha에 포함되어야 함
// 5개가 반드시 필요

// 처음 버전에서의 개선사항
// calculate_possible_words를 모든 리프들에서만 검사하도록 변경
// visited를 이용하여 방문한 field의 재방문을 막음

// positivie feedback, negative feedback을 나누면 시간복잡도의 지수적 스케일이 반으로 줄지 않을까?
