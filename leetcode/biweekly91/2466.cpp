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

const int MOD = (int)1e9 + 7;

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans = 0;
        
        int x = solve(zero, one, high);
        int y = solve(zero, one, low - 1);
        
        return (x - y + MOD) % MOD;
    }
    
    int solve(int a, int b, int t) {
        vector<int> dp(t + 1, 0);
        dp[0] = 1;
        
        for(int i = 1; i <= t; i++) {
            if(i - a >= 0) {
                dp[i] += dp[i - a];
                dp[i] %= MOD;
            }
            if(i - b >= 0) {
                dp[i] += dp[i - b];
                dp[i] %= MOD;
            }
        }
        
        int res = 0;
        for(int i = 0; i <= t; i++) {
            res += dp[i];
            res %= MOD;
        }
        return res;
    }
};
