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
    long long minIncrementOperations(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<int64_t> dp(n + 1, INF);
        dp[0] = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= 3; j++) {
                if(i - j >= 0) {
                    dp[i] = std::min(dp[i], dp[i - j] + std::max(0, k - nums[i - 1]));
                }
            }
        }
        
        return std::min(dp[n], std::min(dp[n - 1], dp[n - 2]));
    }
};
