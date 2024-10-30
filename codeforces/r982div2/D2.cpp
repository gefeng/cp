#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = int64_t(2e18);
constexpr int64_t MOD = int64_t(1e9) + 7;

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
    std::vector<std::vector<int64_t>> dp(M + 1, std::vector<int64_t>(N + 1, INF));
    std::vector<std::vector<int64_t>> ds(M + 1, std::vector<int64_t>(N + 1, 0));
    for(int k = 1; k <= M; k++) {
        dp[k][0] = 0;        
        ds[k][0] = 1;
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

    for(int k = 1; k <= M; k++) {
        std::vector<int64_t> psum(N + 2, 0);
        psum[1] = ds[k][0];
        for(int i = 1; i <= N; i++) {
            if(i < N) {
                dp[k][i] = dp[k - 1][i]; 
                ds[k][i] = ds[k - 1][i];
            }
            
            int j = bs(i, B[k - 1]);
            if(j != 0) {
                int64_t min_v = dp[k][i - j] + M - k;
                
                if(min_v < dp[k][i]) {
                    dp[k][i] = min_v;
                    int p = std::upper_bound(dp[k].begin() + i - j, dp[k].begin() + i, dp[k][i - j]) - dp[k].begin();
                    ds[k][i] = (psum[p] - psum[i - j] + MOD) % MOD;
                } else if(min_v == dp[k][i]) {
                    int p = std::upper_bound(dp[k].begin() + i - j, dp[k].begin() + i, dp[k][i - j]) - dp[k].begin();
                    ds[k][i] += (psum[p] - psum[i - j] + MOD) % MOD;
                    ds[k][i] %= MOD;
                }
            }

            psum[i + 1] = psum[i] + ds[k][i];
            psum[i + 1] %= MOD;
        }
    }

    for(int k = 1; k <= M; k++) {
        ans = std::min(ans, dp[k][N]);
    }

    if(ans == INF) {
        std::cout << -1 << '\n';
        return;
    }
    
    int64_t cnt = 0;
    for(int k = 1; k <= M; k++) {
        if(dp[k][N] == ans) {
            cnt += ds[k][N];
            cnt %= MOD;
        }
    }

    std::cout << ans << ' ' << cnt << '\n';
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
