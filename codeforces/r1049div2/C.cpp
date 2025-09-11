#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = static_cast<int64_t>(2e18);

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t sum = 0;
    int64_t ans = -INF;
    for(int i = 0; i < N; i++) {
        sum += (i % 2 == 0 ? 1 : -1) * A[i];
    }

    ans = sum;

    int64_t max_v = -INF;
    int64_t min_v = INF;
    for(int i = 0; i < N; i++) {
        if(i) {
            if(i % 2 == 0) {
                ans = std::max(ans, sum + i);
                if(max_v != -INF) {
                    ans = std::max(ans, sum - (static_cast<int64_t>(2 * A[i]) - i) + max_v);
                }
            } else {
                ans = std::max(ans, sum + i - 1); 
                if(min_v != INF) {
                    ans = std::max(ans, sum + (static_cast<int64_t>(2 * A[i]) + i) - min_v);
                }
            }
        }

        if(i % 2 == 1) {
            max_v = std::max(max_v, static_cast<int64_t>(2 * A[i]) - i);
        } else {
            min_v = std::min(min_v, static_cast<int64_t>(2 * A[i]) + i);
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
