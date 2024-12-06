#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::string A;
    std::string B;
    std::string C;

    std::cin >> A >> B >> C;

    int n = A.size();
    int m = B.size();
    std::vector<std::vector<int>> dp(n + m + 1, std::vector<int>(n + 1, 0));

    for(int i = 1; i <= n + m; i++) {
        char c = C[i - 1];
        for(int j = 0; j <= std::min(i, n); j++) {
            int k = i - j;
            if(k < 0 || k > m) {
                continue;
            }
            if(j == 0) {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j] + (c == B[k - 1] ? 1 : 0));
            } else if(k == 0) {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] + (c == A[j - 1] ? 1 : 0));
            } else {
                dp[i][j] = dp[i - 1][j];
                if(j != 0) {
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1]);
                }
                if(k != 0 && c == B[k - 1]) {
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][j] + 1);
                }
                if(j != 0 && c == A[j - 1]) {
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
        }
    }

    std::cout << n + m - dp[n + m][n] << '\n';
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
