#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

constexpr int64_t INF = int64_t(2e18);

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<std::vector<int>> G(N, std::vector<int>(N, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> G[i][j];
        }
    }
    
    std::vector<std::vector<int64_t>> ans(N, std::vector<int64_t>(N, INF));
    for(int t = K; t < N; t++) {
        std::vector<int> a(K + 1, 0);
        std::iota(a.begin(), a.end(), 0);
        a.back() = t;
        
        std::vector<std::vector<int64_t>> dp(N, std::vector<int64_t>(1 << (K + 1), INF));
        for(int i = 0; i < K + 1; i++) {
            dp[a[i]][1 << i] = 0;
        }

        for(int m = 1; m < (1 << (K + 1)); m++) {
            for(int sm = m; sm > 0; sm = (sm - 1) & m) {
                if(sm == m) {
                    continue;
                }                
                for(int i = 0; i < N; i++) {
                    dp[i][m] = std::min(dp[i][m], dp[i][sm] + dp[i][m ^ sm]);
                }
            }

            // similar to shortest path, but with a virtual start point
            std::vector<int> vis(N, 0);
            for(int i = 0; i < N; i++) {
                int v = -1;
                for(int j = 0; j < N; j++) {
                    if(!vis[j] && (v == -1 || dp[v][m] > dp[j][m])) {
                        v = j;
                    }
                } 

                if(v == -1 || dp[v][m] == INF) {
                    break;
                }

                vis[v] = 1;
                for(int j = 0; j < N; j++) {
                    if(dp[v][m] + G[v][j] < dp[j][m]) {
                        dp[j][m] = dp[v][m] + G[v][j];
                    }
                }
            }
        } 

        for(int i = 0; i < N; i++) {
            ans[i][t] = std::min(ans[i][t], dp[i][(1 << (K + 1)) - 1]);
        }
    }

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int S, T;
        std::cin >> S >> T;
        S -= 1;
        T -= 1;
        std::cout << ans[S][T] << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
