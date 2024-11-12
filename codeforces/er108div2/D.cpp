#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = int64_t(2e18);

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int64_t> A(N);
    std::vector<int64_t> B(N);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::vector<std::vector<int64_t>> rsum(N, std::vector<int64_t>(N, 0));
    for(int i = 0; i < N; i++) {
        int64_t x = 0;
        for(int l = i, r = i; l >= 0 && r < N; l--, r++) {
            if(l == r) {
                x += A[l] * B[l];
            } else {
                x += A[r] * B[l] + A[l] * B[r];
            }
            rsum[l][r] = x;
        }
        
        x = 0;
        for(int l = i, r = i + 1; l >= 0 && r < N; l--, r++) {
            x += A[r] * B[l] + A[l] * B[r];
            rsum[l][r] = x;
        }
    }

    std::vector<std::vector<std::int64_t>> dp(N + 1, std::vector<int64_t>(2, -INF));
    dp[0][0] = 0;

    for(int i = 0; i < N; i++) {
        dp[i + 1][0] = std::max(dp[i + 1][0], dp[i][0] + A[i] * B[i]);
    
        if(dp[i][1] != -INF) {
            dp[i + 1][1] = std::max(dp[i + 1][1], dp[i][1] + A[i] * B[i]); 
        }

        for(int j = i; j < N; j++) {
            dp[j + 1][1] = std::max(dp[j + 1][1], dp[i][0] + rsum[i][j]);
        }
    }

    std::cout << std::max(dp[N][0], dp[N][1]) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
