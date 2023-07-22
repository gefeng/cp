#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int64_t INF = (int64_t)1e18;

class Solution {
public:
    long long maxScore(std::vector<int>& nums, int x) {
        int n = nums.size();
        std::vector<int64_t> dp(2, -INF);
        dp[nums[0] % 2] = nums[0];
        
        for(int i = 1; i < n; i++) {
            int v = nums[i];
            int p = v % 2;
            
            dp[p] = std::max(dp[p] == -INF ? -INF : dp[p] + v, dp[p ^ 1] == -INF ? -INF : dp[p ^ 1] + v - x);
        }
        
        return std::max(dp[0], dp[1]);
    }
};
