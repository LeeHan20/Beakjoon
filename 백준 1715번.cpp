//그냥 문제 자체가 기분이 나쁘다
//내가 1학년인데 시간복잡도를 어떻게 알며 최적의 알고리즘은 또 어떻게 알겠는가?
//priority_queue를 사용하면 시간복잡도가 n^2 log n에서 n log n으로 된다고는 하는데 내가 그걸 어떻게 알고 있겠는가?

//내가 짠 코드
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void print(const vector<int> &list) {
    cout << "[";
    for (int i : list) {
        cout << i << ",";
    }
    cout << "]" << "\n";
    return;
}
//파이썬에서는 리스트를 출력할 수 있는 반면, c++의 백터는 그 자체로 출력하지 못한다
//그래서 백터를 출력하는 함수를 정의하였더니 틀린 부분을 찾는 것에 매우 용이하다

int make_comparsion(vector<int> &cards) {
    int comparsion_number = 0;
    unsigned long int loop_number = cards.size();
    for (int i = 0; i < loop_number - 1; ++i) {
        sort(cards.begin(), cards.end());
        int new_number = cards[1] + cards[0];
        
        comparsion_number += new_number;
        
        cards.erase(cards.begin(), cards.begin()+2);
        cards.push_back(new_number);
    }
    return comparsion_number;
}

int main() {
    int card_number;
    cin >> card_number;
    vector<int> cards (card_number);
    for (int i = 0; i < card_number; ++i) {
        cin >> cards[i];
    }
    
    cout << make_comparsion(cards) << endl;
    
    return 0;
}

//문제에서 해야 할 것은 나열된 숫자들 중에 가장 작은 두 수를 더하고 그 값을 저장한 후 그 값으로 다시 숫자를 나열나여 마지막 숫자가 남을 때까지 반복하는 것
//이참에 priority_queue 사용법을 익혀서 다음에 써먹어야겠다



//내 코드를 gpt가 priority_queue를 이용해서 시간복잡도를 개선한 코드
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int make_comparison(vector<int>& cards) {
    // 최소 힙 (priority_queue를 사용하여 구현)
    priority_queue<int, vector<int>, greater<int>> min_heap(cards.begin(), cards.end());
    
    int comparison_number = 0;
    
    while (min_heap.size() > 1) {
        // 가장 작은 두 카드를 꺼내기
        int first = min_heap.top();
        min_heap.pop();
        int second = min_heap.top();
        min_heap.pop();
        
        // 비교 횟수를 더하고, 두 카드를 합친 값을 다시 힙에 넣기
        int new_number = first + second;
        comparison_number += new_number;
        min_heap.push(new_number);
    }
    
    return comparison_number;
}

int main() {
    int card_number;
    cin >> card_number;
    vector<int> cards(card_number);
    
    for (int i = 0; i < card_number; ++i) {
        cin >> cards[i];
    }
    
    cout << make_comparison(cards) << endl;
    
    return 0;
}
