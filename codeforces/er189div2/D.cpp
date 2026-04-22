#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = static_cast<int64_t>(998244353);

void run_case() {
    int64_t N, X;
    std::cin >> N >> X;

    auto count_0 = [](int64_t r) {
        return (r < 3 ? 0 : (r - 2 + 3) / 4) + 1;
    };
    
    auto count_1 = [](int64_t r) {
        return (r + 3) / 4;
    };

    int64_t ans = 0;

    int64_t l = count_0(X - 1);
    int64_t r = count_0(N) - count_0(X - 1);
    ans += (l % MOD) * (r % MOD) % MOD;
    ans %= MOD;
    
    l = count_1(X - 1);
    r = count_1(N) - count_1(X - 1);
    ans += (l % MOD) * (r % MOD) % MOD;
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
