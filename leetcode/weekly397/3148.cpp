#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int INF = (int)2e9;

class Solution {
public:
    int maxScore(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, -INF));
        dp[n][m] = 0;
        
        int ans = -INF;
        for(int i = n; i > 0; i--) {
            for(int j = m; j > 0; j--) {
                if(i < n) {
                    dp[i][j] = std::max(dp[i][j], grid[i][j - 1] - grid[i - 1][j - 1]);
                    dp[i][j] = std::max(dp[i][j], dp[i + 1][j] + grid[i][j - 1] - grid[i - 1][j - 1]);
                }
                if(j < m) {
                    dp[i][j] = std::max(dp[i][j], grid[i - 1][j] - grid[i - 1][j - 1]);
                    dp[i][j] = std::max(dp[i][j], dp[i][j + 1] + grid[i - 1][j] - grid[i - 1][j - 1]);
                }
                if(i != n || j != m) {
                    ans = std::max(ans, dp[i][j]);
                }
            }            
        }
        
        return ans;
    }
};
