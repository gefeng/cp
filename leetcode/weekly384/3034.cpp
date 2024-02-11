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
    int countMatchingSubarrays(std::vector<int>& nums, std::vector<int>& pattern) {
        int ans = 0;
        int n = nums.size();
        int m = pattern.size();
        
        for(int i = 0; i <= n - m - 1; i++) {
            bool ok = true;
            for(int j = 0, k = i + 1; j < m; j++, k++) {
                if(pattern[j] == 1) {
                    if(nums[k] <= nums[k - 1]) {
                        ok = false;
                        break;
                    }
                } else if(pattern[j] == 0) {
                    if(nums[k] != nums[k - 1]) {
                        ok = false;
                        break;
                    }
                } else {
                    if(nums[k] >= nums[k - 1]) {
                        ok = false;
                        break;
                    }
                }
            }
            
            if(ok) {
                ans += 1;
            }
        }
        
        return ans;
    }
};
