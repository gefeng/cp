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
    int K;
    std::cin >> K;

    int64_t ans = 0;

    for(int x = 2; x <= K - 4; x++) {
        int k = K - x;
        for(int y = 2; y <= k - 2; y++) {
            int z = k - y;
            int64_t sum = (static_cast<int64_t>(x - 1) * (y - 1) % MOD) * (z - 1) % MOD;
            sum *= K - std::max(x, std::max(y, z));
            sum %= MOD;
            ans += sum;
            ans %= MOD;
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
