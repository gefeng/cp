#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    int64_t MOD;
    std::cin >> N >> MOD;

    int m = N * (N - 1) / 2;

    std::vector<std::vector<int64_t>> comb(N * N + 1, std::vector<int64_t>(N * N + 1, 0));
    comb[0][0] = 1;
    for(int i = 1; i <= N * N; i++) {
        comb[i][0] = 1;
        comb[i][i] = 1;
        for(int j = 1; j < i; j++) {
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
        }
    }

    std::vector<std::vector<std::vector<int64_t>>> g(N + 1, std::vector<std::vector<int64_t>>(N + 1, std::vector<int64_t>(m + 1, 0)));
    for(int i = 0; i <= N; i++) {
        g[i][0][0] = 1;
    }
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            int ub = std::min(m, i * j);
            for(int k = j; k <= ub; k++) {
                for(int s = j - 1; s <= std::min(k, i * (j - 1)); s++) {
                    if(k - s <= i && k - s > 0) {
                        g[i][j][k] += g[i][j - 1][s] * comb[i][k - s] % MOD;
                        g[i][j][k] %= MOD;
                    }
                }
            }
        }
    }

    // [#even_nodes, #odd_nodes, #even_or_odd, used_edges, #nodes_in_current_layer]
    std::vector<std::vector<std::vector<std::vector<std::vector<int64_t>>>>> dp(2, 
            std::vector<std::vector<std::vector<std::vector<int64_t>>>>(N + 1, 
                std::vector<std::vector<std::vector<int64_t>>>(N + 1, 
                    std::vector<std::vector<int64_t>>(m + 1, std::vector<int64_t>(N + 1, 0)))));

    dp[0][1][0][0][1] = 1;
    for(int i = 1; i <= N / 2; i++) {
        for(int j = 1; j <= N / 2; j++) {
            if(i + j > N) {
                continue;
            }

            std::vector<std::vector<std::vector<int64_t>>> ds(2, std::vector<std::vector<int64_t>>(m + 1, std::vector<int64_t>(N + 1, 0)));
            for(int f = 0; f < 2; f++) {
                int lb_e = i + j - 1;
                int ub_e = std::min(m, (i + j) * (i + j - 1) / 2);
                for(int k = lb_e; k <= ub_e; k++) {
                    int ub_l = f == 0 ? j : i;
                    for(int l = 1; l <= ub_l; l++) {
                        int ub = f == 0 ? i : j;
                        for(int s = 1; s <= ub; s++) {
                            int ub_t = std::min(k, s * l);
                            for(int t = s; t <= ub_t; t++) {
                                if(f == 1) {
                                    int64_t x = g[l][s][t] * comb[N - i - j + s][s] % MOD;
                                    dp[f][i][j][k][s] += dp[f ^ 1][i][j - s][k - t][l] * x % MOD;
                                    dp[f][i][j][k][s] %= MOD;
                                    ds[f][k][s] = dp[f][i][j][k][s];
                                } else {
                                    int64_t x = g[l][s][t] * comb[N - i - j + s][s] % MOD;
                                    dp[f][i][j][k][s] += dp[f ^ 1][i - s][j][k - t][l] * x % MOD;
                                    dp[f][i][j][k][s] %= MOD;
                                    ds[f][k][s] = dp[f][i][j][k][s];
                                }
                            }
                        }
                    }

                    
                }
            }

            // connect nodes in the current layer
            for(int f = 0; f < 2; f++) {
                int lb_e = i + j - 1;
                int ub_e = std::min(m, (i + j) * (i + j - 1) / 2);
                for(int k = lb_e; k <= ub_e; k++) {
                    int ub = f == 0 ? i : j;
                    for(int s = 2; s <= ub; s++) {
                        if((f == 0 && s > i) || (f == 1 && s > j)) {
                            continue;
                        }
                        for(int t = 1; t <= k; t++) {
                            int64_t pairs = comb[s][2];
                            if(t <= pairs) {
                                dp[f][i][j][k][s] += ds[f][k - t][s] * comb[pairs][t] % MOD;
                                dp[f][i][j][k][s] %= MOD;
                            }
                        }
                    }
                }
            }
        }
    }

    for(int i = N - 1; i <= m; i++) {
        int64_t res = 0;
        for(int j = 0; j <= N / 2; j++) {
            res += (dp[0][N / 2][N / 2][i][j] + dp[1][N / 2][N / 2][i][j]) % MOD;
            res %= MOD;
        }
        std::cout << res << " \n"[i == m];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
