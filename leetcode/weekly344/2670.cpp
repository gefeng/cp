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
    std::vector<int> distinctDifferenceArray(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ans(n);
    
        std::set<int> s;
        for(int i = 0; i < n; i++) {
            s.insert(nums[i]);
            ans[i] = s.size();
        }
        
        s = std::set<int>();
        for(int i = n - 1; i >= 0; i--) {
            ans[i] -= s.size();
            s.insert(nums[i]);
        }
        
        return ans;
    }
};
