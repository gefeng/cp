#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

constexpr LL INF = (LL)2e15;

void run_case() {
    std::string S;
    std::cin >> S;

    int n = S.size();

    std::vector<LL> p_10(5, 1);
    for(int i = 1; i < 5; i++) {
        p_10[i] = p_10[i - 1] * 10LL;
    }
    
    std::vector<std::vector<LL>> dp(2, std::vector<LL>(5, -INF));
    dp[0][S.back() - 'A'] = p_10[S.back() - 'A'];
    for(int i = 0; i < 5; i++) {
        dp[1][i] = p_10[i];
    }

    for(int i = 2; i <= n; i++) {
        std::vector<std::vector<LL>> ndp(2, std::vector<LL>(5, -INF));
        
        int c = S[n - i] - 'A';
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 5; k++) {
                if(dp[j][k] != -INF) {
                    if(c >= k) {
                        ndp[j][c] = std::max(ndp[j][c], dp[j][k] + p_10[c]);
                    } else {
                        ndp[j][k] = std::max(ndp[j][k], dp[j][k] - p_10[c]);
                    }
                }
            }
        }

        for(int j = 0; j < 5; j++) {
            for(int k = 0; k < 5; k++) {
                if(dp[0][k] != -INF) {
                    if(j >= k) {
                        ndp[1][j] = std::max(ndp[1][j], dp[0][k] + p_10[j]);
                    } else {
                        ndp[1][k] = std::max(ndp[1][k], dp[0][k] - p_10[j]);
                    }
                }
            } 
        }

        std::swap(dp, ndp);
    }

    LL ans = -INF;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 5; j++) {
            ans = std::max(ans, dp[i][j]);
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
