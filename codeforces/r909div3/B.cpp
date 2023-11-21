#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = (int64_t)1e18;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t ans = 0;
    for(int k = 1; k <= N; k++) {
        if(N % k != 0) {
            continue;
        }

        int64_t min_v = INF;
        int64_t max_v = 0;
        int64_t sum = 0;
        for(int i = 0, j = 1; i < N; i++) {
            sum += A[i];
            if(j == k) {
                min_v = std::min(min_v, sum);
                max_v = std::max(max_v, sum);
                sum = 0;
                j = 1;
            } else {
                j += 1;
            }
        }

        ans = std::max(ans, max_v - min_v);
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
