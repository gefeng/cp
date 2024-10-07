#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(998244353);

void run_case(int T) {
    int64_t W, G, L;
    std::cin >> W >> G >> L;
    
    int64_t ans = ((W - G) % MOD) * (((2 * L % MOD) + 1) % MOD) % MOD;

    std::cout << "Case #" << T << ": " << ans << '\n';
}

int main() {
    int T;
    std::cin >> T;
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }
}
