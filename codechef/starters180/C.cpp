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
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> dp(K + 1, 0);
    std::vector<int64_t> ds(K + 2, 0);
    int64_t cnt = 0;

    if(A[0] == -1) {
        for(int i = 1; i <= K; i++) {
            dp[i] = 1;
        }
        for(int i = 1; i <= K; i++) {
            ds[i + 1] = (ds[i] + dp[i]) % MOD;
        }
        cnt = K;
    } else {
        dp[A[0]] = 1;
        for(int i = A[0]; i <= K; i++) {
            ds[i + 1] = (ds[i] + dp[i]) % MOD;
        }
        cnt = 1;
    }

    for(int i = 1; i < N; i++) {
        std::vector<int64_t> n_dp(K + 1, 0);
        std::vector<int64_t> n_ds(K + 2, 0);
        if(A[i] == -1) {
            for(int j = 1; j <= K; j++) {
                n_dp[j] += ds[j];
                n_dp[j] %= MOD;

                n_dp[j] += dp[j] * K % MOD;
                n_dp[j] %= MOD;

                n_dp[j] += cnt;
                n_dp[j] %= MOD;
            }
            cnt *= K;
            cnt %= MOD;
        } else {
            for(int j = 1; j <= K; j++) {
                n_dp[j] += dp[j];
                n_dp[j] %= MOD;
            }
            
            n_dp[A[i]] += ds[A[i]];
            n_dp[A[i]] %= MOD;

            n_dp[A[i]] += cnt;
            n_dp[A[i]] %= MOD;
        }

        for(int j = 1; j <= K; j++) {
            n_ds[j + 1] = (n_ds[j] + n_dp[j]) % MOD;
            n_ds[j + 1] %= MOD;
        }

        std::swap(dp, n_dp);
        std::swap(ds, n_ds);
    }

    int64_t ans = 0;
    for(int i = 1; i <= K; i++) {
        ans += dp[i];
        ans %= MOD;
    }

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
