#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int INF = int(2e9);

class Solution {
public:
    std::vector<int> minBitwiseArray(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ans(n, -1);
        
        for(int i = 0; i < n; i++) {
            int x = nums[i];    
            
            int now = 0;
            int min_v = INF;
            for(int j = 30; j >= 0; j--) {
                if(x & (1 << j)) {
                    int y = now | ((1 << j) - 1);
                    if((y | (y + 1)) == x) {
                        min_v = std::min(min_v, y);
                    }
                    now |= 1 << j;
                }
            }
            
            if(min_v != INF) {
                ans[i] = min_v;
            }
        }
        
        return ans;
    }
};
