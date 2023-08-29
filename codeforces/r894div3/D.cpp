#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int64_t MAX = (int64_t)2e9;

void run_case() {
    int64_t N;
    std::cin >> N;

    if(N == 1) {
        std::cout << 2 << '\n';
        return;
    }

    int64_t lo = 2;
    int64_t hi = MAX;
    int64_t ans = 0;
    while(lo <= hi) {
        int64_t mid = (lo + hi) >> 1;
        int64_t tot = mid * (mid - 1) / 2;
        
        if(tot <= N) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    ans += N - ans * (ans - 1) / 2;

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
