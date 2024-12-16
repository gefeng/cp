#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int INF = int(2e9);

class Solution {
public:
    int makeStringGood(std::string s) {
        int n = s.size();
        std::sort(s.begin(), s.end());
        
        int max_f = 0;
        std::array<int, 26> freq;
        for(int i = 0; i < n; ) {
            int j = i;
            while(i < n && s[i] == s[j]) {
                i += 1;
            }
            max_f = std::max(max_f, i - j);
            freq[s[j] - 'a'] = i - j;
        }
        
        std::vector<std::vector<int>> dp(27, std::vector<int>(max_f + 1, INF));
        for(int i = 0; i <= max_f; i++) {
            dp[0][i] = 0;
            dp[1][i] = std::min(freq[0], std::abs(i - freq[0]));
        }
        
        for(int i = 2; i <= 26; i++) {
            for(int j = 0; j <= max_f; j++) {
                dp[i][j] = dp[i - 1][j] + std::min(freq[i - 1], std::abs(j - freq[i - 1]));
                
                if(freq[i - 1] < j && freq[i - 2] > j) {
                    int d = std::min(freq[i - 2] - j, j - freq[i - 1]);
                    dp[i][j] = std::min(dp[i][j], dp[i - 2][j] + freq[i - 2] - d - j + d + std::abs(freq[i - 1] + d - j));
                }
                
                if(freq[i - 2] && freq[i - 1] < j) {
                    int d = std::min(j - freq[i - 1], freq[i - 2]);
                    int x = freq[i - 2] - d; 
                    if(x <= j) {
                        x = std::min(x, j - x);
                    }
                    dp[i][j] = std::min(dp[i][j], dp[i - 2][j] + d + x + std::abs(freq[i - 1] + d - j));
                }
            }
        }
        
        int ans = INF;
        for(int i = 0; i <= max_f; i++) {
            ans = std::min(ans, dp[26][i]);
        }
        return ans;
    }
};
