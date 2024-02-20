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
    int dfs(std::vector<int>& nums, int t, int st, int ed, std::vector<std::vector<int>>& dp) {
        if(st >= ed) {
            return 0;
        }
        if(dp[st][ed] != -1) {
            return dp[st][ed];
        }
        
        int res = 0;
        if(nums[st] + nums[st + 1] == t) {
            res = std::max(res, dfs(nums, t, st + 2, ed, dp) + 1);
        }
        if(nums[st] + nums[ed] == t) {
            res = std::max(res, dfs(nums, t, st + 1, ed - 1, dp) + 1);
        }
        if(nums[ed] + nums[ed - 1] == t) {
            res = std::max(res, dfs(nums, t, st, ed - 2, dp) + 1);
        }
        
        return dp[st][ed] = res;
    }
    
    int maxOperations(std::vector<int>& nums) {
        int n = nums.size();
        
        int ans = 0;
        std::array<int, 3> t = {nums[0] + nums[1], nums[0] + nums.back(), nums.back() + nums[n - 2]};
        
        for(int s : t) {
            std::vector<std::vector<int>> dp(n, std::vector<int>(n, -1));
            ans = std::max(ans, dfs(nums, s, 0, n - 1, dp));
        }
        
        return ans;
    }
};
