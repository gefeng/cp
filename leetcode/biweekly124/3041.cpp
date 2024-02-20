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
    int maxSelectedElements(std::vector<int>& nums) {
        int n = nums.size();

        std::sort(nums.begin(), nums.end());
        
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(2, 0));
        dp[1][0] = 1;
        dp[1][1] = 1;
        int ans = 1;
        for(int i = 2; i <= n; i++) {
            int pre = nums[i - 2];
            int cur = nums[i - 1];
            
            dp[i][0] = 1;
            dp[i][1] = 1;
            
            if(cur == pre + 1) {
                dp[i][0] = std::max(dp[i][0], dp[i - 1][0] + 1);
                dp[i][1] = std::max(dp[i][1], dp[i - 1][1] + 1);
            } else if(cur == pre + 2) {
                dp[i][0] = std::max(dp[i][0], dp[i - 1][1] + 1);
            } else if(cur == pre) {
                dp[i][1] = std::max(dp[i][1], dp[i - 1][0] + 1);
                
                // not pick
                dp[i][0] = std::max(dp[i][0], dp[i - 1][0]);
                dp[i][1] = std::max(dp[i][1], dp[i - 1][1]);
            }
            
            ans = std::max(ans, std::max(dp[i][0], dp[i][1]));
        }
        
        return ans;
    }
};
