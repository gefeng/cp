#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>
#include <unordered_map>

void run_case() {
    int S, K;
    std::cin >> S >> K;

    if(S % K == 0) {
        std::cout << K << '\n';
        return;
    }

    if(S >= K * K) {
        std::cout << std::max(1, K - 2) << '\n';
        return;
    }

    std::vector<int> dp(S + 1, 0);
    dp[0] = 1;

    int k = K;
    while(true) {
        std::vector<int> ndp(S + 1, 0);
        for(int i = 0; i <= S; i++) {
            if(i - k >= 0 && (dp[i - k] || ndp[i - k])) {
                ndp[i] = 1;
            }
        }

        std::swap(dp, ndp);

        if(dp[S]) {
            std::cout << k << '\n';
            return;
        }


        k = std::max(k - 1, 1);
        
        ndp.assign(S + 1, 0);
        for(int i = S; i >= 0; i--) {
            if(i + k <= S && (dp[i + k] || ndp[i + k])) {
                ndp[i] = 1;
            }
        }

        k = std::max(k - 1, 1);
        std::swap(dp, ndp);
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
