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
        for(int lx = 0, rx = n - 1; lx < rx; lx += 1, rx -= 1) {
            for(int ly = 0, ry = m - 1; ly < ry; ly += 1, ry -= 1) {
                int cnt = 0;
                if(grid[lx][ly] == 1) {
                    cnt += 1;
                } 
                if(grid[lx][ry] == 1) {
                    cnt += 1;
                }
                if(grid[rx][ly] == 1) {
                    cnt += 1;
                }
                if(grid[rx][ry] == 1) {
                    cnt += 1;
                }
                
                ans += std::min(cnt, 4 - cnt);
            }
        }
        
        int flip = 0;
        int cnt = 0;
        if(n % 2 == 1) {
            for(int l = 0, r = m - 1; l < r; l += 1, r -= 1) {
                if(grid[n / 2][l] != grid[n / 2][r]) {
                    flip += 1;
                } else {
                    if(grid[n / 2][l] == 1) {
                        cnt += 1;
                    }
                }
            }
        }
        
        if(m % 2 == 1) {
            for(int l = 0, r = n - 1; l < r; l += 1, r -= 1) {
                if(grid[l][m / 2] != grid[r][m / 2]) {
                    flip += 1;
                } else {
                    if(grid[l][m / 2] == 1) {
                        cnt += 1;
                    }
                }
            }
        }
        
        if(cnt % 2 == 0 || flip) {
            ans += flip;
        } else {
            ans += 2;
        }
        
        if(n % 2 == 1 && m % 2 == 1) {
            ans += grid[n / 2][m / 2];
        }
        
        return ans;
    }
};
