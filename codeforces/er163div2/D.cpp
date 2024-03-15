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
    
    int n = S.size();
    int ans = 0;
    
    std::vector<std::vector<int>> dp(n, std::vector<int>(n + 1, 0));
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i - j >= 0) {
                dp[i][j] = (S[i] == S[i - j] || S[i] == '?' || S[i - j] == '?') ? dp[i - 1][j] + 1 : 0;
                if(dp[i][j] >= j) {
                    ans = std::max(ans, j * 2);
                }
            }
        } 
    }

    std::cout << ans << '\n';
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
