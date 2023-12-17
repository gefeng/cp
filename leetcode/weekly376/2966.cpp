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
    std::vector<std::vector<int>> divideArray(std::vector<int>& nums, int k) {
        std::vector<std::vector<int>> ans;
        int n = nums.size();
        
        std::sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i += 3) {
            if(nums[i + 2] - nums[i] > k) {
                ans.clear();
                break;
            }
            
            ans.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }
        
        return ans;
    }
};
