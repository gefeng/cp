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
    std::vector<int> z_function(std::string s) {
        int n = s.size();
        std::vector<int> z(n);
        int l = 0, r = 0;
        for(int i = 1; i < n; i++) {
            if(i < r) {
                z[i] = std::min(r - i, z[i - l]);
            }
            while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if(i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }
        return z;
    }
    
    int longestPalindrome(std::string s, std::string t) {
        int n = s.size();
        int m = t.size();
        int ans = 0;
        
        std::reverse(t.begin(), t.end());
        
        auto get_max_len = [](std::string t) {
            int n = t.size();
            std::vector<int> max_len(n, 0);
            std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
            for(int i = 0; i < n; i++) {
                for(int j = i; j >= 0; j--) {
                    if(i == j) {
                        dp[j][i] = 1;
                    } else if(j + 1 == i) {
                        dp[j][i] = t[i] == t[j];
                    } else {
                        dp[j][i] = t[i] == t[j] && dp[j + 1][i - 1];
                    }
                }
            }

            for(int i = 0; i < n; i++) {
                for(int j = i; j < n; j++) {
                    if(dp[i][j]) {
                        max_len[i] = std::max(max_len[i], j - i + 1);
                    }
                }
            }
            
            return max_len;
        };
        
        std::vector<int> max_len_s = get_max_len(s);
        std::vector<int> max_len_t = get_max_len(t);
        
        for(int i = 0; i < n; i++) {
            ans = std::max(ans, max_len_s[i]);
        }
        
        for(int i = 0; i < m; i++) {
            ans = std::max(ans, max_len_t[i]);
        }
        
        for(int i = 0; i < n; i++) {
            std::string x = s.substr(i, n - i) + t;
            
            std::vector<int> z = z_function(x);
            for(int j = n - i; j < x.size(); j++) {
                int common = std::min(n - i, z[j]);
                
                if(common) {
                    ans = std::max(ans, common * 2 + (common + i < n ? max_len_s[common + i] : 0));
                    ans = std::max(ans, common * 2 + (j - n + i + common < m ? max_len_t[j - n + i + common] : 0));
                }
            }
        }
        
        return ans;
    }
};
