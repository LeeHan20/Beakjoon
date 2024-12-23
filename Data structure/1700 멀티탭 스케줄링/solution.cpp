#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int taps, usage;
    cin >> taps >> usage;
    
    vector<int> sequence(usage);
    for (int i = 0; i < usage; ++i) {
        cin >> sequence[i];
    }

    set<int> used_flugs;
    int out_count = 0;

    for (int i = 0; i < usage; ++i) {
        int focus_thing = sequence[i];
        
        if (used_flugs.find(focus_thing) != used_flugs.end()) {
            continue;
        }

        if (used_flugs.size() < taps) {
            used_flugs.insert(focus_thing);
        } else {
            int item_to_remove = -1;
            int farthest_usage = -1;

            for (auto plugged_item : used_flugs) {
                int next_usage = usage;
                for (int j = i + 1; j < usage; ++j) {
                    if (sequence[j] == plugged_item) {
                        next_usage = j;
                        break;
                    }
                }

                if (next_usage > farthest_usage) {
                    farthest_usage = next_usage;
                    item_to_remove = plugged_item;
                }
            }

            used_flugs.erase(item_to_remove);
            used_flugs.insert(focus_thing);
            out_count++;
        }
    }
    
    cout << out_count << endl;

    return 0;
}

// prov 1700

//가중치만 필요한 것이 아니고 다음에 어떤 것이 올 것인가를 봐야 함

// 가중치 말고 아예  for문으로 뭐가 더 멀리 있는지를 찾아서 뽑으면 될 듯?
//시간복잡도는 이미 많이 줄여서 괜찮지 않을까
