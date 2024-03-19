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
    int sumOfPower(std::vector<int>& nums, int k) {
        int n = nums.size();
        int64_t ans = 0;
        std::vector<int64_t> p2(n + 1, 1);
        
        for(int i = 1; i <= n; i++) {
            p2[i] = p2[i - 1] * 2 % MOD;
        }
        
        std::vector<std::vector<int64_t>> dp(n + 1, std::vector<int64_t>(k + 1, 0));
        dp[0][0] = 1;
        
        for(int i = 1; i <= n; i++) {
            int v = nums[i - 1];
            std::vector<std::vector<int64_t>> ndp(n + 1, std::vector<int64_t>(k + 1, 0));
            for(int j = 0; j <= i; j++) {
                for(int s = 0; s <= k; s++) {
                    ndp[j][s] = dp[j][s];
                    if(j - 1 >= 0 && s - v >= 0) {
                        ndp[j][s] += dp[j - 1][s - v];
                        ndp[j][s] %= MOD;
                    }
                }
            }
            
            std::swap(dp, ndp);
        }
        
        for(int i = 1; i <= n; i++) {
            ans += p2[n - i] * dp[i][k] % MOD;
            ans %= MOD;
        }
        
        return ans;
    }
};
