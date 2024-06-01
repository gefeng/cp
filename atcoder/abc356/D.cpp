#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)998244353;

void run_case() {
    int64_t N, M;
    std::cin >> N >> M;
    
    N += 1; 
    int64_t p2 = 2;
    int64_t ans = (M & 1) ? N / 2 : 0;
    ans %= MOD; 

    while(p2 <= N) {
        int64_t x = N / p2;

        if(M & p2) {
            ans += (x / 2) * (p2 % MOD) % MOD;
            ans %= MOD;
            ans += (x & 1) ? (N % p2) : 0;
            ans %= MOD;
        }

        p2 <<= 1;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
