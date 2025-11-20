#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MAX = static_cast<int64_t>(1e12);

void run_case() {
    int64_t X, Y, K;
    std::cin >> X >> Y >> K;

    auto count = [&](int64_t t) {
        for(int _ = 0; _ < X; _++) {
            int64_t d = t / Y;  
            t -= d;
        }
        return t;
    };

    int64_t lo = 1;
    int64_t hi = MAX;
    int64_t ans = -1;
    while(lo <= hi) {
        int64_t mid = (lo + hi) >> 1;

        if(count(mid) >= K) {
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
