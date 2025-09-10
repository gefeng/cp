#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>
#include <numeric>

void run_case() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    int mex = 0;
    for(int i = 0; i <= N; i++) {
        if(S[i] == '1') {
            mex = std::max(mex, i);
        }
    }

    std::vector<int> ans(N, 0);
    for(int i = 0; i < N; i++) {
        if(i < mex) {
            ans[i] = i;
        } else {
            ans[i] = mex + 1;
        }
    }
    int pre = 1;
    for(int i = 2; i <= N; i++) {
        if(S[i] == '1') {
            if(pre != i - 1) {
                std::ranges::reverse(ans.begin() + pre, ans.begin() + i); 
            } 
            pre = i;
        }
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
