8/28 깃허브 코드

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //테스트 케이스가 많아질 때를 위한 입출력 성능 개선

    int T;
    cin >> T; 
    
    while (T--) {
        int N;
        cin >> N;  
        //지원자
        
        vector<pair<int, int>> applicants(N);
        for (int i = 0; i < N; ++i) {
            int paper_rank, interview_rank;
            cin >> paper_rank >> interview_rank;
            applicants[i] = {paper_rank, interview_rank};
        }
        
        //서류 성적 기준으로 정렬
        sort(applicants.begin(), applicants.end());
        
        int count = 1;  
        //첫 번째 지원자는 항상 합격해야 함
        int best_interview_rank = applicants[0].second;
        
        for (int i = 1; i < N; ++i) {
            if (applicants[i].second < best_interview_rank) {
                count++;
                best_interview_rank = applicants[i].second;
            }
        }
        cout << count << "\n";
    }
    return 0;
}

//백준 1946번
//무난무난 슴슴하다

//굳이 잘 안 쓰는 while문을 쓸 정도로 딱히 어렵지 않은 문제
//sort가 들어있어서 시간초과 나지 않을까 생각했는데 의외로 안 난다

//{type ,type} << pair의 각 원소 정의할 때 씀
