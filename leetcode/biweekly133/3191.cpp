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
    int minOperations(std::vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        
        for(int i = 0; i <= n - 3; i++) {
            if(nums[i] == 0) {
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                ans += 1;
            }
        }
        
        if(nums[n - 2] == 0 || nums[n - 1] == 0) {
            ans = -1;
        }
        
        return ans;
    }
};
