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
    int longestIdealString(string s, int k) {
        int ans = 0;
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(26, 0));
        
        for(int i = 1; i <= n; i++) {
            int c = s[i - 1] - 'a';
            
            for(int j = 0; j < 26; j++) {
                if(abs(c - j) <= k) {
                    dp[i][c] = max(dp[i][c], dp[i - 1][j] + 1);
                } 
            }
            
            for(int j = 0; j < 26; j++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
        }
        
        for(int i = 0; i < 26; i++) {
            ans = max(ans, dp[n][i]);
        }
        return ans;
    }  
};
