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
    long long incremovableSubarrayCount(std::vector<int>& nums) {
        int64_t ans = 0;
        int n = nums.size();
        
        bool inc = true;
        for(int i = 1; i < n; i++) {
            if(nums[i] <= nums[i - 1]) {
                inc = false;
                break;
            }
        }
        if(inc) {
            return (int64_t)(1 + n) * n / 2;
        }
        
        int p = n - 1;
        while(p - 1 >= 0 && nums[p - 1] < nums[p]) {
            p -= 1;
        }
        
        ans = n - p + 1;
        for(int i = 0; i < n; i++) {
            if(i && nums[i] <= nums[i - 1]) {
                break;
            }
            
            auto it = std::upper_bound(nums.begin() + p, nums.end(), nums[i]);
            ans += n - (it - nums.begin()) + 1;
        }
        
        return ans;
    }
};
