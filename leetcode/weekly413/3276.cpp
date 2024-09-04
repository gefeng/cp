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
    int maxScore(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        std::vector<std::array<int, 3>> a;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                a.push_back({i, j, grid[i][j]});
            }
        }
        
        std::sort(a.begin(), a.end(), [](const auto& x, const auto& y) {
            return x[2] < y[2];
        });
        
        std::vector<std::vector<int>> dp(n * m + 1, std::vector<int>(1 << n, -1));
        dp[0][0] = 0;
        for(int i = 1, k = 0; i <= n * m; i++) {
            if(i > 1 && a[i - 2][2] != a[i - 1][2]) {
                k = i - 1;
            }
            for(int j = 0; j < (1 << n); j++) {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j]);
                
                if(dp[k][j] != -1) {
                    if(!(j & (1 << a[i - 1][0]))) {
                        dp[i][j | (1 << a[i - 1][0])] = std::max(dp[i][j | (1 << a[i - 1][0])], dp[k][j] + a[i - 1][2]);
                    }
                }
            }
        }
        
        for(int i = 0; i < (1 << n); i++) {
            ans = std::max(ans, dp[n * m][i]);
        }
        return ans;
    }
};
