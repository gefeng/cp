#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = int(2e9);

void run_case() {
    int N;
    std::cin >> N;
    
    std::string S, T;
    std::cin >> S >> T;

    std::vector<int> pos(26, 0);
    for(int i = 0; i < 26; i++) {
        pos[T[i] - 'a'] = i;
    }
    
    int skip = 0;
    int set = 1;
    for(int i = 1; i < N; i++) {
        int n_skip = INF;
        int n_set = INF;
        char pre_c = S[i - 1];
        char pre_pc = T[27 - (pos[pre_c - 'a'] + 1) - 1];
        char c = S[i];
        char pc = T[27 - (pos[c - 'a'] + 1) - 1]; 

        if(c >= pre_c && skip != INF) {
            n_skip = std::min(n_skip, skip);
        }

        if(c >= pre_pc && set != INF) {
            n_skip = std::min(n_skip, set);
        }

        if(pc >= pre_c && skip != INF) {
            n_set = std::min(n_set, skip + 1);
        }

        if(pc >= pre_pc && set != INF) {
            n_set = std::min(n_set, set + 1);
        }

        std::swap(skip, n_skip);
        std::swap(set, n_set);
    }

    int ans = std::min(skip, set);
    
    std::cout << (ans == INF ? -1 : ans) << '\n';
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
