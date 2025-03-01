#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int INF = int(2e9) + 10;

class Solution {
public:
    int minCost(std::vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) {
            return nums[0];
        }
        if(n == 2) {
            return std::max(nums[0], nums[1]);
        }
        
        std::vector<int> dp(n, INF);
        dp[0] = std::max(nums[1], nums[2]);
        dp[1] = std::max(nums[0], nums[2]);
        dp[2] = std::max(nums[0], nums[1]);
        
        for(int i = 3; i < n; i += 2) {
            if(i == n - 1) {
                int min_cost = INF;
                for(int j = 0; j < i; j++) {
                    if(dp[j] != INF) {
                        min_cost = std::min(min_cost, dp[j] + std::max(nums[j], nums[i]));
                    }
                }
                return min_cost;
            } 
            if(i + 1 < n) {
                std::vector<int> ndp(n, INF);
                int a = nums[i];
                int b = nums[i + 1];
                for(int j = 0; j < i; j++) {
                    if(dp[j] == INF) {
                        continue;
                    }
                    int c = nums[j];
                    ndp[i + 1] = std::min(ndp[i + 1], dp[j] + std::max(c, a));
                    ndp[i] = std::min(ndp[i], dp[j] + std::max(c, b));
                    ndp[j] = std::min(ndp[j], dp[j] + std::max(a, b));
                }
                std::swap(dp, ndp);
            }
        }
        
        int ans = INF;
        for(int i = 0; i < n; i++) {
            if(dp[i] == INF) {
                continue;
            }
            ans = std::min(ans, dp[i] + nums[i]);
        }
        return ans;
    }
};
