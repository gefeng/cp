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
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    std::vector<int> B(M);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    std::vector<int64_t> psum(N + 1, 0);
    for(int i = 0; i < N; i++) {
        psum[i + 1] = psum[i] + A[i];
    }

    int64_t ans = INF;
    std::vector<std::vector<int64_t>> dp(N + 1, std::vector<int64_t>(M + 1, INF));
    for(int k = 1; k <= M; k++) {
        dp[0][k] = 0;        
    }

    auto bs = [&](int r, int64_t t) {
        int lo = 0;
        int hi = r;
        int res = 0;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            if(psum[r] - psum[r - mid] <= t) {
                res = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return res;
    };

    for(int i = 1; i <= N; i++) {
        for(int k = 1; k <= M; k++) {
            dp[i][k] = dp[i][k - 1];
            
            int j = bs(i, B[k - 1]);
            if(j != 0) {
                dp[i][k] = std::min(dp[i][k], dp[i - j][k] + M - k);
            }
        }
    }

    for(int k = 1; k <= M; k++) {
        ans = std::min(ans, dp[N][k]);
    }
    std::cout << (ans == INF ? -1 : ans) << '\n';
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
