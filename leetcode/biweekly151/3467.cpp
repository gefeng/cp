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
    std::vector<int> transformArray(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ans(n);
        
        for(int i = 0; i < n; i++) {
            ans[i] = nums[i] % 2;
        }
        
        std::sort(ans.begin(), ans.end());
        
        return ans;
    }
};
