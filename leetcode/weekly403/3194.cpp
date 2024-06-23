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
    double minimumAverage(std::vector<int>& nums) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        
        double ans = 1e9;
        for(int l = 0, r = n - 1; l < r; l++, r--) {
            ans = std::min(ans, (nums[l] + nums[r]) / 2.0);
        }
        
        return ans;
    }
};
