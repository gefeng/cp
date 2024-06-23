#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int64_t INF = (int64_t)2e18;

class Solution {
public:
    long long maximumTotalCost(std::vector<int>& nums) {
        int n = nums.size();
        int64_t sum1 = 0;
        int64_t sum2 = -INF;
        sum1 = nums[0];
        
        for(int i = 1; i < n; i++) {
            int64_t n_sum1 = -INF;
            int64_t n_sum2 = sum1 - nums[i];
            
            if(sum2 != -INF) {
                n_sum1 = sum2 + nums[i];
            }
            n_sum1 = std::max(n_sum1, sum1 + nums[i]);
            
            std::swap(sum1, n_sum1);
            std::swap(sum2, n_sum2);
        }
        
        return std::max(sum1, sum2);
    }
};
