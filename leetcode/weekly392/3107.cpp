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
    long long minOperationsToMakeMedianK(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        
        int m = n / 2;
        if(nums[m] == k) {
            return 0;
        }
        
        int64_t ans = 0;
        if(nums[m] < k) {
            
            for(int i = m; i < n; i++) {
                if(nums[i] < k) {
                    ans += k - nums[i];
                }
            }
        } else {
            for(int i = m; i >= 0; i--) {
                if(nums[i] > k) {
                    ans += nums[i] - k;
                }
            }
        }
        
        return ans;
    }
};
