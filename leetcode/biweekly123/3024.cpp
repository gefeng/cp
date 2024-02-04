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
    std::string triangleType(std::vector<int>& nums) {
        std::string ans = "none";
        if(nums[0] == nums[1] && nums[0] == nums[2] && nums[1] == nums[2]) {
            ans = "equilateral";
        } else {
            std::sort(nums.begin(), nums.end());
            if(nums[0] + nums[1] > nums[2]) {
                ans = nums[0] == nums[1] || nums[1] == nums[2] ? "isosceles" : "scalene";
            } 
        }
        
        return ans;
    }
};
