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
    long long countSubarrays(std::vector<int>& nums, int k) {
        int64_t ans = 0;
        int n = nums.size();
        
        int max_v = 0;
        for(int x : nums) {
            max_v = std::max(max_v, x);
        }
        
        int cnt = 0;
        for(int l = 0, r = 0; r < n; r++) {
            if(nums[r] == max_v) {
                cnt += 1;
            }
            
            while(true) {
                if(nums[l] == max_v && cnt - 1 < k) {
                    break;
                }
                if(nums[l] == max_v) {
                    cnt -= 1;
                }
                l += 1;
            }
            
            if(cnt == k) {
                ans += l + 1;
            }
        }
        
        return ans;
    }
};
