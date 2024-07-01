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
    int maximumLength(std::vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        int len_eve = 0;
        int len_odd = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] % 2 == 0) {
                len_eve += 1;
            } else {
                len_odd += 1;
            }
        }
        
        ans = std::max(len_eve, len_odd);
        
        int len = 0;
        int pre = -1;
        for(int i = 0; i < n; i++) {
            if(nums[i] % 2 != pre) {
                len += 1;
                pre = nums[i] % 2;
            }
        }
        
        ans = std::max(ans, len);
        
        return ans;
    }
};
