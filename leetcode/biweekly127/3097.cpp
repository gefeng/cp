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
    int minimumSubarrayLength(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::array<int, 30> cnt{};
        
        auto is_ok = [&]() {
            int x = 0;
            for(int i = 0; i < 30; i++) {
                if(cnt[i]) {
                    x |= 1 << i;
                }
            }
            
            return x >= k;
        };
    
        int ans = -1;
        for(int l = 0, r = 0; r < n; r++) {
            for(int i = 0; i < 30; i++) {
                if(nums[r] & (1 << i)) {
                    cnt[i] += 1;
                }
            }
            
            while(l <= r && is_ok()) {
                ans = ans == -1 ? r - l + 1 : std::min(ans, r - l + 1);
                
                for(int i = 0; i < 30; i++) {
                    if(nums[l] & (1 << i)) {
                        cnt[i] -= 1;
                    }
                }
                l += 1;
            }
        }
        
        return ans;
    }
};
