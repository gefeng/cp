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

    int64_t ans = 0;
    if(N % 2 == 0) {
        std::vector<int64_t> dp(N, 0);
        ans = INF;
        for(int i = N - 2; i > 1; i -= 2) {
            int d = std::max(0, std::max(A[i - 1], A[i + 1]) - A[i] + 1);
            dp[i] = (i + 2 < N ? dp[i + 2] : 0) + d;
        }

        int64_t now = 0;
        for(int i = 1; i < N - 1; i += 2) {
            int d = std::max(0, std::max(A[i - 1], A[i + 1]) - A[i] + 1);
            ans = std::min(ans, now + dp[i + 1]);
            now += d;
        }
        ans = std::min(ans, now);
    } else {
        for(int i = 1; i < N - 1; i += 2) {
            ans += std::max(0, std::max(A[i - 1], A[i + 1]) - A[i] + 1);
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
