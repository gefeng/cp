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
    int64_t q_pow(int64_t x, int64_t y) {
        int64_t res = 1;
        while(y) {
            if(y & 1) {
                res *= x;
                res %= MOD;
            }
            x *= x;
            x %= MOD;
            y >>= 1;
        }
        return res;
    }
    int stringCount(int n) {
        if(n < 4) {
            return 0;
        }
        
        std::vector<std::vector<int64_t>> dp(n + 1, std::vector<int64_t>(1 << 4, 0));
        dp[0][0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < (1 << 4); j++) {
                int cnt = 0;
                for(int k = 0; k < 4; k++) {
                    if((j & (1 << k)) == 0) {
                        cnt += 1;
                        dp[i + 1][j | (1 << k)] += dp[i][j];
                        dp[i + 1][j | (1 << k)] %= MOD;
                    }
                }
                
                if((j & (1 << 1)) == 0 && (j & (1 << 2)) == 0) {
                    cnt -= 1;
                }
                
                dp[i + 1][j] += dp[i][j] * (26 - cnt) % MOD;
                dp[i + 1][j] %= MOD;
            }
        }
        
        return dp[n][(1 << 4) - 1] * q_pow(2, MOD - 2) % MOD;
    }
};
