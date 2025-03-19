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
    int maxSum(std::vector<int>& nums) {
        int ans = 0;
        
        std::sort(nums.begin(), nums.end());
        nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
        
        if(nums.back() < 0) {
            ans = nums.back();    
        } else {
            for(int x : nums) {
                if(x >= 0) {
                    ans += x;
                }
            }
        }
        
        return ans;
    }
};
