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
    int maxRemovals(std::string source, std::string pattern, std::vector<int>& targetIndices) {
        int n = source.size();
        int m = pattern.size();
        int q = targetIndices.size();

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, -1));
        dp[0][0] = 0;
        
        for(int i = 1, j = 0; i <= n; i++) {
            for(int k = 0; k <= std::min(i, m); k++) {
                if(j == q || i - 1 < targetIndices[j]) {
                    if((k == 0 && pattern[0] != source[i - 1]) || (k && pattern[k - 1] != source[i - 1])) {
                        dp[i][k] = std::max(dp[i][k], dp[i - 1][k]);
                    } else {
                        if(k == 0) {
                            dp[i][k] = std::max(dp[i][k], dp[i - 1][k]);
                        } else {
                            dp[i][k] = std::max(dp[i][k], dp[i - 1][k - 1]);
                        }
                    }
                } else {
                    if((k == 0 && pattern[0] != source[i - 1]) || (k && pattern[k - 1] != source[i - 1])) {
                        dp[i][k] = std::max(dp[i][k], dp[i - 1][k]);
                    } else {
                        if(k == 0) {
                            dp[i][k] = std::max(dp[i][k], dp[i - 1][k]);
                        } else {
                            dp[i][k] = std::max(dp[i][k], dp[i - 1][k - 1]);
                        }
                    }
                    
                    if(dp[i - 1][k] != -1) {
                        dp[i][k] = std::max(dp[i][k], dp[i - 1][k] + 1);
                    }
                }
            }
            if(j < q && i - 1 == targetIndices[j]) {
                j += 1;
            }
        }
        
        return dp[n][m];
    }
};
