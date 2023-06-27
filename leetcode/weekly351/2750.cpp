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

constexpr LL MOD = (LL)1e9 + 7LL;

class Solution {
public:
    int numberOfGoodSubarraySplits(std::vector<int>& nums) {
        LL ans = 1LL;
        int n = nums.size();
        
        bool has_one = false;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {
                has_one = true;
            }
        }
        
        if(!has_one) {
            return 0;
        }
        
        for(int i = 0; i < n; ) {
            if(nums[i] == 1) {
                int j = i;
                i += 1;
                while(i < n && nums[i] == 0) {
                    i += 1;
                }
                
                if(i != n) {
                    ans *= (i - j);
                    ans %= MOD;
                }
            } else {
                i += 1;
            }
        }
        
        return ans;
    }
};
