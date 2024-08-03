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
    int minFlips(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int ans = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int l = 0, r = m - 1; l < r; l += 1, r -= 1) {
                if(grid[i][l] != grid[i][r]) {
                    cnt += 1;
                }
            }
        }
        
        ans = cnt;
        cnt = 0;
        for(int i = 0; i < m; i++) {
            for(int l = 0, r = n - 1; l < r; l += 1, r -= 1) {
                if(grid[l][i] != grid[r][i]) {
                    cnt += 1;
                }
            }
        }
        
        ans = std::min(ans, cnt);
        
        return ans;
    }
};
