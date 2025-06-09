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
    int64_t N, G, B;
    std::cin >> N >> G >> B;

    int64_t lo = N;
    int64_t hi = MAX;
    int64_t ans = -1;

    while(lo <= hi) {
        int64_t mid = (lo + hi) >> 1;
        
        int64_t t = mid / (G + B);
        int64_t rem = std::min(G, mid % (G + B));
        
        if(t * G + rem >= (N + 1) / 2) {
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
