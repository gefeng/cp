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
    long long maxSubarraySum(std::vector<int>& nums, int k) {
        int n = nums.size();
        int64_t ans = -INF;
        int64_t sum = 0;
        
        std::vector<int64_t> best(k, INF);
        best[0] = 0;
        
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = (i + 1) % k;
            
            if(best[rem] != INF) {
                ans = std::max(ans, sum - best[rem]);
            }
            best[rem] = std::min(best[rem], sum);
        }
        
        return ans;
    }
};
