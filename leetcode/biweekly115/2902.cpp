#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)1e9 + 7;

class Solution {
public:
    int countSubMultisets(std::vector<int>& nums, int l, int r) {
        int n = nums.size();
        
        std::sort(nums.begin(), nums.end());
        
        std::vector<int64_t> dp(r + 1, 0);
        dp[0] = 1;
        int cur = 0;
        for(int i = 0; i < n; ) {
            int j = i;
            while(i < n && nums[i] == nums[j]) {
                i += 1;
            }
            
            if(nums[j] == 0) {
                dp[0] += i - j;
                continue;
            }
            
            int v = nums[j];
            int f = i - j;
            cur += f * v;
            std::vector<int64_t> ndp(r + 1, 0);
            std::vector<int64_t> psum(r + 1, 0);
            ndp[0] = dp[0];
            psum[0] = dp[0];
            for(int s = 1; s <= std::min(r, cur); s++) {
                psum[s] = ((s - v >= 0 ? psum[s - v] : 0) + dp[s]) % MOD;
            }
            
            for(int s = 0; s <= std::min(r, cur); s++) {
                ndp[s] = psum[s] - (s - (f + 1) * v >= 0 ? psum[s - (f + 1) * v] : 0);
                ndp[s] += MOD;
                ndp[s] %= MOD;
            }
            
            std::swap(dp, ndp);
        }
        
        int64_t ans = 0;
        for(int s = l; s <= r; s++) {
            ans += dp[s];
            ans %= MOD;
        }
        return ans;
    }
};
