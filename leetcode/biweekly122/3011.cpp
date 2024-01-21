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
    bool canSortArray(std::vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            int j = i;
            while(j > 0 && nums[j] < nums[j - 1]) {
                if(__builtin_popcount(nums[j]) == __builtin_popcount(nums[j - 1])) {
                    std::swap(nums[j], nums[j - 1]);
                    j -= 1;
                } else {
                    return false;
                }
            }
        }
        
        return true;
    }
};
