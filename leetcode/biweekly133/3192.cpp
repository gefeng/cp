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
        int n = nums.size();
        
        int flip = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(flip) {
                nums[i] ^= 1;
            }
            if(nums[i] == 0) {
                flip ^= 1;
                ans += 1;
            }
        }
        
        return ans;
    }
};
