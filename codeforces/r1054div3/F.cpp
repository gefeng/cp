#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int H, D;
    std::cin >> H >> D;

    auto check = [&](int64_t b) {
        int64_t x = D / (b + 1);
        int64_t r = D % (b + 1);
        
        int64_t h1 = (x + 1) * x / 2;
        int64_t h2 = (x + 2) * (x + 1) / 2;
        int64_t sum = h2 * r + h1 * (b + 1 - r) - b;
        
        return sum < H;
    };

    int64_t lo = 0;
    int64_t hi = D;
    int64_t ans = -1;
    while(lo <= hi) {
        int64_t mid = (lo + hi) >> 1;
        
        if(check(mid)) {
            ans = D + mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
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
