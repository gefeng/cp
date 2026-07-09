#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::string S, T;
    std::cin >> S >> T;

    int n = S.size();
    int m = T.size();
    
    std::vector<int> a(n + 1, 0);
    std::vector<int> b(m + 1, 0);
    
    for(int i = 0; i < n; i++) {
        a[i + 1] = (a[i] + S[i] - '0') % 10;
    }

    for(int i = 0; i < m; i++) {
        b[i + 1] = (b[i] + T[i] - '0') % 10;
    }

    if(a[n] != b[m]) {
        std::cout << -1 << '\n';
        return;
    }

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(i) {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j]);
            }
            if(j) {
                dp[i][j] = std::max(dp[i][j], dp[i][j - 1]);
            }
            if(i && j && a[i - 1] == b[j - 1]) {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }

    std::cout << dp[n][m] << '\n';
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
