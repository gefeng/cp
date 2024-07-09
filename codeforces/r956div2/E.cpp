#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)1e9 + 7;

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

    int64_t a_s = (N - K + 2) / 2;
    int64_t a_ns = (N - K + 1) / 2;
    int64_t b_s = N - K + 1 - a_s;
    int64_t b_ns = N - K - a_ns;

    int64_t sum_s = 0;
    int64_t sum_ns = 0;
    for(int i = 0; i < K; i++) {
        sum_s += A[i];
        sum_s %= MOD;
    }

    for(int i = K; i < N; i++) {
        sum_ns += A[i];
        sum_ns %= MOD;
    }

    int64_t ans_a = (a_s * sum_s % MOD) * q_pow(N - K + 1, MOD - 2) % MOD;
    ans_a += (a_ns * sum_ns % MOD) * q_pow(N - K, MOD - 2) % MOD;
    ans_a %= MOD;

    int64_t ans_b = (b_s * sum_s % MOD) * q_pow(N - K + 1, MOD - 2) % MOD;
    ans_b += (b_ns * sum_ns % MOD) * q_pow(N - K, MOD - 2) % MOD;
    ans_b %= MOD;
    
    std::cout << ans_a << ' ' << ans_b << '\n';
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
