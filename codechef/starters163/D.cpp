#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MAX = int64_t(1e18);

void run_case() {
    int64_t X, N;
    std::cin >> X >> N;

    auto solve = [&](int64_t u) {
        int64_t sum = u;
        int steps = 1;
        while(steps < N && u > 1) {
            u /= 2;
            sum += u;
            steps += 1;
        }
        return sum;
    };

    int64_t lo = 1;
    int64_t hi = MAX;
    int64_t ans = -1;
    while(lo <= hi) {
        int64_t mid = (lo + hi) >> 1;
        
        int64_t sum = solve(mid);
        if(sum == X) {
            ans = mid;
            break;
        }
        
        if(sum > X) {
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
