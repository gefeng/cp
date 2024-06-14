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
    long long maxArrayValue(std::vector<int>& nums) {
        int n = nums.size();
        int64_t ans = 0;
        int64_t x = nums.back();
        ans = x;
        for(int i = n - 2; i >= 0; i--) {
            if(x >= nums[i]) {
                x += nums[i];
            } else {
                x = nums[i];
            }
            ans = std::max(ans, x);
        }
        
        return ans;
    }
};
