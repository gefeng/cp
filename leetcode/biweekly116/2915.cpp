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
    int lengthOfLongestSubsequence(std::vector<int>& nums, int target) {
        int n = nums.size();
        std::vector<int> dp(target + 1, -1);
        dp[0] = 0;
        
        for(int i = 0; i < n; i++) {
            std::vector<int> ndp(target + 1, -1);
            
            for(int j = 0; j <= target; j++) {
                ndp[j] = std::max(ndp[j], dp[j]);
                
                if(j + nums[i] <= target && dp[j] != -1) {
                    ndp[j + nums[i]] = std::max(ndp[j + nums[i]], dp[j] + 1);
                }
            }
            std::swap(dp, ndp);
        }
        
        return dp[target];
    }
};
