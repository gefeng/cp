#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int INF = int(2e9);

class Solution {
public:
    int maximumAmount(std::vector<std::vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();
        
        std::vector<std::vector<std::vector<int>>> dp(3, std::vector<std::vector<int>>(n, std::vector<int>(m, -INF)));
        
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < m; c++) {
                if(r == 0 && c == 0) {
                    dp[0][0][0] = coins[0][0];
                    if(coins[0][0] < 0) {
                        dp[1][0][0] = 0;
                    }
                } else {
                    if(r) {
                        for(int k = 0; k <= 2; k++) {
                            if(dp[k][r - 1][c] != -INF) {
                                dp[k][r][c] = std::max(dp[k][r][c], dp[k][r - 1][c] + coins[r][c]);
                            }
                            if(k - 1 >= 0 && dp[k - 1][r - 1][c] != -INF && coins[r][c] < 0) {
                                dp[k][r][c] = std::max(dp[k][r][c], dp[k - 1][r - 1][c]);
                            }
                        }
                    }
                    if(c) {
                        for(int k = 0; k <= 2; k++) {
                            if(dp[k][r][c - 1] != -INF) {
                                dp[k][r][c] = std::max(dp[k][r][c], dp[k][r][c - 1] + coins[r][c]);
                            }
                            if(k - 1 >= 0 && dp[k - 1][r][c - 1] != -INF && coins[r][c] < 0) {
                                dp[k][r][c] = std::max(dp[k][r][c], dp[k - 1][r][c - 1]);
                            }
                        }
                    }
                }
            }
        }
        
        int ans = -INF;
        for(int i = 0; i < 3; i++) {
            ans = std::max(ans, dp[i][n - 1][m - 1]);
        }
        return ans;
    }
};
