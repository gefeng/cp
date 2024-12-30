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
    int minimumOperations(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int ans = 0;
        for(int c = 0; c < m; c++) {
            for(int r = 1; r < n; r++) {
                int d = std::max(0, grid[r - 1][c] + 1 - grid[r][c]);
                ans += d;
                grid[r][c] += d;
            }
        }
        
        return ans;
    }
};
