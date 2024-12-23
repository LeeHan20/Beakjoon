vector<bool> is_sosu(5000001, true);
vector<int> prefix_sosu(5000001, 0);

void che(int n) {
    for (int i = 2; i * i < n; ++i) {
        if (is_sosu[i]) {
            for (int j = 2; j * i <= n; ++j) {
                is_sosu[i * j] = false;
            }
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        prefix_sosu[i] = prefix_sosu[i - 1] + (is_sosu[i] ? 1 : 0);
    }
    
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    che(n);
    
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        
        int sosu_cnt = prefix_sosu[b] - prefix_sosu[a - 1];
        
        cout << sosu_cnt << "\n";
    }
    
    return 0;
}

// 41, 43, 47, 49
