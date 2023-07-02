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
    long long continuousSubarrays(std::vector<int>& nums) {
        int n = nums.size();
        int64_t ans = n;
        
        std::map<int, int> m;
        for(int l = 0, r = 0; r < n; r++) {
            m[nums[r]] += 1;
            
            while(m.rbegin()->first - m.begin()->first > 2) {
                if(--m[nums[l]] == 0) {
                    m.erase(nums[l]);
                }
                l += 1;
            }
            
            int64_t cnt = r - l + 1;
            
            ans += cnt - 1;
        }
        
        return ans;
    }
};
