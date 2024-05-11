#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int INF = (int)2e9;

class Solution {
public:
    int minimumSubstringsInPartition(std::string s) {
        int n = s.size();
        
        std::vector<int> dp(n + 1, INF);
        dp[0] = 0;
        
        for(int i = 1; i <= n; i++) {
            std::array<int, 26> cnt{};
            for(int j = i - 1; j >= 0; j--) {
                cnt[s[j] - 'a'] += 1;
                if(dp[j] != INF) {
                    bool bal = true;
                    int t = 0;
                    for(int k = 0; k < 26; k++) {
                        if(cnt[k]) {
                            if(t && cnt[k] != t) {
                                bal = false;
                                break;
                            }
                            if(t == 0) {
                                t = cnt[k];
                            }
                        }
                    }
                    if(bal) {
                        dp[i] = std::min(dp[i], dp[j] + 1);
                    }
                }
            }
        }

        return dp[n];
    }
};
