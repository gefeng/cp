#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(1e9) + 7;
constexpr int MAX = 32;

class Solution {
public:
    int64_t dfs(int n, int m, std::vector<std::vector<int>>& g, int k, int r, int c, int sum, std::vector<std::vector<std::vector<int64_t>>>& dp) {
        if(r == n - 1 && c == m - 1) {
            return sum == k ? 1 : 0;
        }
        if(dp[sum][r][c] != -1) {
            return dp[sum][r][c];
        }
        
        int64_t res = 0;
        if(r + 1 < n) {
            res += dfs(n, m, g, k, r + 1, c, sum ^ g[r + 1][c], dp);
            res %= MOD;
        }
        
        if(c + 1 < m) {
            res += dfs(n, m, g, k, r, c + 1, sum ^ g[r][c + 1], dp);
            res %= MOD;
        }
        
        return dp[sum][r][c] = res;
    }
    
    int countPathsWithXorValue(std::vector<std::vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        
        std::vector<std::vector<std::vector<int64_t>>> dp(MAX + 1, std::vector<std::vector<int64_t>>(n, std::vector<int64_t>(m, -1)));
        
        return dfs(n, m, grid, k, 0, 0, grid[0][0], dp);
    }
};
