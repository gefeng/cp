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
    std::vector<std::vector<int>> differenceOfDistinctValues(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        std::vector<std::vector<int>> ans(n, std::vector<int>(m, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int r = i - 1;
                int c = j - 1;
                std::set<int> s1;
                std::set<int> s2;
                while(r >= 0 && c >= 0 && r < n && c < m) {
                    s1.insert(grid[r][c]);
                    r -= 1;
                    c -= 1;
                }
                
                r = i + 1;
                c = j + 1;
                while(r >= 0 && c >= 0 && r < n && c < m) {
                    s2.insert(grid[r][c]);
                    r += 1;
                    c += 1;
                }
                
                ans[i][j] = abs((int)s1.size() - (int)s2.size());
            }
        }
        
        return ans;
    }
};
