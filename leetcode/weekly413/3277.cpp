#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<int> maximumSubarrayXor(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        
        std::vector<std::vector<int>> xor_range(n, std::vector<int>(n, 0));
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            xor_range[i][i] = nums[i];
            dp[i][i] = nums[i];
        }
        
        for(int k = 1; k <= n; k++) {
            for(int i = 0; i + k < n; i++) {
                xor_range[i][i + k] = xor_range[i + 1][i + k] ^ xor_range[i][i + k - 1];
            }
        }        
        
        for(int k = 1; k <= n; k++) {
            for(int i = 0; i + k < n; i++) {
                dp[i][i + k] = xor_range[i][i + k];
                dp[i][i + k] = std::max(dp[i][i + k], std::max(dp[i][i + k - 1], dp[i + 1][i + k]));
            }
        }
        
        std::vector<int> ans(m);
        for(int i = 0; i < m; i++) {
            ans[i] = dp[queries[i][0]][queries[i][1]]; 
        }
        return ans;
    }
};
