8/28 깃허브 코드

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //테스트 케이스가 많아지면 

    int T;
    cin >> T;  // 테스트 케이스의 수
    
    while (T--) {
        int N;
        cin >> N;  // 지원자의 수
        
        vector<pair<int, int>> applicants(N);
        
        for (int i = 0; i < N; ++i) {
            int paper_rank, interview_rank;
            cin >> paper_rank >> interview_rank;
            applicants[i] = {paper_rank, interview_rank};
        }
        
        // 서류 성적 기준으로 정렬
        sort(applicants.begin(), applicants.end());
        
        int count = 1;  // 첫 번째 지원자는 항상 합격
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
