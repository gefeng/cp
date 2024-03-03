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
    int countSubmatrices(std::vector<std::vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        
        std::vector<std::vector<int>> psum(n + 1, std::vector<int>(m + 1, 0));
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + grid[i - 1][j - 1];
                if(psum[i][j] <= k) {
                    ans += 1;
                }
            }
        }
    
        return ans;
    }
};
