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
        std::vector<std::vector<int>> ds0(zero + 1, std::vector<int>(one + 2, 0));
        std::vector<std::vector<int>> ds1(zero + 2, std::vector<int>(one + 1, 0));
        
        dp[0][0][0] = 1;
        dp[1][0][0] = 1;
        ds0[0][1] = 1;
        ds1[1][0] = 1;
        
        for(int i = 0; i <= zero; i++) {
            for(int j = 0; j <= one; j++) {
                if(i) {
                    int l = i - std::min(limit, i);
                    int r = i - 1;
                    dp[0][i][j] += (ds1[r + 1][j] - ds1[l][j] + MOD) % MOD;
                    dp[0][i][j] %= MOD;
                }
                ds0[i][j + 1] = (ds0[i][j] + dp[0][i][j]) % MOD;
                
                if(j) {
                    int l = j - std::min(limit, j);
                    int r = j - 1;
                    dp[1][i][j] += (ds0[i][r + 1] - ds0[i][l] + MOD) % MOD;
                    dp[1][i][j] %= MOD;
                }
                ds1[i + 1][j] = (ds1[i][j] + dp[1][i][j]) % MOD;
            }
        }
        
        int ans = (dp[0][zero][one] + dp[1][zero][one]) % MOD;
        return ans;
    }
};
