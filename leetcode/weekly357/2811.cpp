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
    bool canSplitArray(std::vector<int>& nums, int m) {
        int n = nums.size();
        if(n < 3) {
            return true;
        }
        
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] + nums[i + 1] >= m) {
                return true;
            }
        }
        
        return false;
    }
};
