#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int INF = (int)1e9;

class Solution {
public:
    int paintWalls(std::vector<int>& cost, std::vector<int>& time) {
        int n = cost.size();
        
        // minimum cost to paint j walls by using first i options
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, INF));
        dp[0][0] = 0;
        
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                dp[i][j] = dp[i - 1][j];
                
                int k = std::max(0, j - time[i - 1] - 1);
                dp[i][j] = std::min(dp[i][j], dp[i - 1][k] + cost[i - 1]);
            }
        }
        
        return dp[n][n];
    }
};
