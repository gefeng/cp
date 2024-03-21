#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map> 
#include <set>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    } 

    std::vector<std::vector<std::vector<int64_t>>> dp(2, 
            std::vector<std::vector<int64_t>>(2, std::vector<int64_t>(K + 1, -1)));
    dp[0][0][0] = 0;
    dp[0][1][0] = 0;
    
    for(int i = 1; i <= N; i++) {
        std::vector<std::vector<std::vector<int64_t>>> ndp(2, 
                std::vector<std::vector<int64_t>>(2, std::vector<int64_t>(K + 1, -1)));
        auto [c, v] = A[i - 1];
        for(int j = 0; j <= std::min(i, K); j++) {
            /*for(int k = 0; k <= N; k++) {
                // keep
                if(c != k && dp[j][k] != -1) {
                    ndp[j][c] = std::max(ndp[j][c], dp[j][k] + v);
                }

                // remove
                if(j && dp[j - 1][k] != -1) {
                    ndp[j][k] = std::max(ndp[j][k], dp[j - 1][k]);
                }
            }*/

            for(int k = 0; k < 2; k++) {
                int64_t x = c == dp[k][0][j] ? -1 : dp[k][1][j];
                if(x != -1) {
                    x += v;
                    if(x > ndp[0][1][j]) {
                        if(ndp[0][0][j] != c) {
                            ndp[1][0][j] = ndp[0][0][j];
                            ndp[1][1][j] = ndp[0][1][j];
                        }
                        
                        ndp[0][0][j] = c;
                        ndp[0][1][j] = x;
                    } else if(x > ndp[1][1][j]) {
                        if(ndp[0][0][j] != c) {
                            ndp[1][0][j] = c;
                            ndp[1][1][j] = x;
                        }
                    }
                }

                if(j) {
                    x = dp[k][1][j - 1];
                    int pre_c = dp[k][0][j - 1];

                    if(x > ndp[0][1][j]) {
                        if(ndp[0][0][j] != pre_c) {
                            ndp[1][0][j] = ndp[0][0][j];
                            ndp[1][1][j] = ndp[0][1][j];
                        }
                        ndp[0][0][j] = pre_c;
                        ndp[0][1][j] = x;
                    } else if(x > ndp[1][1][j]) {
                        if(ndp[0][0][j] != pre_c) {
                            ndp[1][0][j] = pre_c;
                            ndp[1][1][j] = x;
                        }
                    }
                }
            }
        }

        std::swap(dp, ndp);
    }

    int64_t ans = -1;
    for(int i = 0; i <= N; i++) {
        ans = std::max(ans, dp[0][1][K]);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
