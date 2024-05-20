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
    std::vector<bool> isArraySpecial(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        std::vector<bool> ans(m, true);
        
        std::vector<int> a;
        for(int i = 1; i < n; i++) {
            if(nums[i] % 2 == nums[i - 1] % 2) {
                a.push_back(i);
            }
        }
        
        for(int i = 0; i < m; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            
            auto it = std::upper_bound(a.begin(), a.end(), l);
            
            if(it != a.end() && *it <= r) {
                ans[i] = false;
            }
        }
        
        return ans;
    }
};
