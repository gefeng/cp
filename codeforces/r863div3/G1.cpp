#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

constexpr LL MOD = (LL)1e9 + 7LL;

LL q_pow(LL x, LL y) {
    LL res = 1LL;
    while(y) {
        if(y & 1LL) {
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        y >>= 1LL;
    }
    return res;
}

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    if(K == 1) {
        std::cout << 1 << '\n';
        return;
    }

    std::vector<LL> fact(N + 1, 1LL);
    std::vector<LL> invf(N + 1, 1LL);

    for(int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    for(int i = 1; i <= N; i++) {
        invf[i] = q_pow(fact[i], MOD - 2LL);
    }

    std::vector<std::vector<int>> cnt(N + 1, std::vector<int>(N + 1, 0));
    for(int i = 0; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cnt[i][j] = cnt[i][j - 1] + (i == A[j - 1] ? 1 : 0);
        } 
    }

    std::vector<int> ds(N + 1, 0);
    int max_len = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < i; j++) {
            if(cnt[A[i - 1]][i] - cnt[A[i - 1]][j] >= K) {
                ds[i] = std::max(ds[i], ds[j] + K);
            }
        }
    }

    for(int i = 0; i <= N; i++) {
        max_len = std::max(max_len, ds[i]);
    }

    std::vector<LL> dp(N + 1, 0LL);
    dp[0] = 1LL;
    
    LL ans = max_len == 0 ? 1LL : 0LL;
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < i; j++) {
            if(ds[j] + K == ds[i]) {
                // j + 1, i -> j, i - 1
                int have = cnt[A[i - 1]][i] - cnt[A[i - 1]][j] - 1;
                int need = K - 1;

                if(have >= need) {
                    LL choice = (fact[have] * invf[need] % MOD) * invf[have - need] % MOD;
                    dp[i] += dp[j] * choice % MOD;
                    dp[i] %= MOD;
                }
            }
        }

        if(ds[i] == max_len) {
            ans += dp[i];
            ans %= MOD;
        }
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
