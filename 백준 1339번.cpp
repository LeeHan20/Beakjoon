8/15 깃허브 코드

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;

void calculate_weights(const vector<string>& alphas, unordered_map<char, int>& weights) {
    for (const string& word : alphas) {
        unsigned long int length = word.length();
        for (int i = 0; i < length; ++i) {
            weights[word[i]] += pow(10, length - i - 1);
            //pow(<#double#>, <#double#>)함수
            //첫 번째 인자 = n, 두 번째 인자 = m이라고 하면
            //n**m을 리턴함
            //파이썬이면 **, **(1/2) c++이면 pow, sqrt
            cout << weights[word[i]] << endl;
        }
    }
}

int calculate_max_sum(unordered_map<char, int>& weights) {
    vector<int> values;
    for (const auto& pair : weights) {
        values.push_back(pair.second);
    }
    //원래라면 weights의 size를 구하고 vector의 길이를 size로 설정해서 i index를 사용해서 values를 초기화하였지만
    //그건 c에서 배열 초기화할 때나 하는 거고 백터는 가변적이라 그냥 이렇게 하면 훨씬 편함
    
    sort(values.begin(), values.end(), greater<int>());
    //greater<int>는 내림차순 정렬에 사용
    //안 쓰면 오름차순
    int max_sum = 0;
    int index = 9;
    for (int value : values) {
        max_sum += value * index;
        index--;
    }
    
    return max_sum;
}

int main() {
    int number_of_alphas;
    cin >> number_of_alphas;
    vector<string> alphas(number_of_alphas);
    
    for (int i = 0; i < number_of_alphas; ++i) {
        cin >> alphas[i];
    }
    
    unordered_map<char, int> weights;
    calculate_weights(alphas, weights);
    int result = calculate_max_sum(weights);
    
    cout << result << "\n";
    //문제 자체가 출력을 숫자 하나만 하기 때문에 endl을 써도 상관없음
    
    return 0;
}

//백준 1339번

//calculate_weight 함수에서 각 알파벳의 무게(가중치?)의 기본값을 계산함
//ex) A = 10000, B = 1010
//그리고 그 계산한 무게에 따라 9부터 0까지의 숫자를 할당하여 모두 더함
//처음에는 각 알파벳 문자열을 줄 단위로 받아 각각의 자리를 비교하고 가장 큰 알파벳의 자리를 9, 8 순서대로 대체하면서
//할 생각이었는데 애초에 줄 단위로 생각할 필요도 없었음

//조금 더 어려운 구현 문제를 만나면 위의 상황처럼 될 수도 있긴 한데
//그건 학년 올라가면 내가 알아서 하겠지~

//지난번부터 unordered_map이 상당히 쓸만하다
//가변적인 자료형인 것부터 문자열 인덱스를 지원한다는 건 정말 말도 안 되는 기능이다
