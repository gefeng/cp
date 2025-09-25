#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t L, R, P, K;
    std::cin >> L >> R >> P >> K;

    auto solve = [](int64_t r) {
        if(r % 4 == 0) {
            return r;
        }
        if(r % 4 == 1) {
            return int64_t(1);
        }
        if(r % 4 == 2) {
            return r + 1;
        }
        return int64_t(0);
    };

    int64_t ans = solve(R) ^ solve(L - 1);
    
    int64_t p = int64_t(std::pow(2, P));
    int64_t c1 = L >= K ? ((L - K) + p - 1) / p : 0;
    int64_t l = c1 * p + K;
    int64_t c2 = R >= K ? (R - K) / p : 0;
    int64_t r = c2 * p + K;

    if(l <= r && K <= R) {
        int64_t suffix = l & ((int64_t(1) << P) - 1);
        
        l >>= P;
        r >>= P;
        
        int64_t x = solve(r) ^ (l == 0 ? 0 : solve(l - 1));
        x <<= P;
        
        if((c2 - c1 + 1) % 2 == 1) {
            x ^= suffix;
        }

        ans ^= x;
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
