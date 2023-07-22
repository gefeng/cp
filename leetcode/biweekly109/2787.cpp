#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)(1e9 + 7);

class Solution {
public:
    int numberOfWays(int n, int x) {
        std::vector<int64_t> dp(n + 1, 0);
        dp[0] = 1;

        for(int i = 1; i <= n; i++) {
            std::vector<int64_t> ndp(n + 1, 0);

            for(int j = 0; j <= n; j++) {
                ndp[j] += dp[j];
                ndp[j] %= MOD;
                
                int64_t nj = 1;
                for(int k = 0; k < x; k++) {
                    nj *= i;
                }
                nj += j;
                if(nj <= n) {
                    ndp[nj] += dp[j];
                    ndp[nj] %= MOD;
                }
            }

            std::swap(dp, ndp);
        }
        
        return dp[n];
    }
};
