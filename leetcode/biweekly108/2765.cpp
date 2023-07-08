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
    int alternatingSubarray(std::vector<int>& nums) {
        int ans = -1;
        int n = nums.size();
        
        for(int i = 0; i < n - 1; i++) {
            int len = 1;
            for(int j = i + 1, k = 1; j < n; j++, k *= -1) {
                if(nums[j] != nums[j - 1] + k) {
                    break;
                }
                len += 1;
            }
            
            if(len > 1) {
                ans = std::max(ans, len);
            }
        }
        
        return ans;
    }
};
