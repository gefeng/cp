#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <tuple>

constexpr int64_t INF = int64_t(2e18);

void run_case() {
    int N, W;
    std::cin >> N >> W;
    
    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    std::sort(A.begin(), A.end());

    std::vector<std::vector<int64_t>> dp(W + 1, std::vector<int64_t>(W + 1, -INF));
    dp[0][0] = 0;
    
    for(int i = 1, p = 0; i <= W; i++) {
        if(p == N || A[p].first != i) {
            for(int j = 0; j <= W; j++) {
                dp[i][j] = dp[i - 1][j];
            }
        } else {
            int st = p;
            while(p < N && A[p].first == i) {
                p += 1;
            }
            
            int w = A[st].first;
            int cnt = W / w;
            std::vector<int64_t> f(cnt + 1, 0);
            std::priority_queue<std::tuple<int64_t, int, int>> pq;
            for(int k = st; k < p; k++) {
                pq.emplace(A[k].second - 1, k, 0);
            }
            for(int k = 1; k <= cnt; k++) {
                auto [v, idx, t] = pq.top();
                pq.pop();
                f[k] = f[k - 1] + v;
                t += 1;
                v = A[idx].second - 2 * t - 1;
                pq.emplace(v, idx, t);
            }
            
            for(int j = 0; j <= W; j++) {
                dp[i][j] = dp[i - 1][j]; 
                for(int k = 1; ; k++) {
                    int pre = j - k * w;
                    if(pre < 0) {
                        break;
                    }
                    if(dp[i - 1][pre] != -INF) {
                        dp[i][j] = std::max(dp[i][j], dp[i - 1][pre] + f[k]);
                    }
                }
            }
        }
    } 

    int64_t ans = -INF;
    for(int i = 0; i <= W; i++) {
        ans = std::max(ans, dp[W][i]);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
