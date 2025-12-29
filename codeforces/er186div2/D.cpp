#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

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

    std::vector<int> A(N + 1);
    for(int i = 0; i < N + 1; i++) {
        std::cin >> A[i];
    }

    std::ranges::sort(A.begin() + 1, A.end());

    int min_v = A[1];
    for(int i = 1; i <= N; i++) {
        A[i] -= min_v;
    }

    int need = 0;
    for(int i = 1; i <= N; i++) {
        need += A.back() - A[i];
    }

    int d = std::max(0, need - A[0]);
    int cnt = std::ranges::count(A.begin() + 1, A.end(), A.back());
    
    if(cnt + d > N) {
        std::cout << 0 << '\n';
        return;
    }

    std::vector<int64_t> fact(N + 1, 1);
    std::vector<int64_t> invf(N + 1, 1);
    for(int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invf[i] = q_pow(fact[i], MOD - 2);
    }

    if(d == 0) {
        std::cout << fact[N] << '\n';
        return;
    }

    int64_t ans = (fact[N - d] * invf[cnt] % MOD) * invf[N - d - cnt] % MOD;
    ans *= fact[N - cnt];
    ans %= MOD;
    ans *= fact[cnt];
    ans %= MOD;

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
