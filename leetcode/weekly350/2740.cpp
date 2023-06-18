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
    int findValueOfPartition(std::vector<int>& nums) {
        int n = nums.size();
        
        std::sort(nums.begin(), nums.end());
        
        int ans = (int)2e9;
        for(int i = 1; i < n; i++) {
            ans = std::min(ans, nums[i] - nums[i - 1]);
        }
        
        return ans;
    }
};
