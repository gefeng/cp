#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int INF = (int)1e9;

class Solution {
public:
    int minimumOperationsToWriteY(std::vector<std::vector<int>>& grid) {
        int ans = INF;
        int n = grid.size();
        
        std::vector<std::vector<int>> is_y(n, std::vector<int>(n, 0));
        for(int i = 0, r = 0, c = 0; i <= n / 2; i++) {
            is_y[r + i][c + i] = 1;
        }
        
        for(int i = 0, r = 0, c = n - 1; i <= n / 2; i++) {
            is_y[r + i][c - i] = 1;
        }
        
        for(int i = 0, r = n / 2; i <= n / 2; i++) {
            is_y[r + i][n / 2] = 1; 
        }
        
        for(int a = 0; a <= 2; a++) {
            for(int b = 0; b <= 2; b++) {
                if(a == b) {
                    continue;
                }
                int cnt = 0;
                for(int r = 0; r < n; r++) {
                    for(int c = 0; c < n; c++) {
                        if(is_y[r][c]) {
                            cnt += grid[r][c] == a ? 0 : 1;
                        } else {
                            cnt += grid[r][c] == b ? 0 : 1;
                        }
                    }
                }
                
                ans = std::min(ans, cnt);
            }
        }
        
        return ans;
    }
};
