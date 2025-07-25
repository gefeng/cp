#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(998244353);

void run_case() {
    int64_t N;
    std::cin >> N;
    
    int64_t ans = 0;
    if((N - 2) % 2 == 0) {
        ans = (((N - 2) / 2) % MOD) * ((N - 1) % MOD);
    } else {
        ans = (((N - 1) / 2) % MOD) * ((N - 2) % MOD);
    }

    ans %= MOD;

    int64_t x = N;
    for(int64_t l = 2; l < N; ) {
        int64_t r = x / (x / l);
        int64_t q = x / l;
        ans -= ((q - 1) % MOD) * (r - l + 1) % MOD;
        ans += MOD;
        ans %= MOD;
        l = r + 1;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
