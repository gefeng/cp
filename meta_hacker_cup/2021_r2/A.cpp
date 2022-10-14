#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void run_case(int T) {
    int N, M;
    cin >> N >> M;

    unordered_map<int, int> cur_1;  // unchanged
    unordered_map<int, int> cur_2;  // changed 
    for(int i = 0; i < M; i++) {
        int S;
        cin >> S;

        cur_1[S]++;
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        unordered_map<int, int> nxt_1;
        unordered_map<int, int> nxt_2;
        unordered_map<int, int> todo;

        for(int j = 0; j < M; j++) {
            int S;
            cin >> S;
            
            if(cur_2.find(S) != cur_2.end()) {
                nxt_2[S]++;
                if(--cur_2[S] == 0) {
                    cur_2.erase(S);
                }
            } else if(cur_1.find(S) != cur_1.end()) {
                nxt_1[S]++;
                if(--cur_1[S] == 0) {
                    cur_1.erase(S);
                }
            } else {
                todo[S]++;
            }
        } 

        for(auto [k, v] : todo) {
            while(v) {
                if(!cur_1.empty()) {
                    auto it = cur_1.begin();
                    if(--(it->second) == 0) {
                        cur_1.erase(it);
                    }
                } else {
                    ans++;
                }
                nxt_2[k]++;
                v--;
            }
        }

        swap(cur_1, nxt_1);
        swap(cur_2, nxt_2);
    }

    cout << "Case #" << T << ": " << ans << '\n';
}

int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }
}
