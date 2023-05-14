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

class Solution {
public:
    long long maximumOr(std::vector<int>& nums, int k) {
        std::array<int, 32> cnt = {};
        
        int sum = 0;
        for(int x : nums) {
            sum |= x;
            
            for(int i = 0; i < 32; i++) {
                if(x & (1 << i)) {
                    cnt[i] += 1;
                }
            }
        }
        
        LL ans = 0LL;
        for(int x : nums) {
            LL y = sum;
            for(int i = 0; i < 32; i++) {
                if(x & (1 << i)) {
                    if(cnt[i] == 1) {
                        y ^= 1 << i;
                    }
                }
            }
            
            y |= ((LL)x << k);
        
            ans = std::max(ans, y);
        }
        
        return ans;
    }
};
