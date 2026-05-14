#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MAX = static_cast<int64_t>(2e18);

void run_case() {
    int N;
    int64_t K;
    std::cin >> N >> K;

    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t lo = *std::ranges::min_element(A);
    int64_t hi = MAX;
    int64_t ans = lo;
    while(lo <= hi) {
        int64_t mid = (lo + hi) >> 1;
        
        int64_t sum = 0;
        bool ok = true;
        for(int i = 0; i < N; i++) {
            int64_t d = std::max(static_cast<int64_t>(0), mid - A[i]);
            sum += (d + i) / (i + 1);
            if(sum > K) {
                ok = false;
                break;
            }
        }

        if(ok) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
