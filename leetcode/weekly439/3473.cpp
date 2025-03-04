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
    int maxSum(std::vector<int>& nums, int k, int m) {
        int n = nums.size();
        std::vector<int> psum(n + 1, 0);
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, -INF));
        std::vector<std::vector<int>> ds(n + 1, std::vector<int>(k + 1, -INF));
        
        for(int i = 0; i < n; i++) {
            psum[i + 1] = psum[i] + nums[i];
        }
        
        dp[0][0] = 0;
        ds[0][0] = 0;
        
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= std::min(i, k); j++) {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j]);
                if(j - 1 >= 0 && i - m >= 0) {
                    if(ds[i - m][j - 1] != -INF) {
                        dp[i][j] = std::max(dp[i][j], ds[i - m][j - 1] + psum[i]);
                    }
                }
                
                ds[i][j] = std::max(ds[i - 1][j], dp[i][j] - psum[i]);
            }
        }
        
        return dp[n][k];
    }
};
