#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = int64_t(2e18);

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> dp(N, INF);
    dp[N - 1] = A[N - 1];

    int min_v = A.back();
    std::vector<int> pos;
    pos.push_back(N - 1);
    for(int i = N - 2; i >= 0; i--) {
        if(A[i] <= min_v) {
            if(A[i] < min_v) {
                pos.clear();
                pos.push_back(i);
                min_v = A[i];
            }

            int r = pos.size() == 1 ? N : i + 1;
            for(int k = i; k < r; k++) {
                int64_t len = k - i + 1;
                int64_t cost = k >= i ? k - i : 0;
                cost += k >= i ? min_v * len + len - 1 : (min_v + 1) * len;
                dp[i] = std::min(dp[i], cost + (k + 1 == N ? 0 : dp[k + 1]));
            }
        } else {
            dp[i] = dp[i + 1] + min_v + 1; 
        }
    }

    std::cout << dp[0] << '\n';
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
