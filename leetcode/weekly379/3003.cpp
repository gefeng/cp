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
    int dfs(std::string& s, int k, int cur, int used, int changed, std::unordered_map<int64_t, int>& dp) {
        int n = s.size();
        if(cur == n) {
            return 1;
        }
        
        int64_t mask = ((int64_t)cur << 27) | (used << 1) | changed;
        int c = s[cur] - 'a';
        int add = used | (1 << c);
        int cnt = __builtin_popcount(add);
        
        if(dp.find(mask) != dp.end()) {
            return dp[mask];
        }
        
        int res = 0;
        if(cnt > k) {
            res = dfs(s, k, cur + 1, 1 << c, changed, dp) + 1;
        }
        
        if(cnt <= k) {
            res = std::max(res, dfs(s, k, cur + 1, add, changed, dp));
        }
        
        if(!changed) {
            for(int nc = 0; nc < 26; nc++) {
                if(nc != c) {
                    if(used & (1 << nc)) {
                        continue;
                    }
                    
                    add = used | (1 << nc);
                    cnt = __builtin_popcount(add);
                    
                    if(cnt <= k) {
                        res = std::max(res, dfs(s, k, cur + 1, add, 1, dp));
                    } else {
                        res = std::max(res, dfs(s, k, cur + 1, 1 << nc, 1, dp) + 1);
                    }
                }
            }
        }
        
        return dp[mask] = res;
    }
    
    int maxPartitionsAfterOperations(std::string s, int k) {
        std::unordered_map<int64_t, int> dp;
        return dfs(s, k, 0, 0, 0, dp);
    }
};
