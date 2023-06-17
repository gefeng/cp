#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

using LL = long long;
constexpr LL INF = (LL)2e18;

class Solution {
public:
    long long minCost(std::vector<int>& nums, int x) {
        int n = nums.size();
        
        std::vector<std::vector<LL>> dp(n, std::vector<LL>(n, INF));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0) {
                    dp[i][j] = nums[j];
                } else {
                    dp[i][j] = std::min(dp[i - 1][j], 1LL * nums[(j - i + n) % n]);
                }
            }
        }
        
        LL ans = INF;
        for(int i = 0; i < n; i++) {
            LL cost = 1LL * i * x;
            for(int j = 0; j < n; j++) {
                cost += dp[i][j];
            }
            
            ans = std::min(ans, cost);
        }
        
        return ans;
    }
};
