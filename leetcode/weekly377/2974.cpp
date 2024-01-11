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
    std::vector<int> numberGame(std::vector<int>& nums) {
        std::vector<int> ans;
        int n = nums.size();
        
        std::sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i += 2) {
            int x = nums[i];
            int y = nums[i + 1];
            ans.push_back(y);
            ans.push_back(x);
        }
        
        return ans;
    }
};
