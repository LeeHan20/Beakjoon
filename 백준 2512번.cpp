// 8/25 깃허브 코드

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool is_possible(const vector<int>& budgets, int total_budget, int cap) {
    int sum = 0;
    for (int budget : budgets) {
        sum += min(budget, cap);
        //요청한 예산과 현재 상한선의 후보(mid, cap)를 비교함
        //cap이 정상 범위 내의 값이라면 budget이 total보다 많은 값을 요구해도 cap이 억제할 수 있음
        //그렇지 않을 때는 아래 return에서 bool타입으로 그 여부를 판단하여 내보냄
    }
    return sum <= total_budget;
}
//이거 void로 &붙여서 나가게 할 수도 있음

int main() {
    int province, total_budget;
    cin >> province;
    vector<int> budgets(province);
    
    for (int i = 0; i < province; ++i) {
        cin >> budgets[i];
    }
    cin >> total_budget;
    
    int left = 0;
    int right = *max_element(budgets.begin(), budgets.end());
    //여기서 *은 또 주소와 관련되는데
    //max_element는 max element의 주소를 가리킨다
    //int에 값을 할당하려면 주소가 아닌 값을 받아와야 하는데 *를 붙여서 역참조를 하면 주소에 해당하는 값을 받아올 수 있다
    int answer = 0;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (is_possible(budgets, total_budget, mid)) {
            answer = mid;
            left = mid + 1;
            //mid값이 상한선이 될 수 있다면 mid값을 키우는 방향으로 탐색함
        }
        else {
            right = mid - 1;
            //mid값이 상한선이 될 수 없다면 mid값을 줄이는 방향으로 탐색함
        }
    }
    
    cout << answer << endl;
    
    return 0;
}

//백준 2512번

//처음 문제를 보면 상한선이 도대체 뭔가 싶을 수 있는데
//사실 나도 그랬고 문제 볼 때는 이해 못 했는데 이진 탐색 찾아보다가 이해함

//예전 코드들도 보다 보니 변수명은 직관적인 편이 확실히 좋은 듯

//갓 들어온 따끈따끈한 새내기들한테 이진탐색, 트리, 재귀, 동적 계획법 다 가르쳐주신 현하킴 교수님 연전연승 중
