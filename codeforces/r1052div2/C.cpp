#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>
#include <ranges>

void run_case() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == '1') {
            if(cnt == 1) {
                std::cout << "No" << '\n';
                return;
            } 
            cnt = 0;
        } else {
            cnt += 1;
        }
    }

    cnt = 0;
    for(int i = N - 1; i >= 0; i--) {
        if(S[i] == '1') {
            if(cnt == 1) {
                std::cout << "No" << '\n';
                return;
            }
            cnt = 0;
        } else {
            cnt += 1;
        }
    }

    std::cout << "Yes" << '\n';
    std::vector<int> ans(N, 0);
    std::iota(ans.begin(), ans.end(), 1);
    int pre = -1;
    for(int i = 0; i < N; i++) {
        if(S[i] == '1') {
            if(pre != i - 1) {
                std::ranges::reverse(ans.begin() + pre + 1, ans.begin() + i);
            }
            pre = i;
        }
    }

    if(pre != N - 1) {
        std::ranges::reverse(ans.begin() + pre + 1, ans.end());
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
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
