#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <iomanip>

constexpr int64_t INF = (int64_t)2e18;

void run_case() {
    int N, D;
    std::cin >> N >> D;

    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int64_t>> dp(1 << N, std::vector<int64_t>(D + 1, INF));
    dp[0][0] = 0; 

    for(int s = 1; s < (1 << N); s++) {
        dp[s][1] = 0;
        for(int i = 0; i < N; i++) {
            if(s & (1 << i)) {
                dp[s][1] += A[i];
            }
        }
        dp[s][1] *= dp[s][1];
    }
    
    for(int s = 1; s < (1 << N); s++) {
        int cnt = __builtin_popcount(s);

        for(int k = 2; k <= std::min(D, cnt); k++) {
            for(int sm = s; sm > 0; sm = (sm - 1) & s) {
                if(dp[s ^ sm][k - 1] != INF) {
                    dp[s][k] = std::min(dp[s][k], dp[s ^ sm][k - 1] + dp[sm][1]);
                }
            }
        }
    }

    int64_t sum = 0;
    for(int64_t w : A) {
        sum += w;
    }

    long double ans = (long double)(dp[(1 << N) - 1][D] * D - sum * sum) / (D * D);

    std::cout << std::setprecision(20) << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
