#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = (int64_t)2e18;

void run_case() {
    int N;
    std::cin >> N;
    
    std::string S;
    std::cin >> S;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i]; 
    }

    std::vector<std::vector<int64_t>> dp(2, std::vector<int64_t>(2, INF));
    dp[0][0] = 0;
    dp[1][0] = A[0];
    for(int i = 1; i < N; i++) {
        std::vector<std::vector<int64_t>> ndp(2, std::vector<int64_t>(2, INF));
        if(S[i] == S[i - 1]) {
            ndp[0][0] = dp[1][0];
            ndp[0][1] = std::min(dp[0][0], dp[1][1]);
            
            if(dp[0][0] != INF) {
                ndp[1][0] = dp[0][0] + A[i];
            }
            if(dp[0][1] != INF) {
                ndp[1][1] = std::min(ndp[1][1], dp[0][1] + A[i]);
            }
            if(dp[1][0] != INF) {
                ndp[1][1] = std::min(ndp[1][1], dp[1][0] + A[i]);
            }
        } else { 
            ndp[0][0] = dp[0][0];
            ndp[0][1] = std::min(dp[0][1], dp[1][0]); 

            if(dp[1][0] != INF) {
                ndp[1][0] = dp[1][0] + A[i];
            }
            
            if(dp[0][0] != INF) {
                ndp[1][1] = std::min(ndp[1][1], dp[0][0] + A[i]);
            }
            if(dp[1][1] != INF) {
                ndp[1][1] = std::min(ndp[1][1], dp[1][1] + A[i]);
            }
        }

        std::swap(dp, ndp);
    }

    std::cout << std::min(dp[0][1], dp[1][1]) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
