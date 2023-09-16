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
    int minimumRightShifts(std::vector<int>& nums) {
        int n = nums.size();
        
        auto is_sorted = [](std::vector<int>& nums) {
            int n = nums.size();
            for(int i = 1; i < n; i++) {
                if(nums[i] < nums[i - 1]) {
                    return false;
                }
            }
            return true;
        };
        
        for(int i = 0; i < n; i++) {
            if(is_sorted(nums)) {
                return i;
            }    
            
            int last = nums.back();
            for(int j = n - 1; j > 0; j--) {
                nums[j] = nums[j - 1];
            }
            nums[0] = last;
        }
        return -1;
    }
};
