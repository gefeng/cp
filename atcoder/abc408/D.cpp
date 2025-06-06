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

    std::string S;
    std::cin >> S;

    std::vector<int> dp(3, INF);
    dp[0] = 0;
    for(int i = 0; i < N; i++) {
        std::vector<int> n_dp(3, INF);
        
        if(S[i] == '1') {
            n_dp[0] = std::min(n_dp[0], dp[0] + 1);
            n_dp[1] = std::min(n_dp[1], dp[0]); 
            if(dp[1] != INF) {
                n_dp[1] = std::min(n_dp[1], dp[1]);
                n_dp[2] = std::min(n_dp[2], dp[1] + 1);
            }
            if(dp[2] != INF) {
                n_dp[2] = std::min(n_dp[2], dp[2] + 1);
            }
        } else {
            n_dp[0] = std::min(n_dp[0], dp[0]);
            n_dp[1] = std::min(n_dp[1], dp[0] + 1);
            if(dp[1] != INF) {
                n_dp[1] = std::min(n_dp[1], dp[1] + 1);
                n_dp[2] = std::min(n_dp[2], dp[1]);
            }
            if(dp[2] != INF) {
                n_dp[2] = std::min(n_dp[2], dp[2]);
            }
        }
        
        dp = std::move(n_dp);
    }

    std::cout << std::min(std::min(dp[0], dp[1]), dp[2]) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
