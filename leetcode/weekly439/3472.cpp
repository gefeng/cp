#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

class Solution {
public:
    int longestPalindromicSubsequence(std::string s, int k) {
        int n = s.size();
        std::vector<std::vector<std::vector<int>>> dp(n, std::vector<std::vector<int>>(n, std::vector<int>(k + 1, 0)));
        
        for(int i = 0; i < n; i++) {
            dp[i][i][0] = 1;
        }
        
        int ans = 1;
        for(int i = 1; i < n; i++) {
            for(int j = i - 1; j >= 0; j--) {
                for(int p = 0; p <= k; p++) {
                    dp[j][i][p] = std::max(dp[j][i][p], dp[j][i - 1][p]);
                    dp[j][i][p] = std::max(dp[j][i][p], dp[j + 1][i][p]);
                    char a = s[i];
                    char b = s[j];
                    int cost = std::min(std::abs(a - b), 26 - std::abs(a - b));
                    if(p - cost >= 0) {
                        dp[j][i][p] = std::max(dp[j][i][p], j + 1 <= i - 1 ? dp[j + 1][i - 1][p - cost] + 2 : 2);
                    }
                    ans = std::max(ans, dp[j][i][p]);
                }
            }
        }
        
        return ans;
    }
};
