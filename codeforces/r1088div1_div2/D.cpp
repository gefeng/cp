#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = static_cast<int64_t>(1e9) + 7;

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

    if(N == 1) {
        std::cout << A[0] << '\n';
        return;
    }

    std::vector<int64_t> fact(N + 1, 1);
    std::vector<int64_t> invf(N + 1, 1);

    for(int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invf[i] = q_pow(fact[i], MOD - 2);
    }

    std::vector<int> ans(N, 0);
    std::vector<std::pair<int64_t, int64_t>> c;
    
    if(A[N - 1] != 0) {
        c.emplace_back(N, A[N - 1]);
    }

    for(int k = N - 1; k > 0; k--) {
        int64_t sum = 0;
        for(auto [n, b] : c) {
            int64_t coef = (fact[n] * invf[k] % MOD) * invf[n - k] % MOD; 
            sum += coef * b % MOD;
            sum %= MOD;
        } 
        int64_t x = (A[k - 1] - sum + MOD) % MOD;
        if(x) {
            c.emplace_back(k, x);
        }
    }

    for(auto [k, x] : c) {
        for(int i = 0; i < k; i++) {
            ans[i] |= x;
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
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
