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
    int countWays(std::vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        
        std::sort(nums.begin(), nums.end());
        
        if(nums[0]) {
            ans += 1;
        }
        
        for(int i = 0; i < n; i++) {
            if(i + 1 > nums[i] && (i == n - 1 || i + 1 < nums[i + 1])) {
                ans += 1;
            }
        }
        
        return ans;
    }
};
