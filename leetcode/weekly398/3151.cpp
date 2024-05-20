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
    bool isArraySpecial(std::vector<int>& nums) {
        int n = nums.size();
        for(int i = 1; i < n; i++) {
            if(nums[i] % 2 == nums[i - 1] % 2) {
                return false;
            }
        }
        
        return true;
    }
};
