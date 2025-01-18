#include "iostream"
#include "vector"
#include "queue"
#include "deque"
#include "string"
#include "stack"
#define endl '\n'
using namespace std;

#define unchecked 999999999

vector<vector<vector<int>>> dp_table(101, vector<vector<int>>(101, vector<int>(101, unchecked)));

int hahahoho_func_excution(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        dp_table[a + 50][b + 50][c + 50] = 1;
        return 1;
    }
    
    if (a > 20 || b > 20 || c > 20) {
        int parameter1;
        if (dp_table[70][70][70] == unchecked) parameter1 = hahahoho_func_excution(20, 20, 20);
        else parameter1 = dp_table[70][70][70];
        
        dp_table[70][70][70] = parameter1;
        
        return parameter1;
    }
    
    if (a < b && b < c) {
        int parameter1, parameter2, parameter3;
        if (dp_table[a + 50][b + 50][c + 49] == unchecked) parameter1 = hahahoho_func_excution(a, b, c-1);
        else parameter1 = dp_table[a + 50][b + 50][c + 49];
        if (dp_table[a + 50][b + 49][c + 49] == unchecked) parameter2 = hahahoho_func_excution(a, b-1, c-1);
        else parameter2 = dp_table[a + 50][b + 49][c + 49];
        if (dp_table[a + 50][b + 49][c + 50] == unchecked) parameter3 = hahahoho_func_excution(a, b-1, c);
        else parameter3 = dp_table[a + 50][b + 49][c + 50];
        
        dp_table[a + 50][b + 50][c + 49] = parameter1;
        dp_table[a + 50][b + 49][c + 49] = parameter2;
        dp_table[a + 50][b + 49][c + 50] = parameter3;
        
        return parameter1 + parameter2 - parameter3;
    }
    
    int parameter1, parameter2, parameter3, parameter4;
    if (dp_table[a + 49][b + 50][c + 50] == unchecked) parameter1 = hahahoho_func_excution(a - 1, b, c);
    else parameter1 = dp_table[a + 49][b + 50][c + 50];
    if (dp_table[a + 49][b + 49][c + 50] == unchecked) parameter2 = hahahoho_func_excution(a-1, b-1, c);
    else parameter2 = dp_table[a + 49][b + 49][c + 50];
    if (dp_table[a + 49][b + 50][c + 49] == unchecked) parameter3 = hahahoho_func_excution(a-1, b, c-1);
    else parameter3 = dp_table[a + 49][b + 50][c + 49];
    if (dp_table[a + 49][b + 49][c + 49] == unchecked) parameter4 = hahahoho_func_excution(a-1, b-1, c-1);
    else parameter4 = dp_table[a + 49][b + 49][c + 49];
    
    dp_table[a + 49][b + 50][c + 50] = parameter1;
    dp_table[a + 49][b + 49][c + 50] = parameter2;
    dp_table[a + 49][b + 50][c + 49] = parameter3;
    dp_table[a + 49][b + 49][c + 49] = parameter4;
    
    return parameter1 + parameter2 + parameter3 - parameter4;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while (true) {
        int a, b, c;
        cin >> a >> b >> c;
        
        if (a == -1 && b == -1 && c == -1) {
            break;
        }
        
        cout << "w(" << a << ", " << b << ", " << c << ") = " << hahahoho_func_excution(a, b, c) << endl;
    }
    
    return 0;
}

// prov

//코드는 더 간결하게 쓸 수 있다


