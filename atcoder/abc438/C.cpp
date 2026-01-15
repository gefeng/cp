#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::pair<int, int>> stk;
    for(int i = 0; i < N; i++) {
        if(!stk.empty()) {
            if(A[i] == stk.back().first) {
                stk.back().second += 1;
            } else {
                stk.emplace_back(A[i], 1);
            }
        } else {
            stk.emplace_back(A[i], 1);
        }

        if(stk.back().second == 4) {
            stk.pop_back();
        }
    }

    int ans = 0;
    for(auto [_, c] : stk) {
        ans += c;
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
