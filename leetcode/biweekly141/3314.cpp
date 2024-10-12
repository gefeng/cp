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
    std::vector<int> minBitwiseArray(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ans(n, -1);
        
        for(int i = 0; i < n; i++) {
            for(int x = 0; x < nums[i]; x++) {
                if((x | x + 1) == nums[i]) {
                    ans[i] = x;
                    break;
                }
            }
        }
        
        return ans;
    }
};
