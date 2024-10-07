//#include <vector>
//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <cctype>
//using namespace std;
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int number_of_coordination;
//    cin >> number_of_coordination;
//    
//    //백터를 두 가지 생성
//    //하나는 result에 index 정보를 줄 백터이고
//    //나머지 하나는 최솟값, 순서를 줄 백터
//    vector<int> coordinations (number_of_coordination);
//    vector<int> jjap_coordinations (number_of_coordination);
//    
//    for (int i = 0; i < number_of_coordination; ++i) {
//        cin >> coordinations[i];
//    }
//    
//    //짭백터를 찐백터에서 가져온 정보로 할당시키고 정렬하고 중복 제거
//    jjap_coordinations = coordinations;
//    sort(jjap_coordinations.begin(), jjap_coordinations.end());
//    jjap_coordinations.erase(unique(jjap_coordinations.begin(), jjap_coordinations.end()), jjap_coordinations.end());
//
//    //압축된 좌표를 index정보와 함께 저장할 result vecotr
//    vector<int> result_vector (number_of_coordination, -1);
//    
//    //압축된 좌표의 첫 번째를 설정
//    int compressive_coordination = 0;
//    
//    while (!empty(jjap_coordinations)) {
//        //일단 최솟값을 구함
//        int mini = jjap_coordinations[0];
//        
//        //최솟값에 해당하는 값이 얼마나 있는지 구하고 해당 인덱스를 저장함
//        int count_of_mini = 0;
//        vector<int> indexes;
//        for (int i = 0; i < coordinations.size(); ++i) {
//            if (coordinations[i] == mini) {
//                count_of_mini++;
//                indexes.push_back(i);
//            }
//        }
//        
//        //해당 최솟값이 있는 인덱스를 압축된 좌표로 저장시킴
//        for (int i = 0; i < count_of_mini; ++i) {
//            result_vector[indexes[i]] = compressive_coordination;
//        }
//        
//        //짭좌표에서 최솟값을 빼냄
//        jjap_coordinations.erase(remove(jjap_coordinations.begin(), jjap_coordinations.end(), mini), jjap_coordinations.end());
//        
//        //압축된 좌표를 다음 값으로 넘김
//        compressive_coordination++;
//    }
//    
//    for (int coo : result_vector) {
//        cout << coo << " ";
//    }
//    
//    cout << endl;
//    
//    return 0;
//}

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int number_of_coordination;
    cin >> number_of_coordination;

    vector<int> coordinations(number_of_coordination);
    for (int i = 0; i < number_of_coordination; ++i) {
        cin >> coordinations[i];
    }

    // 좌표를 복사하고 정렬
    vector<int> sorted_coords = coordinations;
    sort(sorted_coords.begin(), sorted_coords.end());

    // 중복 제거
    sorted_coords.erase(unique(sorted_coords.begin(), sorted_coords.end()), sorted_coords.end());

    // 좌표 값에 대한 압축 맵 생성
    unordered_map<int, int> coord_map;
    for (int i = 0; i < sorted_coords.size(); ++i) {
        coord_map[sorted_coords[i]] = i;
    }

    // 결과 출력
    for (int i = 0; i < coordinations.size(); ++i) {
        cout << coord_map[coordinations[i]] << " ";
    }
    cout << endl;

    return 0;
}

//백준 18870번

//정렬, 구현 문제이긴 한데 unoredered_map(nlogn)을 비효율적으로(n^2) 구현함

//위 코드는 시간초과, 아래 코드는 664ms

//편한게 있으면 그냥 쓰자
