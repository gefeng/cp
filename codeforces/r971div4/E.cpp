#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t N, K;
    std::cin >> N >> K;
    
    int64_t lo = 1;
    int64_t hi = N;
    int64_t res = -1;
    while(lo <= hi) {
        int64_t mid = (lo + hi) >> 1;
        
        int64_t x = (K + K + mid - 1) * mid;
        int64_t y = (K + mid + K + N - 1) * (N - mid);
        if(x >= y) {
            res = mid;
            hi = mid - 1; 
        } else {
            lo = mid + 1;
        }
    }

    int64_t ans = (K + K + res - 1) * res - (K + res + K + N - 1) * (N - res);
    
    if(res > 1) {
        res -= 1;
        ans = std::min(ans, std::abs((K + K + res - 1) * res - (K + res + K + N - 1) * (N - res)));
    }

    std::cout << ans / 2 << '\n';
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
