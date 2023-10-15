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
    std::vector<std::string> getWordsInLongestSubsequence(int n, std::vector<std::string>& words, std::vector<int>& groups) {
        std::vector<std::string> ans;
        std::vector<int> dp(n, 1);
        std::vector<int> pre(n, -1);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(groups[i] == groups[j]) {
                    continue;
                }
                if(words[i].size() != words[j].size()) {
                    continue;
                }
                
                int diff = 0;
                for(int k = 0; k < words[i].size(); k++) {
                    if(words[i][k] != words[j][k]) {
                        diff += 1;
                    }
                }
                
                if(diff != 1) {
                    continue;
                }
                
                if(dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                }
            }
        }
        
        int now = std::max_element(dp.begin(), dp.end()) - dp.begin();
        while(now != -1) {
            ans.push_back(words[now]);
            now = pre[now];
        }
        
        std::reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
