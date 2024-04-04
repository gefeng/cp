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
    long long countAlternatingSubarrays(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int64_t> dp(n + 1, 0);
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            if(nums[i - 1] == nums[i - 2]) {
                dp[i] = 1;
            } else {
                dp[i] = dp[i - 1] + 1;
            }
        }
        int64_t ans = 0;
        for(int i = 1; i <= n; i++) {
            ans += dp[i];
        }
        return ans;
    }
};
