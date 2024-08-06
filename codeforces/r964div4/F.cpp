#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

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
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int cnt_1 = 0;
    int cnt_0 = 0;
    for(int i = 0; i < N; i++) {
        cnt_1 += A[i];
    }
    cnt_0 = N - cnt_1;

    std::vector<int64_t> fact(N + 1, 1);
    std::vector<int64_t> invf(N + 1, 1);
    for(int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invf[i] = q_pow(fact[i], MOD - 2);
    }

    int64_t ans = 0;
    int n = std::min(K, cnt_1);
    for(int i = (K + 1) / 2; i <= n; i++) {
        if(K - i <= cnt_0) {
            int64_t pick_1 = (fact[cnt_1] * invf[i] % MOD) * invf[cnt_1 - i] % MOD;
            int64_t pick_0 = (fact[cnt_0] * invf[K - i] % MOD) * invf[cnt_0 - K + i] % MOD;
            ans += pick_1 * pick_0 % MOD;
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
