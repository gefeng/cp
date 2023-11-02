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
    int findKOr(std::vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        
        std::array<int, 31> cnt = {};
        for(int x : nums) {
            for(int i = 0; i < 31; i++) {
                if(x & (1 << i)) {
                    cnt[i] += 1;
                }
            }
        }
        
        for(int i = 0; i < 31; i++) {
            if(cnt[i] >= k) {
                ans |= 1 << i;
            }
        }
        
        return ans;
    }
};
