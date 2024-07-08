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
    int numberOfSubmatrices(std::vector<std::vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        
        std::vector<std::vector<int>> psum_x(n + 1, std::vector<int>(m + 1, 0));
        std::vector<std::vector<int>> psum_y(n + 1, std::vector<int>(m + 1, 0));
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                psum_x[i][j] = psum_x[i - 1][j] + psum_x[i][j - 1] - psum_x[i - 1][j - 1] + (grid[i - 1][j - 1] == 'X' ? 1 : 0);
                psum_y[i][j] = psum_y[i - 1][j] + psum_y[i][j - 1] - psum_y[i - 1][j - 1] + (grid[i - 1][j - 1] == 'Y' ? 1 : 0);
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int cnt_x = psum_x[i + 1][j + 1];
                int cnt_y = psum_y[i + 1][j + 1];
                if(cnt_x == cnt_y && cnt_x) {
                    ans += 1;
                }
            }
        }
        
        return ans;
    }
};
