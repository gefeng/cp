#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(1e9) + 7;

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int64_t> p(30, 1);
    for(int i = 1; i < 30; i++) {
        p[i] = p[i - 1] * N % MOD;
    }

    int64_t ans = 0;
    for(int i = 0; i < 30; i++) {
        if(K & (1 << i)) {
            ans += p[i];
            ans %= MOD;
        }
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
