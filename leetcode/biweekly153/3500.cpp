#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int64_t INF = int64_t(2e18);

class Solution {
public:
    long long minimumCost(std::vector<int>& nums, std::vector<int>& cost, int k) {
        int n = nums.size();
        int64_t ans = INF;
        
        std::vector<int64_t> psum(n + 1, 0);
        for(int i = 0; i < n; i++) {
            psum[i + 1] = psum[i] + cost[i];
        }
        
        std::vector<int64_t> dp(n + 1, INF);
        dp[0] = 0;
        
        int64_t prefix = 0;
        for(int i = 1; i <= n; i++) {
            prefix += nums[i - 1];
            
            for(int j = 0; j < i; j++) {
                dp[i] = std::min(dp[i], dp[j] + prefix * (psum[i] - psum[j]) + k * (psum[n] - psum[j]));    
            }
        }
        
        return dp[n];
    }
};
