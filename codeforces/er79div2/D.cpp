#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(998244353);
constexpr int MAX = int(1e6);

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
    
    std::vector<std::vector<int>> A(N);
    std::vector<int> freq(MAX + 1, 0);
    for(int i = 0; i < N; i++) {
        int M;
        std::cin >> M;
        A[i].resize(M, 0);
        for(int j = 0; j < M; j++) {
            std::cin >> A[i][j];
            freq[A[i][j]] += 1;
        }
    }

    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        int m = A[i].size();
        int64_t p = q_pow(N, MOD - 2) * q_pow(m, MOD - 2) % MOD;
        for(int j = 0; j < m; j++) {
            int f = freq[A[i][j]];
            ans += (f * q_pow(N, MOD - 2) % MOD) * p % MOD;
            ans %= MOD;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
