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
    int minOperations(std::vector<int>& nums) {
        int n = nums.size();
        
        int ans = 0;
        int pre = -1;
        std::vector<int> stk;
        for(int i = 0; i < n; i++) {
            pre = -1;
            while(!stk.empty() && stk.back() > nums[i]) {
                if(stk.back() != pre && stk.back() != 0) {
                    ans += 1;
                }
                pre = stk.back();
                stk.pop_back();
            }
            
            stk.push_back(nums[i]);
        }
    
        pre = -1;
        while(!stk.empty()) {
            if(stk.back() != pre && stk.back() != 0) {
                ans += 1;
            }
            pre = stk.back();
            stk.pop_back();
        }
        
        return ans;
    }
};
