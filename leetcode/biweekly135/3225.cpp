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
    long long maximumScore(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        
        if(n == 1) {
            return 0;
        }
        
        std::vector<std::vector<int64_t>> psum(n, std::vector<int64_t>(n + 1, 0));
        
        for(int c = 0; c < n; c++) {
            for(int r = 0; r < n; r++) {
                psum[c][r + 1] = psum[c][r] + grid[r][c];
            }
        }
        
        int64_t ans = 0;
        std::vector<int64_t> dp1(n + 1, 0);
        std::vector<int64_t> dp2(n + 1, 0);
        
        for(int c = 1; c < n; c++) {
            std::vector<int64_t> ndp1(n + 1, 0);
            std::vector<int64_t> ndp2(n + 1, 0);
            
            for(int i = 0; i <= n; i++) {
                for(int j = 0; j <= n; j++) {
                    if(i <= j) {
                        ndp1[i] = std::max(ndp1[i], std::max(dp1[j], dp2[j]));
                        ndp2[i] = std::max(ndp2[i], std::max(dp1[j], dp2[j]) + psum[c][j] - psum[c][i]);
                    } else {
                        ndp1[i] = std::max(ndp1[i], std::max(dp1[j], dp2[j]));
                        ndp1[i] = std::max(ndp1[i],  dp1[j] + psum[c - 1][i] - psum[c - 1][j]);
                        ndp2[i] = std::max(ndp2[i], std::max(dp2[j], dp1[j] + psum[c - 1][i] - psum[c - 1][j]));
                    }
                }
            }
            
            std::swap(dp1, ndp1);
            std::swap(dp2, ndp2);
        }
        
        for(int i = 0; i <= n; i++) {
            ans = std::max(ans, dp2[i]);
        }
        
        return ans;
    }
};
