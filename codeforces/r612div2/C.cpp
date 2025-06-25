#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = int(2e9);

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<int> present(N + 1, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        present[A[i]] = 1;
    }

    int eve = 0;
    int odd = 0;
    for(int i = 1; i <= N; i++) {
        if(!present[i]) {
            if(i % 2 == 0) {
                eve += 1;
            } else {
                odd += 1;
            }
        }
    }

    std::vector<std::vector<std::vector<int>>> dp(2, std::vector<std::vector<int>>(eve + 1, std::vector<int>(odd + 1, INF)));
    if(A[0] == 0) {
        if(eve) {
            dp[0][eve - 1][odd] = 0;
        }
        if(odd) {
            dp[1][eve][odd - 1] = 0;
        }
    } else {
        dp[A[0] % 2][eve][odd] = 0;
    }
    
    for(int i = 1; i < N; i++) {
        std::vector<std::vector<std::vector<int>>> n_dp(2, std::vector<std::vector<int>>(eve + 1, std::vector<int>(odd + 1, INF)));
        
        for(int j = 0; j <= eve; j++) {
            for(int k = 0; k <= odd; k++) {
                for(int p = 0; p < 2; p++) {
                    if(dp[p][j][k] != INF) {
                        if(A[i] == 0) {
                            if(j - 1 >= 0) {
                                n_dp[0][j - 1][k] = std::min(n_dp[0][j - 1][k], dp[p][j][k] + (p == 0 ? 0 : 1));
                            }
                            if(k - 1 >= 0) {
                                n_dp[1][j][k - 1] = std::min(n_dp[1][j][k - 1], dp[p][j][k] + (p == 1 ? 0 : 1));
                            }
                        } else {
                            n_dp[A[i] % 2][j][k] = std::min(n_dp[A[i] % 2][j][k], dp[p][j][k] + (A[i] % 2 == p ? 0 : 1));
                        }
                    }
                }
            }
        }

        dp = std::move(n_dp);
    }

    std::cout << std::min(dp[0][0][0], dp[1][0][0]) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
