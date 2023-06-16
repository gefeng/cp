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
    int semiOrderedPermutation(std::vector<int>& nums) {
        int ans = 0;
        
        int i = -1;
        int j = -1;
        int n = nums.size();
        for(int p = 0; p < n; p++) {
            if(nums[p] == 1) {
                i = p;
            } 
            if(nums[p] == n) {
                j = p;
            }
        }
        
        ans = i + n - 1 - j;
        
        if(i > j) {
            ans -= 1;
        }
        
        return ans;
    }
};
