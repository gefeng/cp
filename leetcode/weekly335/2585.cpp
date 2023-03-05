#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const LL MOD = (LL)1e9 + 7LL;

class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        vector<vector<LL>> dp(n + 1, vector<LL>(target + 1, 0LL));
        dp[0][0] = 1;
        
        for(int i = 1; i <= n; i++) {
            int tot = types[i - 1][0];
            int score = types[i - 1][1];
            for(int j = 0; j <= target; j++) {
                for(int k = 0; k <= tot; k++) {
                    if(j - k * score >= 0) {
                        dp[i][j] += dp[i - 1][j - k * score];
                        dp[i][j] %= MOD;
                    }
                }
            }
        }
        
        return dp[n][target];
    }
};
