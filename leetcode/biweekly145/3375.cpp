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
    int minOperations(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        
        nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
        
        if(k > nums[0]) {
            return -1;
        }
        
        return k == nums[0] ? nums.size() - 1 : nums.size();
    }
};
