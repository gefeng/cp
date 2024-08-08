#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    std::vector<std::set<int>> pos(26);
    for(int i = 0; i < N; i++) {
        pos[S[i] - 'a'].insert(i);
    }
    
    auto solve_back = [&]() {
        std::string s = "back";
        int cnt = 0;
        int res = 0;
        while(true) {
            int last = N;
            int suffix = 0;
            for(int i = 3; i >= 0; i--) {
                int c = s[i] - 'a';
                auto it = pos[c].upper_bound(last);
                if(it == pos[c].begin()) {
                    break;
                }
                it--;
                suffix += 1;
                last = *it;
                pos[c].erase(it);
            }

            int need = 4 - suffix;
            if(need <= cnt) {
                res += 3;
                cnt -= need - 1;
            } else {
                break;
            }
        }

        return res;
    };

    auto solve_front = [&]() {
        std::string s = "front";
        int cnt = 0;
        int res = 0;
        while(true) {
            int now = -1;
            int prefix = 0;
            for(int i = 0; i < 5; i++) {
                int c = s[i] - 'a';
                auto it = pos[c].upper_bound(now);
                if(it == pos[c].end()) {
                    break;
                }
                prefix += 1;
                now = *it;
                pos[c].erase(it);
            }

            int need = 5 - prefix;
            if(need <= cnt) {
                res += 4;
                cnt -= need - 1;
            } else {
                break;
            }
        }
        return res;
    }; 

    std::cout << N - solve_back() - solve_front() << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
