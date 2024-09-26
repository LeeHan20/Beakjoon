#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

//주의사항

//main vector인 people의 인덱스와 실제 입력받는 사람의 수는 1씩 차이가 남

bool is_she_attended(const vector<int> &day_people) {
    for (int people : day_people) {
        if (people == 1) {
            return true;
        }
    }
    return false;
}

int main() {
    int number_of_people, campfire_days;\
    cin >> number_of_people;
    cin >> campfire_days;
    
    vector<set<int>> people(number_of_people);
    //main vector로 사람들이 알고 있는 노래를 등록
    //첫 번째 레이어는 사람들, 두 번째 레이어는 사람들의 뇌
    
    int attendant_people;
    for (int i = 0; i < campfire_days; ++i) {
    //캠프파이어 시작
        
        cin >> attendant_people;
        //하루에 참가한 사람의 수
        vector<int> day_people (attendant_people);
        for (int j = 0; j < attendant_people; ++j) {
        //캠프파이어에 참가한 사람들 등록
            cin >> day_people[j];
        }

        if (is_she_attended(day_people)) {
        //선영이 참가했다면 새로운 노래를 공유
            for (int people_number : day_people) {
                people[people_number - 1].insert(i);
            }
        }
        else {
        //선영이가 참여하지 않았다면 참가한 사람들이 아는 노래를 공유
            set<int> daily_shared_songs;
            for (int people_number : day_people) {
            //사람들이 아는 노래를 모두 모은 집합을 만듦
                daily_shared_songs.insert(people[people_number - 1].begin(), people[people_number - 1].end());
            }
            
            for (int people_number : day_people) {
            //daily_shared_songs를 모두에게 알려줌
                people[people_number - 1].insert(daily_shared_songs.begin(), daily_shared_songs.end());
            }
        }
    }
    
    set<int> main_set = people[0];
    
    for (int i = 0; i < people.size(); ++i) {
    //선영의 뇌 속의 노래의 길이와 같다면 출력
        if (main_set == people[i]) {
            cout << i + 1 << "\n";
        }
    }
    
    return 0;
}
