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
    int minExtraChar(std::string s, std::vector<std::string>& dictionary) {
        std::unordered_set<std::string> dict;
        for(std::string s : dictionary) {
            dict.insert(s);
        }
        
        std::vector<int> dp(s.size(), -1);
        return dfs(s, 0, dict, dp);
    }
    
    int dfs(std::string& s, int cur, std::unordered_set<std::string>& dict, std::vector<int>& dp) {
        int n = s.size();
        if(cur == n) {
            return 0;
        }
        
        if(dp[cur] != -1) {
            return dp[cur];
        }
        
        std::string t = "";
        int res = n;
        for(int i = cur; i < n; i++) {
            t.push_back(s[i]);
            int ret = dfs(s, i + 1, dict, dp) + (dict.find(t) == dict.end() ? t.size() : 0);
            
            res = std::min(res, ret);
        }
        
        return dp[cur] = res;
    }
};
