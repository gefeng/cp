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
    const std::array<int, 3> DR = {-1, 0, 1};
    const std::array<int, 3> DC = {1, 1, 1};
public:
    int maxMoves(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        std::vector<std::vector<int>> dp(n, std::vector<int>(m, -1));
        
        for(int i = 0; i < n; i++) {
            dp[i][0] = 0;
        }
        
        int ans = 0;
        for(int c = 1; c < m; c++) {
            for(int r = 0; r < n; r++) {
                for(int i = 0; i < 3; i++) {
                    int pr = r - DR[i];
                    int pc = c - DC[i];
                    
                    if(pr >= 0 && pr < n && pc >= 0 && pc < m && grid[pr][pc] < grid[r][c] && dp[pr][pc] != -1) {
                        dp[r][c] = std::max(dp[r][c], dp[pr][pc] + 1);
                    }
                }
                
                ans = std::max(ans, dp[r][c]);
            }
        }
        
        return ans;
    }
};
