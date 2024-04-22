#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int INF = int(2e9);

class Solution {
public:
    int minimumOperations(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        std::vector<std::vector<int>> col(m, std::vector<int>(10, 0));
        for(int c = 0; c < m; c++) {
            for(int r = 0; r < n; r++) {
                col[c][grid[r][c]] += 1;
            }
        }
        
        std::vector<int> dp(10, INF);
        for(int i = 0; i < 10; i++) {
            dp[i] = n - col[0][i];
        }
        
        for(int i = 1; i < m; i++) {
            std::vector<int> ndp(10, INF);
            for(int j = 0; j < 10; j++) {
                for(int k = 0; k < 10; k++) {
                    if(j != k) {
                        ndp[j] = std::min(ndp[j], dp[k] + n - col[i][j]);
                    }
                }
            }
            std::swap(dp, ndp);
        }
        
        int ans = INF;
        for(int i = 0; i < 10; i++) {
            ans = std::min(ans, dp[i]);
        }
        
        return ans;
    }
};
