#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int INF = int(2e9);

void run_case() {
    int N, K;
    std::cin >> N >> K;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int lo = 1;
    int hi = int(1e9);
    int ans = 0;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;

        std::vector<int> b(N);
        for(int i = 0; i < N; i++) {
            if(A[i] >= mid) {
                b[i] = 1;
            } else {
                b[i] = -1;
            }
        }

        std::vector<int> dp(N, -INF);
        dp[0] = b[0];
        for(int i = 1; i < N; i++) {
            if(i % K == 0) {
                dp[i] = std::max(dp[i - K], b[i]);
            } else {
                dp[i] = std::max(dp[i], dp[i - 1] + b[i]);
                if(i - K >= 0) {
                    dp[i] = std::max(dp[i], dp[i - K]);
                }
            }
        } 

        if(dp[N - 1] > 0) {
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
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
