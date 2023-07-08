#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int INF = (int)1e9;

class Solution {
public:
    int minimumBeautifulSubstrings(std::string s) {
        int n = s.length();
        
        std::set<int> a;
        int p_5 = 1;
        for(int i = 0; i < 8; i++) {
            a.insert(p_5);
            p_5 *= 5;
        }
        
        std::vector<int> dp(n + 1, INF);
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            int x = 0;
            for(int j = i; j > 0; j--) {
                if(s[j - 1] == '1') {
                    x |= 1 << (i - j);
                } 
                if(s[j - 1] != '0' && a.find(x) != a.end() && dp[j - 1] != INF) {
                    dp[i] = std::min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        
        return dp[n] == INF ? -1 : dp[n];
    }
};
