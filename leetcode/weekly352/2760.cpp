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
    int longestAlternatingSubarray(std::vector<int>& nums, int threshold) {
        int ans = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            if(nums[i] % 2 == 1) {
                continue;
            }
            for(int j = i; j < n; j++) {
                bool ok = true;
                for(int k = i; k <= j; k++) {
                    if(nums[k] > threshold) {
                        ok = false;
                        break;
                    }
                    
                    if(k != j && nums[k] % 2 == nums[k + 1] % 2) {
                        ok = false;
                        break;
                    }
                }
                
                if(ok) {
                    ans = std::max(ans, j - i + 1);
                }
            }
        }
        
        return ans;
    }
};
