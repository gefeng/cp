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
    int dfs(int k, int pos, int used, int jump, std::vector<int>& p2, std::map<int, std::map<std::pair<int, int>, int>>& dp) {
        if(pos > k + 1) {
            return 0;
        }
        
        if(dp.find(pos) != dp.end() && dp[pos].find({used, jump}) != dp[pos].end()) {
            return dp[pos][{used, jump}];
        }
        
        int res = pos == k ? 1 : 0;
        
        if(!used && pos != 0) {
            res += dfs(k, pos - 1, 1, jump, p2, dp);
        }
        res += dfs(k, pos + p2[jump], 0, jump + 1, p2, dp);
        
        return dp[pos][{used, jump}] = res;
    }

    int waysToReachStair(int k) {
        std::vector<int> p2(31, 1);
        for(int i = 1; i <= 30; i++) {
            p2[i] = p2[i - 1] * 2;
        }
        
        std::map<int, std::map<std::pair<int, int>, int>> dp;
        return dfs(k, 1, 0, 0, p2, dp);
    }
};
