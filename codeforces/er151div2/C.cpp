#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::string S;
    std::cin >> S;

    int M;
    std::cin >> M;

    std::string L, R;
    std::cin >> L >> R;

    int n = S.size();
    std::vector<std::vector<int>> pos(10);
    for(int i = 0; i < n; i++) {
        pos[S[i] - '0'].push_back(i);
    }

    for(int i = M - 1; i >= 0; i--) {
        int l = L[i] - '0';
        int r = R[i] - '0';

        int min_i = n;
        for(int d = l; d <= r; d++) {
            if(pos[d].empty()) {
                std::cout << "YES" << '\n';
                return;
            } 

            min_i = std::min(min_i, pos[d].back());
        }

        for(int d = 0; d < 10; d++) {
            while(!pos[d].empty() && pos[d].back() >= min_i) {
                pos[d].pop_back();
            }
        }
    }

    std::cout << "NO" << '\n';
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
