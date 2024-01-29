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
    int minOrAfterOperations(std::vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int can_remove = 0;
        
        for(int b = 29; b >= 0; b--) {
            int x = can_remove | (1 << b);
            int cur = 0;
            int cnt = 0;
            for(int i = 0; i < n; i++) {
                cur = cur == 0 ? x & nums[i] : cur & x & nums[i];
                if(cur) {
                    cnt += 1;
                }
            }
            
            if(cnt > k) {
                ans |= 1 << b;
            } else {
                can_remove |= 1 << b;
            }
        }
        
        return ans;
    }
};
