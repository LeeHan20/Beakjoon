#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int hardness_number;
    cin >> hardness_number;
    
    //난이도가 0으로 입력되면 프로그램을 종료
    if (hardness_number == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    //난이도들
    vector<int> numbers(hardness_number);
    for (int i = 0; i < hardness_number; ++i) {
        cin >> numbers[i];
    }
    
    //절사평균을 취할 때 양쪽에서 자를 수의 개수
    int cuting_number = round(hardness_number*0.15);
    
    sort(numbers.begin(), numbers.end());
    
    //절사평균을 취하기 위해 양쪽을 잘라냄
    //백터를 이미 정렬해놓기도 했고 원소를 특정해서 빼내는 것이 아니기 때문에 다시 정의하는게 빠름
    numbers = vector<int> (numbers.begin() + cuting_number, numbers.end() - cuting_number);
    
    
    int sum = 0;
    for (int i = 0; i < numbers.size(); ++i) {
        sum += numbers[i];
    }
    
    //마지막에 sum과 size의 나눗셈은 정수형 나눗셈이 되기 때문에 5.666을 6으로 반환하지 않고
    //5로 반환함. 따라서 sum이나 size 중 하나를(셈을 하는 두 수 중 하나) double이나 float로 바꿔야 round함수가
    //제대로 처리할 수 있음
    cout << round((double)sum/numbers.size()) << endl;
        
    
    return 0;
}

//백준 18110번

//백터 다루기, 정수형 나눗셈의 버림
