#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MAX = int64_t(2e18);

void run_case() {
    int64_t K;
    std::cin >> K;
    
    int64_t lo = K;
    int64_t hi = MAX;
    int64_t ans = 0;
    while(lo <= hi) {
        int64_t mid = (lo + hi) >> 1;
        
        int64_t x = int64_t(sqrtl(mid));
        if(mid - x >= K) {
            ans = mid;
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
