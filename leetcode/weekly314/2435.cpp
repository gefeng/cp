#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
    using LL = long long;
    const LL MOD = (LL)1e9 + 7LL;
    array<int, 2> DR{0, 1};
    array<int, 2> DC{1, 0};
    
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<vector<LL>>> dp(m, vector<vector<LL>>(n, vector<LL>(k, -1)));
        
        return dfs(grid, k, 0, 0, 0, dp);
    }
    
    LL dfs(vector<vector<int>>& grid, int k, int r, int c, int rem, vector<vector<vector<LL>>>& dp) {
        int m = grid.size();
        int n = grid[0].size();
        if(r == m - 1 && c == n - 1) {
            return (rem + (grid[r][c] % k)) % k == 0 ? 1LL : 0LL;
        }
        
        if(dp[r][c][rem] != -1) {
            return dp[r][c][rem];
        }
        
        LL res = 0LL;
        for(int i = 0; i < 2; i++) {
            int nr = r + DR[i];
            int nc = c + DC[i];
            if(nr >= 0 && nc >= 0 && nr < m && nc < n) {
                res += dfs(grid, k, nr, nc, (rem + (grid[r][c] % k)) % k, dp);
                res %= MOD;
            }
        }
        
        return dp[r][c][rem] = res;
    }
};
