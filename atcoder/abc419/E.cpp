#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = static_cast<int64_t>(2e18);

void run_case() {
    int N, M, L;
    std::cin >> N >> M >> L;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int64_t>> cost(N, std::vector<int64_t>(M, 0));
    for(int i = 0; i < L; i++) {
        for(int j = 0; j < M; j++) {
            for(int k = i; k < N; k += L) {
                cost[i][j] += A[k] <= j ? j - A[k] : j - A[k] + M;     
            }
        } 
    }

    std::vector<std::vector<int64_t>> dp(L + 1, std::vector<int64_t>(M, INF));
    dp[0][0] = 0;
    
    for(int i = 1; i <= L; i++) {
        for(int j = 0; j < M; j++) {
            if(dp[i - 1][j] == INF) {
                continue;
            }
            
            for(int k = 0; k < M; k++) {
                int r = (j + k) % M;
                dp[i][r] = std::min(dp[i][r], dp[i - 1][j] + cost[i - 1][k]);
            }
        }
    }

    std::cout << dp[L][0] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
