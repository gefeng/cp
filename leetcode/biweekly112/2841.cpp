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
    long long maxSum(std::vector<int>& nums, int m, int k) {
        int64_t ans = 0;
        int64_t sum = 0;
        std::map<int, int> seen;
        int n = nums.size();
        for(int l = 0, r = 0; r < n; r++) {
            seen[nums[r]] += 1;
            sum += nums[r];
            
            if(r - l + 1 > k) {
                if(--seen[nums[l]] == 0) {
                    seen.erase(nums[l]);
                }
                sum -= nums[l];
                l += 1;
            }
            
            if(r - l + 1 == k && seen.size() >= m) {
                ans = std::max(ans, sum);
            }
        }
        
        return ans;
    }
};
