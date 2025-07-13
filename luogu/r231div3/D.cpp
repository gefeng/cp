#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(998244353);
constexpr int MAX = int(1e7);

std::vector<int64_t> fact(MAX + 1, 1);

void run_case() {
    int N, M, K;
    std::cin >> N >> M >> K;

    if(N == 1) {
        std::cout << fact[N] << '\n';
        return;
    }

    if(M == 0) {
        std::cout << fact[N] * K % MOD << '\n';
        return;
    }
    
    int64_t ans = 0;
    int cnt_div = 0;

    for(int f = 1; f * f <= M; f++) {
        if(M % f == 0 && f <= N) {
            cnt_div += 1;
            
            ans += fact[N - 1] * K % MOD;
            ans %= MOD;

            if(M / f != f && M / f <= N) {
                cnt_div += 1;
                
                ans += fact[N - 1] * K % MOD;
                ans %= MOD;
            }
        }
    }

    int64_t x = N % 2 == 0 ? int64_t(N / 2) * (N + 1) : int64_t(N + 1) / 2 * N;
    x %= MOD;

    ans += (((x - K + MOD) % MOD) * fact[N - 2] % MOD) * (N - cnt_div) % MOD;
    ans %= MOD;

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    for(int i = 1; i <= MAX; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
