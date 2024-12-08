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
    std::vector<int> constructTransformedArray(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ans(n);
        
        for(int i = 0; i < n; i++) {
            int p = i;
            for(int j = 0; j < std::abs(nums[i]); j++) {
                p += 1 * (nums[i] > 0 ? 1 : -1);
                p = (p + n) % n;
            }
            ans[i] = nums[p];
        }
        
        return ans;
    }
};
