#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(998244353);

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    if(N == 1) {
        std::cout << (A[0] == 0 ? 2 : 1) << '\n';
        return;
    }

    std::vector<std::vector<int64_t>> dp(2, std::vector<int64_t>(N, 0));
    if(A[0] == 0) {
        dp[0][0] = 1;
        dp[1][0] = 1;
    } else {
        dp[0][0] = 0;
        dp[1][0] = 1;
    }

    for(int i = 1; i < N; i++) {
        if(A[i] == A[i - 1]) {
            dp[0][i] += dp[0][i - 1];
            dp[0][i] %= MOD;
        }
        if((i == 1 && A[i] == 1) || (i - 2 >= 0 && A[i - 2] + 1 == A[i])) {
            dp[0][i] += dp[1][i - 1];
            dp[0][i] %= MOD;
        }
        dp[1][i] += dp[0][i - 1];
        dp[1][i] %= MOD;
    }

    int64_t ans = (dp[0][N - 1] + dp[1][N - 1]) % MOD;
    std::cout << ans << '\n';
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
