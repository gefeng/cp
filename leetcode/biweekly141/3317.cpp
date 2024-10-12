#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(1e9) + 7;

class Solution {
public:
    int numberOfWays(int n, int x, int y) {
        std::vector<int64_t> power(x + 1, 1);
        
        for(int i = 1; i <= x; i++) {
            power[i] = power[i - 1] * y % MOD;
        }
        
        int64_t ans = 0;
        std::vector<int64_t> dp(x + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < n; i++) {
            std::vector<int64_t> ndp(x + 1, 0);
            
            for(int j = 0; j <= x; j++) {
                ndp[j] += dp[j] * j % MOD;
                ndp[j] %= MOD;
                if(j + 1 <= x) {
                    ndp[j + 1] += dp[j] * (x - j) % MOD;
                    ndp[j + 1] %= MOD;
                }
            }
            
            std::swap(dp, ndp);
        }

        for(int i = 1; i <= x; i++) {
            ans += dp[i] * power[i] % MOD;
            ans %= MOD;
        }
        
        return ans;
    }
};
