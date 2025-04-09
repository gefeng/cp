#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

constexpr int64_t MOD = int64_t(1e9) + 7;

int64_t q_pow(int64_t x, int64_t y) {
    int64_t res = 1;
    while(y) {
        if(y & 1) {
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        y >>= 1;
    }
    return res;
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<int> psum(N + 1, 0);
    std::vector<int> present(N, 0);
    int tot = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        if(A[i] != -1) {
            present[A[i]] = 1;
        } else {
            tot += 1;
        }
    }

    for(int i = 0; i < N; i++) {
        psum[i + 1] = psum[i] + (A[i] == -1 ? 1 : 0);
    }

    std::vector<int64_t> fact(N + 1, 1);
    std::vector<int64_t> invf(N + 1, 1);
    for(int i = 2; i <= N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invf[i] = q_pow(fact[i], MOD - 2);
    }

    int64_t ans = 0;
    std::vector<std::vector<int64_t>> dp(N + 1, std::vector<int64_t>(N + 1, 0));

    int min_prefix = N;
    for(int i = 0; i < N; i++) {
        int min_suffix = N;
        for(int j = N - 1; j >= i; j--) {
            int cnt = psum[j + 1] - psum[i];
            int min_absent = std::min(min_prefix, min_suffix);
            dp[cnt][0] += 1;
            dp[cnt][min_absent] -= 1;
            if(A[j] != -1) {
                min_suffix = std::min(min_suffix, A[j]);
            }
        }
        if(A[i] != -1) {
            min_prefix = std::min(min_prefix, A[i]);
        }
    } 
    
    for(int i = 0; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            dp[i][j] += dp[i][j - 1]; 
        }
    }
    
    int absent = 0;
    for(int k = 0; k < N; k++) {
        if(!present[k]) {
            absent += 1;
        }
        for(int c = absent; c <= tot; c++) {
            int64_t x = (fact[c] * invf[absent] % MOD)* invf[c - absent] % MOD;
            x *= fact[absent] * fact[tot - absent] % MOD;
            x %= MOD;
            x *= dp[c][k];
            x %= MOD;
            ans += x;
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
