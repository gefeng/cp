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
    int maximumLength(std::vector<int>& nums, int k) {
        int n = nums.size();
        
        std::vector<std::vector<int>> dp(n, std::vector<int>(k, 0));
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int rem = (nums[i] + nums[j]) % k;
                if(dp[j][rem] == 0) {
                    dp[i][rem] = std::max(dp[i][rem], 2);
                } else {
                    dp[i][rem] = std::max(dp[i][rem], dp[j][rem] + 1);
                }
                
                ans = std::max(ans, dp[i][rem]);
            }
        }
        
        return ans;
    }
};
