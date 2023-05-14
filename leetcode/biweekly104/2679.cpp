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
    int matrixSum(std::vector<std::vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            std::sort(nums[i].begin(), nums[i].end(), std::greater<int>());    
        }
        
        for(int i = 0; i < m; i++) {
            int max_v = 0;
            for(int j = 0; j < n; j++) {
                max_v = std::max(max_v, nums[j][i]);
            }
            
            ans += max_v;
        }
        
        return ans;
    }
};
