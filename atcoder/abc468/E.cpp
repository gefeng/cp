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

    std::vector<int64_t> dp1(N + 1, 0);
    std::vector<int64_t> dp2(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        dp1[i] = (dp1[i - 1] + q_pow(i, MOD - 2)) % MOD;
    }

    for(int i = 1; i <= N; i++) {
        dp2[i] = (dp2[i - 1] + A[i - 1]) % MOD;
    }

    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        ans += dp2[i + 1] * dp1[i + 1] % MOD;
        ans %= MOD;
    }

    for(int i = 0; i < N; i++) {
        ans -= dp2[i] * dp1[N - i] % MOD;
        ans += MOD;
        ans %= MOD;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
