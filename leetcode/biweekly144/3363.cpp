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
    int dfs_1(int n, vector<vector<int>>& fruits, int r, int c, int steps, std::map<std::pair<int, int>, int>& dp) {
        if(steps == n - 1) {
            return r == n - 1 && c == n - 1 ? 0 : -1;
        }
    
        std::pair<int, int> key = {r * n + c, steps};
        if(dp.find(key) != dp.end()) {
            return dp[key];
        }
        
        int res = -1;
        for(int d = -1; d <= 1; d++) {
            int nr = r + 1;
            int nc = c + d;
            if(nr >= 0 && nc >= n / 2 && nr < n && nc < n) {
                int ret = dfs_1(n, fruits, nr, nc, steps + 1, dp);
                if(ret != -1) {
                    res = std::max(res, ret + fruits[r][c]);
                }
            }
        }
        
        return dp[key] = res;
    }
    
    int dfs_2(int n, vector<vector<int>>& fruits, int r, int c, int steps, std::map<std::pair<int, int>, int>& dp) {
        if(steps == n - 1) {
            return r == n - 1 && c == n - 1 ? 0 : -1;
        }
    
        std::pair<int, int> key = {r * n + c, steps};
        if(dp.find(key) != dp.end()) {
            return dp[key];
        }
        
        int res = -1;
        for(int d = -1; d <= 1; d++) {
            int nr = r + d;
            int nc = c + 1;
            if(nr >= n / 2 && nc >= 0 && nr < n && nc < n) {
                int ret = dfs_2(n, fruits, nr, nc, steps + 1, dp);
                if(ret != -1) {
                    res = std::max(res, ret + fruits[r][c]);
                }
            }
        }
        
        return dp[key] = res;
    }

    int maxCollectedFruits(std::vector<std::vector<int>>& fruits) {
        int n = fruits.size();
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += fruits[i][i];
            fruits[i][i] = 0;
        }
    
        std::map<std::pair<int, int>, int> dp;
        ans += dfs_1(n, fruits, 0, n - 1, 0, dp);
        
        dp.clear();
        ans += dfs_2(n, fruits, n - 1, 0, 0, dp);
        
        return ans;
    }
};
