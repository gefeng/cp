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
    std::vector<int> findColumnWidth(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        std::vector<int> ans(n, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int x = abs(grid[j][i]);
                int len = 0;
                if(x != 0) {
                    while(x) {
                        len += 1;
                        x /= 10;
                    }
                    len = grid[j][i] < 0 ? len + 1 : len;
                } else {
                    len = 1;
                }
                ans[i] = std::max(ans[i], len);
            }
        }
        
        return ans;
    }
};
