#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int test_number;
    cin >> test_number;
    
    for (int i = 0; i < test_number; ++i) {
        int A_fish, B_fish;
        cin >> A_fish >> B_fish;
        vector<int> A_size(A_fish);
        vector<int> B_size(B_fish);
        
        for (int j = 0; j < A_fish; ++j) {
            cin >> A_size[j];
        }
        
        for (int j = 0; j < B_fish; ++j) {
            cin >> B_size[j];
        }
        
        sort(B_size.begin(), B_size.end());
        
        int cnt = 0;
        
        for (int j = 0; j < A_fish; ++j) {
            cnt += lower_bound(B_size.begin(), B_size.end(), A_size[j]) - B_size.begin();
        }
        
        cout << cnt << "\n";
    }
    return 0;
}

//이중 for문을 쓰면 시간초과가 난다

//이진 탐색을 c++에서 low_bound로 제공해주지만 내가 직접 써보는 것도 필요할 것 같긴 하다
//근데 솔직히 너무 성능 좋음
