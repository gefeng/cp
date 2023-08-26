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
    int longestEqualSubarray(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<std::vector<int>> pos(n + 1);
        
        for(int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }
        
        int ans = 0;
        for(int i = 0; i <= n; i++) {
            std::vector<int>& a = pos[i];
            if(a.empty()) {
                continue;
            }
            
            int sz = a.size();
            for(int l = 0, r = 0; r < sz; r++) {
                while(a[r] - a[l] + 1 - (r - l + 1) > k) {
                    l += 1;
                }
                
                ans = std::max(ans, r - l + 1);
            }
        }
        
        return ans;
    }
};
