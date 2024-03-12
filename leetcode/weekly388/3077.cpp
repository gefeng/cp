#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int64_t INF = (int64_t)2e18;

class Solution {
public:
    long long maximumStrength(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<std::vector<std::vector<int64_t>>> dp(n + 1, std::vector<std::vector<int64_t>>(k + 1, std::vector<int64_t>(2, -INF)));
        
        for(int i = 0; i <= n; i++) {
            dp[i][0][0] = 0;
        }
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= std::min(i, k); j++) {
                dp[i][j][0] = std::max(dp[i - 1][j][0], dp[i - 1][j][1]);
                
                if(dp[i - 1][j - 1][1] != -INF) {
                    int64_t cost = j % 2 == 0 ? (int64_t)-j * nums[n - i] : (int64_t)j * nums[n - i];
                    dp[i][j][1] = std::max(dp[i][j][1], dp[i - 1][j - 1][1] + cost);
                }
                if(dp[i - 1][j - 1][0] != -INF) {
                    int64_t cost = j % 2 == 0 ? (int64_t)-j * nums[n - i] : (int64_t)j * nums[n - i];
                    dp[i][j][1] = std::max(dp[i][j][1], dp[i - 1][j - 1][0] + cost);
                }
                
                if(dp[i - 1][j][1] != -INF) {
                    int64_t cost = j % 2 == 0 ? (int64_t)-j * nums[n - i] : (int64_t)j * nums[n - i];
                    dp[i][j][1] = std::max(dp[i][j][1], dp[i - 1][j][1] + cost);
                }
            }
        }
        
        return std::max(dp[n][k][0], dp[n][k][1]);
    }
};
