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
    int sumOfGoodNumbers(std::vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            if(i - k < 0 && i + k >= n) {
                ans += nums[i];
                continue;
            }
            
            if(i - k >= 0 && nums[i] <= nums[i - k]) {
                continue;
            }
            if(i + k < n && nums[i] <= nums[i + k]) {
                continue;
            }
            ans += nums[i];
        }
        
        return ans;
    }
};
