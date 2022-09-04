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
public:
    const int MOD = 1e9 + 7;
    
    int numberOfWays(int startPos, int endPos, int k) {
        int MAX = 2000;
        vector<int> dp(MAX * 2 + 5, 0);
        
        dp[startPos + MAX] = 1;
        for(int i = 1; i <= k; i++) {
            vector<int> ndp(MAX * 2 + 5, 0);
            for(int p = 1; p <= MAX * 2; p++) {
                if(dp[p - 1] != -1) {
                    ndp[p] += dp[p - 1];
                    ndp[p] %= MOD;
                } 
                if(dp[p + 1] != -1) {
                    ndp[p] += dp[p + 1];
                    ndp[p] %= MOD;
                }
            }
            
            swap(dp, ndp);
        }
        
        return dp[endPos + MAX];
    }
};
