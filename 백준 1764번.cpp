#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int li_people_number, se_people_number;
    cin >> li_people_number >> se_people_number;
    vector<string> li_people(li_people_number);
    vector<string> se_people(se_people_number);
    
    for (int i = 0; i < li_people_number; ++i) {
        cin >> li_people[i];
    }
    
    for (int i = 0; i < se_people_number; ++i) {
        cin >> se_people[i];
    }

    sort(li_people.begin(), li_people.end());
    sort(se_people.begin(), se_people.end());

    vector<string> intersection;
    
    intersection.resize(min(li_people.size(), se_people.size()));

    auto it = set_intersection(li_people.begin(), li_people.end(), se_people.begin(), se_people.end(), intersection.begin());

    intersection.resize(it - intersection.begin());
    
    cout << intersection.size() << "\n";
    for (const string& name : intersection) {
        cout << name << "\n";
    }

    return 0;
}

//mian으로 다 몰아서 무지성 코드쓰기

//vecotr의 크기를 구하는 함수가 sizeof인 줄 알았는데 그냥 size였음
//교집합을 구하는데 algorithm라이브러리의 set_intersection을 사용함
//이름 자체는 어디에 따로 정의된 함수인 것처럼 보이는데 저거 자체가 알고리즘에서 제공하는 함수임

//사실 이거 실버 문제가 맞나 싶은 난이도
