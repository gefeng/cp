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
    int maxPalindromes(string s, int k) {
        int n = s.length();
        vector<vector<bool>> is_pal(n, vector<bool>(n, false));
        
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                if(j == i) {
                    is_pal[i][j] = true;
                } else if(j == i + 1) {
                    is_pal[i][j] = s[i] == s[j];
                } else {
                    is_pal[i][j] = s[i] == s[j] && is_pal[i + 1][j - 1];
                }
            }
        }
        
        vector<int> dp(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            for(int j = 0; j < i; j++) {
                if(i - j >= k && is_pal[j][i - 1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        return dp[n];
    }
};
