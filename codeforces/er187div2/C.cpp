#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MAX = static_cast<int64_t>(1e18);

void run_case() {
    int64_t S, M;
    std::cin >> S >> M;

    int64_t ans = -1;
    int64_t lo = 1;
    int64_t hi = MAX;
    while(lo <= hi) {
        int64_t mid = (lo + hi) >> 1;
        
        int64_t s = S;
        std::array<int64_t, 61> cnt{};
        for(int i = 60; i >= 0; i--) {
            int64_t x = static_cast<int64_t>(1) << i;
            if((M & x) && x <= s) {
                int64_t c = s / x;
                c = std::min(c, mid);
                cnt[i] += c; 
                s -= x * c;
            }
        }

        if(s == 0) {
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
