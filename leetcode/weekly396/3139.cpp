#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int MAX = (int)2e6;
constexpr int64_t INF = (int64_t)2e18;
constexpr int64_t MOD = (int64_t)1e9 + 7;

class Solution {
public:
    int minCostToEqualizeArray(std::vector<int>& nums, int cost1, int cost2) {
        int n = nums.size();
        
        std::sort(nums.begin(), nums.end());
        
        int64_t ans = INF;
        int64_t sum_d = 0;
        int64_t max_d = nums.back() - nums.front();
        for(int i = 1; i < n; i++) {
            sum_d += nums.back() - nums[i];
        }
        
        if(cost1 * 2 <= cost2) {
            ans = (sum_d + max_d) * cost1;
        } else {
            for(int64_t d = max_d; d <= MAX; d++, sum_d += n - 1) {
                int64_t cost = 0;
                if(d > sum_d) {
                    cost = sum_d * cost2 + (d - sum_d) * cost1;
                } else {
                    cost = (d + sum_d) / 2 * cost2 + ((d + sum_d) % 2) * cost1;
                }
                ans = std::min(ans, cost);
            }
        }
        
        return ans % MOD;
    }
};
