#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = static_cast<int64_t>(998244353);

void run_case() {
    int N, K;
    std::cin >> N >> K;

    int n = static_cast<int>(sqrt(N * 2));

    std::vector<int64_t> dp(N + 1, 0);
    std::vector<int64_t> ans(N + 1, 0); 
    for(int i = 1; i <= N; i++) {
        if(i % K == 0) {
            dp[i] = 1;
            ans[i] += 1;
        }
    }

    std::vector<int64_t> ds(K + n + 1, 0);
    for(int i = 1; i <= n; i++) {
        std::vector<int64_t> ndp(N + 1, 0);
        for(int j = 0; j < K + i; j++) {
            ds[j] = 0;
        }
        for(int j = 1; j <= N; j++) {
            ndp[j] += ds[j % (K + i)];
            ndp[j] %= MOD;

            ds[j % (K + i)] += dp[j];
            ds[j % (K + i)] %= MOD;

            ans[j] += ndp[j];
            ans[j] %= MOD;
        }

        dp = std::move(ndp);
    }

    for(int i = 1; i <= N; i++) {
        std::cout << ans[i] << " \n"[i == N];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
