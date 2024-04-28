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
    long long numberOfRightTriangles(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int64_t ans = 0;
        
        std::vector<std::vector<int>> row(n, std::vector<int>(m, 0));
        std::vector<std::vector<int>> col(m, std::vector<int>(n, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                row[i][j] = j == 0 ? grid[i][j] : row[i][j - 1] + grid[i][j];        
            }
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                col[i][j] = j == 0 ? grid[j][i] : col[i][j - 1] + grid[j][i];
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    continue;
                }
                
                int up = col[j][i] - grid[i][j];
                int down = col[j][n - 1] - col[j][i];
                int left = row[i][j] - grid[i][j];
                int right = row[i][m - 1] - row[i][j];
                ans += int64_t(up) * (left + right) + int64_t(down) * (left + right);
            }
        }
        
        return ans;
    }
};
