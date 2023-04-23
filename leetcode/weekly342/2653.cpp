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
    std::vector<int> getSubarrayBeauty(std::vector<int>& nums, int k, int x) {
        std::vector<int> ans;
        std::array<int, 51> cnt = {}; 
        
        int n = nums.size();
        for(int l = 0, r = 0; r < n; r++) {
            if(nums[r] < 0) {
                cnt[-nums[r]] += 1;
            }
            
            if(r - l + 1 > k) {
                if(nums[l] < 0) {
                    cnt[-nums[l]] -= 1;
                }
                l += 1;
            }
            
            if(r - l + 1 == k) {
                int cur = 0;
                bool found = false;
                for(int i = 50; i > 0; i--) {
                    if(cur + cnt[i] >= x) {
                        ans.push_back(-i);
                        found = true;
                        break;
                    } 
                    cur += cnt[i];
                }
                
                if(!found) {
                    ans.push_back(0);
                }
            }
        }
        
        return ans;
    }
};
