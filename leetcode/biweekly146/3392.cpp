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
    int countSubarrays(std::vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        for(int i = 1; i < n - 1; i++) {
            if((nums[i - 1] + nums[i + 1]) * 2 == nums[i]) {
                ans += 1;
            }
        }
        
        return ans;
    }
};
