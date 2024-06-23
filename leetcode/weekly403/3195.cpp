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
    int minimumArea(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int min_r = n;
        int max_r = 0;
        int min_c = n;
        int max_c = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    min_r = std::min(min_r, i);
                    max_r = std::max(max_r, i);
                    min_c = std::min(min_c, j);
                    max_c = std::max(max_c, j);
                }
            }
        }
        
        return (max_r - min_r + 1) * (max_c - min_c + 1);
    }
};
