#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::string S;
    std::cin >> S;

    int K;
    std::cin >> K;

    int n = S.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            dp[i][j] = j - i + 1;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = i - 1; j >= 0; j--) {
            dp[j][i] = std::min(dp[j][i], dp[j + 1][i] + 1);

            if(S[j] == 'o') {
                if(j == i - 1 && S[i] == 'f') {
                    dp[j][i] = 0; 
                }

                for(int k = j + 1; k <= i; k++) {
                    if(S[k] == 'f' && dp[j + 1][k - 1] == 0) {
                        dp[j][i] = std::min(dp[j][i], k == i ? 0 : std::max(0, dp[k + 1][i] - K));
                    }
                } 
            }
        }
    }

    std::cout << dp[0][n - 1] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
