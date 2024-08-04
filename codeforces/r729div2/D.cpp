#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(998244353);

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        char T;
        std::cin >> T;
        if(T == '+') {
            int X;
            std::cin >> X;

            A[i] = {0, X};
        } else {
            A[i] = {1, 0};
        }
    }
    
    int64_t ans = 0;
    for(int k = 0; k < N; k++) {
        if(A[k].first == 1) {
            continue; 
        }

        std::vector<std::vector<int64_t>> dp(N + 1, std::vector<int64_t>(N, 0));
        dp[0][0] = 1;
        
        for(int i = 1; i <= N; i++) {
            if(A[i - 1].first == 1) {
                for(int j = 0; j < N; j++) {
                    dp[i][j] += dp[i - 1][j];
                    dp[i][j] %= MOD;

                    if(j + 1 < N) {
                        dp[i][j] += dp[i - 1][j + 1];
                        dp[i][j] %= MOD;
                    }

                    if(j == 0 && i - 1 < k) {
                        dp[i][0] += dp[i - 1][0];
                        dp[i][0] %= MOD;
                    }
                }
            } else {
                if(i - 1 == k) {
                    for(int j = 0; j < N; j++) {
                        dp[i][j] = dp[i - 1][j];
                    }
                    continue;
                }

                for(int j = 0; j < N; j++) {
                    dp[i][j] += dp[i - 1][j];
                    dp[i][j] %= MOD;

                    if((A[i - 1].second > A[k].second) || (A[i - 1].second == A[k].second && i - 1 > k)) {
                        dp[i][j] += dp[i - 1][j];
                        dp[i][j] %= MOD;
                    }

                    if(j && (A[i - 1].second < A[k].second || (A[i - 1].second == A[k].second && i - 1 < k))) {
                        dp[i][j] += dp[i - 1][j - 1];
                        dp[i][j] %= MOD;
                    }
                }

            }
        }

        int64_t sum = 0;
        for(int i = 0; i < N; i++) {
            sum += dp[N][i];
            sum %= MOD;
        }

        ans += sum * A[k].second % MOD;
        ans %= MOD;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
