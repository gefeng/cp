#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int MOD = int(1e9) + 7;

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        std::vector<std::vector<std::vector<int>>> dp(2, std::vector<std::vector<int>>(zero + 1, std::vector<int>(one + 1, 0)));
        
        dp[0][0][0] = 1;
        dp[1][0][0] = 1;
        
        for(int i = 0; i <= zero; i++) {
            for(int j = 0; j <= one; j++) {
                if(i) {
                    for(int k = 1; k <= std::min(limit, i); k++) {
                        dp[0][i][j] += dp[1][i - k][j];
                        dp[0][i][j] %= MOD;
                    }
                }
                if(j) {
                    for(int k = 1; k <= std::min(limit, j); k++) {
                        dp[1][i][j] += dp[0][i][j - k];
                        dp[1][i][j] %= MOD;
                    }
                }
            }
        }
        
        int ans = (dp[0][zero][one] + dp[1][zero][one]) % MOD;
        return ans;
    }
};
