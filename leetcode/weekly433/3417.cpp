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
    std::vector<int> zigzagTraversal(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        std::vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                for(int j = 0; j < m; j += 2) {
                    ans.push_back(grid[i][j]);
                }
            } else {
                for(int j = m % 2 == 0 ? m - 1 : m - 2; j >= 0; j -= 2) {
                    ans.push_back(grid[i][j]);
                }
            }
        }
        
        return ans;
    }
};
