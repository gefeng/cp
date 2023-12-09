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
    int maxSubarrayLength(std::vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        
        std::map<int, int> m;
        for(int l = 0, r = 0; r < n; r++) {
            m[nums[r]] += 1;
            
            while(l <= r && m[nums[r]] > k) {
                if(--m[nums[l]] == 0) {
                    m.erase(nums[l]);
                }
                l += 1;
            }
            
            ans = std::max(ans, r - l + 1);
        }
        
        return ans;
    }
};
