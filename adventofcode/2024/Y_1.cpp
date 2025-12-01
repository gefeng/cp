#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::vector<std::vector<int>> keys;
    std::vector<std::vector<int>> locks;
    std::vector<std::string> A;
    for(std::string S; std::getline(std::cin, S); ) {
        if(S.empty()) {
            continue;
        }
        A.push_back(S);
    }

    int n = A.size();
    for(int i = 0; i < n; i += 7) {
        bool is_key = A[i][0] == '.';
        
        std::vector<int> h;
        for(int c = 0; c < 5; c++) {
            int cnt = 0;
            for(int r = 0; r < 5; r++) {
                if(A[i + r + 1][c] == '#') {
                    cnt += 1;
                }
            }
            h.push_back(cnt);
        }
        
        if(is_key) {
            keys.push_back(h);
            // std::cout << "key: ";
            // for(int i = 0; i < 5; i++) {
            //     std::cout << h[i] << " \n"[i == 4];
            // }
        } else {
            locks.push_back(h);
            // std::cout << "lock: ";
            // for(int i = 0; i < 5; i++) {
            //     std::cout << h[i] << " \n"[i == 4];
            // }
        }
    }

    auto fit = [](std::vector<int>& h_1, std::vector<int>& h_2) {
        for(int i = 0; i < 5; i++) {
            if(h_1[i] + h_2[i] > 5) {
                return false;
            }
        }
        return true;
    };

    int ans = 0;
    for(auto& k : keys) {
        for(auto& l : locks) {
            if(fit(k, l)) {
                ans += 1;
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
