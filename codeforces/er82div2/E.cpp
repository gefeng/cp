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

    auto is_subseq = [](std::string& s, std::string& t) {
        int n = s.size();
        int m = t.size();
        int j = 0;
        for(int i = 0; i < n && j < m; i++) {
            if(s[i] == t[j]) {
                j += 1; 
            }
        }
        return j == m;
    };

    if(is_subseq(S, T)) {
        std::cout << "YES" << '\n';
        return;
    }

    for(int i = 0; i < m - 1; i++) {
        std::string prefix = T.substr(0, i + 1);
        std::string suffix = T.substr(i + 1, m - 1 - i);
        
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(i + 2, -1));
        for(int j = 0; j <= n; j++) {
            dp[j][0] = 0;
        }

        for(int j = 1; j <= n; j++) {
            for(int k = 0; k <= i + 1; k++) {
                dp[j][k] = std::max(dp[j][k], dp[j - 1][k]);
                if(k) {
                    if(dp[j - 1][k - 1] != -1 && S[j - 1] == prefix[k - 1]) {
                        dp[j][k] = std::max(dp[j][k], dp[j - 1][k - 1]);
                    }
                }
                
                int len = dp[j - 1][k];
                if(len != -1 && len < m - 1 - i && S[j - 1] == suffix[len]) {
                    dp[j][k] = std::max(dp[j][k], dp[j - 1][k] + 1); 
                }
            }

            if(dp[j][i + 1] == m - 1 - i) {
                std::cout << "YES" << '\n';
                return;
            }
        }
    }

    std::cout << "NO" << '\n';
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
