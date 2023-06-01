#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

using LL = long long;

constexpr LL INF = (LL)2e18;

class Solution {
public:
    long long maxStrength(std::vector<int>& nums) {
        int n = nums.size();
        LL ans = -INF;
        
        for(int i = 1; i < (1 << n); i++) {
            LL p = 1LL;
            for(int j = 0; j < n; j++) {
                if(i & (1 << j)) {
                    p *= nums[j];
                }
            }
            
            ans = std::max(ans, p);
        }
        
        return ans;
    } 
};
