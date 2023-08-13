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
        int n = nums.size();
        int ans = -1;
        
        auto max_digits = [](int x) {
            int res = 0;
            while(x) {
                res = std::max(res, x % 10);
                x /= 10;
            }  
            
            return res;
        };
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(max_digits(nums[i]) == max_digits(nums[j])) {
                    ans = std::max(ans, nums[i] + nums[j]);
                }
            }
        }
        return ans;
    }
};
