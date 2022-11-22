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
    bool is_prime(char c) {
        return c == '2' || c == '3' || c == '5'|| c == '7';
    }
    int beautifulPartitions(string s, int k, int minLength) {
        int n = s.length();
        
        if(!is_prime(s[0])) {
            return 0;
        }
        
        vector<vector<LL>> dp(k + 1, vector<LL>(n + 1, 0LL));
        vector<vector<LL>> cum(k + 1, vector<LL>(n + 1, 0LL));
        dp[0][0] = 1LL;
        
        for(int i = 1; i <= k; i++) {    
            for(int j = 0; j <= n; j++) {
                if(j == 0) {
                    cum[i - 1][j] = dp[i - 1][j];
                } else {
                    cum[i - 1][j] += cum[i - 1][j - 1] + (is_prime(s[j]) ? dp[i - 1][j] : 0);
                    cum[i - 1][j] %= MOD;
                }
            }
            for(int j = 1; j <= n; j++) { 
                if(!is_prime(s[j - 1])) {
                    if(j - minLength >= 0) {
                        dp[i][j] += cum[i - 1][j - minLength];
                        dp[i][j] %= MOD;
                    }
                    /*for(int t = 0; t <= j - minLength; t++) {
                        if(t == 0 || is_prime(s[t])) {
                            dp[i][j] += dp[i - 1][t];
                            dp[i][j] %= MOD;
                        }
                    }*/
                }
            }
        }
        
        return dp[k][n];
    }
};
