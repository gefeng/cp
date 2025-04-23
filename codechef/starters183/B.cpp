#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t N, M;
    std::cin >> N >> M;

    int64_t tot = N * (N - 1) / 2;
    int64_t most = 0;
    int64_t least = 0;
    int64_t lo = 0;
    int64_t hi = N - 1;
    while(lo <= hi) {
        int64_t mid = (lo + hi) >> 1;
        int64_t cnt = (N - mid + N - 1) * mid / 2;

        if(cnt <= M) {
            most = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    least = std::max(int64_t(0), N - 1 - tot + M);

    int64_t ans = (least + most) * (most - least + 1) / 2;
    
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
