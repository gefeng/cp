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
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int64_t>> dp(N, std::vector<int64_t>(N, 0));
    for(int r = 0; r < N; r++) {
        for(int l = r; l >= 0; l--) {
            if(r - l + 1 > 2) {
                for(int i = l; i < r; i++) {
                    if(i != l) {
                        int64_t score = int64_t(A[l]) * A[i] * A[r];
                        if(l + 1 <= i - 1) {
                            score += dp[l + 1][i - 1];
                        }
                        if(i + 1 <= r - 1) {
                            score += dp[i + 1][r - 1];
                        }
                        dp[l][r] = std::max(dp[l][r], score);
                    }
                    dp[l][r] = std::max(dp[l][r], dp[l][i] + dp[i + 1][r]);
                }
            }
        }
    }
    
    std::cout << dp[0][N - 1] << '\n';
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
