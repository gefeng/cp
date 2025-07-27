#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void dfs(int K, std::vector<std::vector<int>>& G, std::vector<int>& A, int v, int p, std::vector<std::vector<std::vector<int64_t>>>& dp) {
    if(p != -1 && G[v].size() == 1) {
        dp[1][1][v] = A[v];
        dp[2][1][v] = A[v];
        return;
    }

    for(int nei : G[v]) {
        if(nei == p) {
            continue;
        }

        dfs(K, G, A, nei, v, dp);
        
        std::vector<std::vector<int64_t>> n_dp(3, std::vector<int64_t>(K + 1, 0));
        for(int i = 0; i <= K; i++) {
            for(int j = 0; j <= K; j++) {
                if(i + j <= K) {
                    n_dp[0][i + j] = std::max(n_dp[0][i + j], dp[0][i][v] + dp[0][j][nei]);
                    if(i) {
                        for(int s = 1; s < 3; s++) {
                            n_dp[s][i + j] = std::max(n_dp[s][i + j], dp[s][i][v] + dp[0][j][nei]);
                        }
                    }
                }

                if(j && i + j <= K) {
                    n_dp[0][i + j] = std::max(n_dp[0][i + j], dp[0][i][v] + dp[1][j][nei]);
                    n_dp[1][i + j] = std::max(n_dp[1][i + j], dp[0][i][v] + dp[1][j][nei] + A[v]);
                    if(i) {
                        n_dp[1][i + j] = std::max(n_dp[1][i + j], dp[1][i][v] + dp[1][j][nei]);
                        n_dp[2][i + j] = std::max(n_dp[2][i + j], dp[2][i][v] + dp[1][j][nei]);
                    }
                }

                if(i + j - 1 > 0 && i + j - 1 <= K && i && j) {
                    n_dp[2][i + j - 1] = std::max(n_dp[2][i + j - 1], dp[1][i][v] + dp[1][j][nei]);
                }

                if(j && i + j <= K) {
                    n_dp[0][i + j] = std::max(n_dp[0][i + j], dp[0][i][v] + dp[2][j][nei]);
                    if(i) {
                        for(int s = 1; s < 3; s++) {
                            n_dp[s][i + j] = std::max(n_dp[s][i + j], dp[s][i][v] + dp[2][j][nei]);
                        }
                    }
                }
            }
        }
        
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j <= K; j++) {
                dp[i][j][v] = std::max(dp[i][j][v], n_dp[i][j]);
            }
        }
    }
}

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    std::vector<std::vector<std::vector<int64_t>>> dp(3, std::vector<std::vector<int64_t>>(K + 1, std::vector<int64_t>(N, 0)));

    dfs(K, G, A, 0, -1, dp);

    int64_t ans = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j <= K; j++) {
            ans = std::max(ans, dp[i][j][0]);
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
