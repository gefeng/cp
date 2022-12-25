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

class Solution {
    using LL = long long;
    const LL MOD = (LL)1e9 + 7LL;
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        
        LL sum = 0LL;
        for(int x : nums) {
            sum += x;
        }
        
        vector<vector<LL>> dp(n + 1, vector<LL>(k + 1, 0LL));
        dp[0][0] = 1LL;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= k; j++) {
                dp[i + 1][j] += dp[i][j];
                dp[i + 1][j] %= MOD;
                dp[i + 1][min(k, j + nums[i])] += dp[i][j];
                dp[i + 1][min(k, j + nums[i])] %= MOD;
            }
        }
        
        LL ans = dp[n][k];
        LL invalid = 0LL;
        for(int i = 0; i < k; i++) {
            if(sum - i >= k) {
                invalid += dp[n][i];
                invalid %= MOD;
            }
        }
        
        return (ans - invalid + MOD) % MOD;
    }
};
