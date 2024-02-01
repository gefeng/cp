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
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<std::array<int, 3>> A(M);
    for(int i = 0; i < M; i++) {
        std::cin >> A[i][0] >> A[i][1] >> A[i][2];
    }

    
    // E(S) = E(x1) + E(x2) + ... + E(xm)
    // where xi is expected value of friendshipt i
    std::vector<int64_t> fact(K + 1, 1);
    std::vector<int64_t> invf(K + 1, 1);
    int64_t nc2 = ((int64_t)N * (N - 1) % MOD) * q_pow(2, MOD - 2) % MOD;
    int64_t rnc2 = q_pow(nc2, MOD - 2);

    for(int i = 1; i <= K; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    for(int i = 1; i <= K; i++) {
        invf[i] = q_pow(fact[i], MOD - 2);
    }

    int64_t a = 0;
    int64_t b = 0;
    for(int i = 1; i <= K; i++) {
        int64_t p = q_pow(rnc2, i) * q_pow((1 - rnc2 + MOD) % MOD, K - i) % MOD;
        p *= (fact[K] * invf[i] % MOD) * invf[K - i] % MOD;
        p %= MOD; 

        a += i * p % MOD;
        a %= MOD;
        b += (((int64_t)i * (i - 1) / 2) % MOD) * p % MOD;
        b %= MOD;
    }

    int64_t ans = 0;
    for(int i = 0; i < M; i++) {
        ans += ((A[i][2] * a % MOD) + b) % MOD; 
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
