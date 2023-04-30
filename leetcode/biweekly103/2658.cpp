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
    const std::array<int, 4> DR = {1, 0, -1, 0};
    const std::array<int, 4> DC = {0, 1, 0, -1};
public:
    int findMaxFish(std::vector<std::vector<int>>& grid) {
        int ans = 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        std::vector<std::vector<bool>> vis(n, std::vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && grid[i][j]) {
                    ans = std::max(ans, dfs(grid, vis, i, j));
                }
            }
        }
        
        return ans;
    }
    
    int dfs(std::vector<std::vector<int>>& g, std::vector<std::vector<bool>>& vis, int r, int c) {
        int n = g.size();
        int m = g[0].size();
        int res = g[r][c];
        vis[r][c] = true;
        
        for(int i = 0; i < 4; i++) {
            int nr = r + DR[i];
            int nc = c + DC[i];
            if(nr >= 0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc] && g[nr][nc]) {
                res += dfs(g, vis, nr, nc);
            }
        }
        
        return res;
    }
};
