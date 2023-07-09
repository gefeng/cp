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
    const int INF = 1e9;
public:
    int maximumJumps(std::vector<int>& nums, int target) {
        int n = nums.size();
        std::vector<int> dp(n, -INF);
        dp[0] = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(abs(nums[i] - nums[j]) <= target && dp[i] != -INF) {
                    dp[j] = std::max(dp[j], dp[i] + 1);
                }
            }
        }
        
        return dp[n - 1] == -INF ? -1 : dp[n - 1];
    }
};
