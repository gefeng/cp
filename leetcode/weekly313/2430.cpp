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

const LL MOD = (LL)1e14;

class Solution {
public:
    int deleteString(string s) {
        int n = s.length();
        int ans = 1;
        
        
        
        vector<vector<LL>> h(n, vector<LL>(n, 0LL));
        for(int i = 0; i < n; i++) {
            LL hash = 0LL;
            LL base = 27;
            for(int j = i; j < n; j++) {
                hash = (hash * base % MOD + (s[j] - 'a' + 1)) % MOD;
                h[i][j] = hash;
            }
        }
        
        vector<int> dp(n + 1, -1); // maximum prefix can remove
        
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                if(dp[j] != -1) {
                    if(i + i - j <= n && h[j][i - 1] == h[i][2 * i - j - 1]) {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
            }
        }
        
        for(int i = 1; i <= n; i++) {
            ans = max(ans, dp[i] + 1);
        }
        
        return ans;
    }
};
