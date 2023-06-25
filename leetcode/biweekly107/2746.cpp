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
    const int INF = (int)1e9;
public:
    int minimizeConcatenatedLength(std::vector<std::string>& words) {
        int n = words.size();
        std::vector<std::vector<std::vector<int>>> dp(n, std::vector<std::vector<int>>(26, std::vector<int>(26, INF)));
        
        dp[0][words[0][0] - 'a'][words[0].back() - 'a'] = words[0].size();
        
        for(int i = 1; i < n; i++) {
            std::string& s = words[i];
            int first = s[0] - 'a';
            int last = s.back() - 'a';
            
            for(int j = 0; j < 26; j++) {
                for(int k = 0; k < 26; k++) {
                    
                    
                    if(dp[i - 1][j][k] != INF) {
                        // append to the left     
                        if(j == last) {
                            dp[i][first][k] = std::min(dp[i][first][k], dp[i - 1][j][k] + (int)s.size() - 1);
                        } else {
                            dp[i][first][k] = std::min(dp[i][first][k], dp[i - 1][j][k] + (int)s.size());
                        }
                        
                        // append to the right
                        if(k == first) {
                            dp[i][j][last] = std::min(dp[i][j][last], dp[i - 1][j][k] + (int)s.size() - 1);
                        } else {
                            dp[i][j][last] = std::min(dp[i][j][last], dp[i - 1][j][k] + (int)s.size());
                        }
                    }
                }
            }
        }
        
        int ans = INF;
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 26; j++) {
                ans = std::min(ans, dp[n - 1][i][j]);
            }
        }
        
        return ans;
    }
};
