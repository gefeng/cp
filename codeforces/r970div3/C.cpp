#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t L, R;
    std::cin >> L >> R;
    
    int64_t t = (R - L) * 2;
    int64_t lo = 0;
    int64_t hi = t;
    int64_t x = 0; 
    while(lo <= hi) {
        int64_t mid = (lo + hi) / 2;
        
        if(mid * (mid + 1) <= t) {
            x = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    std::cout << x + 1 << '\n';
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
