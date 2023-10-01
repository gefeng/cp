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
    int maxSubarrays(std::vector<int>& nums) {
        int n = nums.size();
        int t = (1 << 20) - 1;
        for(int x : nums) {
            t &= x;
        }
        
        if(t) {
            return 1;
        }
        
        t = (1 << 20) - 1;
        int ans = 0;
        for(int x : nums) {
            t &= x;
            if(t == 0) {
                t = (1 << 20) - 1;
                ans += 1;
            }
        }
        
        return ans;
    }
};
