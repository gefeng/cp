#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = static_cast<int64_t>(998244353);

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
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> inv(N + 1, 1);
    for(int i = 1; i <= N; i++) {
        inv[i] = q_pow(i, MOD - 2);
    }

    int zeros = std::ranges::count(A, 0);

    std::vector<int64_t> dp(zeros + 1, 0);
    
    int cnt0 = 0;
    for(int i = 0; i < zeros; i++) {
        if(A[i] == 0) {
            cnt0 += 1;
        }
    }

    dp[zeros] = 0;
    for(int i = zeros - 1; i >= cnt0; i--) {
        int64_t p = ((zeros - i) * inv[N] % MOD) * ((zeros - i) * inv[N - 1] % MOD) % MOD;
        p *= 2;
        p %= MOD;

        dp[i] = (((dp[i + 1] * p % MOD) + 1) % MOD) * q_pow(p, MOD - 2) % MOD;
    }

    std::cout << dp[cnt0] << '\n';
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
