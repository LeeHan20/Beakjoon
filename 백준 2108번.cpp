#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <algorithm>
#include <unordered_map>
using namespace std;

void mean(vector<int> numbers) {
    unsigned long int size = numbers.size();
    //그냥 int를 써도 상관없지만 size 함수는 양수만을 반환하고(unsigned) 그 값의 범위가 int와 다르기 때문에(long) int를 사용하지 않음
    //근데 auto가 있는데 이게 다 무슨 소용인가 싶긴 함 ㅋㅋㅋㅋㅋㅋㅋ
    //size의 범위는 50만까지라서 진짜로 int 써도 상관없음
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += numbers[i];
    }
    int result = round(static_cast<double>(sum) / numbers.size());
    cout << result << "\n";
    return;
}

void median(vector<int> numbers) {
    unsigned long int mid_value = (numbers.size() - 1) / 2;
    cout << numbers[mid_value] << "\n";
    return;
}

void mode(vector<int> &numbers) {
    unordered_map<int, int> frequency;
    for (int number : numbers) {
        frequency[number]++;
    }

    vector<pair<int, int>> freq_vec(frequency.begin(), frequency.end());

    // 빈도 내림차순, 값 오름차순으로 정렬
    sort(freq_vec.begin(), freq_vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    });

    int mode = freq_vec[0].first;
    if (freq_vec.size() > 1 && freq_vec[0].second == freq_vec[1].second) {
        mode = freq_vec[1].first;
    }

    cout << mode << "\n";
}

void range(vector<int> numbers) {
    int range = numbers.back()- numbers[0];
    cout << range << "\n";
    return;
}

int main (void) {
    int number_of_numbers;
    //(1 ≤ number_of_numbers ≤ 500,000)
    //number_of_numbers is odd number
    cin >> number_of_numbers;
    vector<int> numbers (number_of_numbers);
    for (int i = 0; i < number_of_numbers; ++i) {
        cin >> numbers[i];
    }
    sort(numbers.begin(), numbers.end());
    //정렬해서 함수들에 전달함
    mean(numbers);
    median(numbers);
    mode(numbers);
    range(numbers);
    
    return 0;
}

//현하킴 교수님 기말고사에서 파이썬으로 푼 문제들을 c++로 풀기
//오히려 백준 문제에는 n의 홀수 가정 등이 있어 풀기 쉬움
//하지만 c++로 해서 난이도는 더 어려운 듯

//unordered_map이 파이썬의 딕셔너리 비슷한 역할을 하는데 쓰임은 딕셔너리보다 훨씬 쓰기 편한 듯
