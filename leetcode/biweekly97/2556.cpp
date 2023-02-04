#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> a(m, vector<int>(n, 0));
        vector<vector<int>> b(m, vector<int>(n, 0));
        
        int r = 0;
        int c = 0;
        while(true) {
            a[r][c] += 1;
            if(c + 1 < n && grid[r][c + 1] == 1) {
                c += 1;
            } else if(r + 1 < m && grid[r + 1][c] == 1) {
                r += 1;
            } else {
                break;
            }
        }
        
        r = 0;
        c = 0;
        while(true) {
            b[r][c] += 1;
            if(r + 1 < m && grid[r + 1][c] == 1) {
                r += 1;
            } else if(c + 1 < n && grid[r][c + 1] == 1) {
                c += 1;
            } else {
                break;
            }
        }
        
        if(a[m - 1][n - 1] == 0 || b[m - 1][n - 1] == 0) {
            return true;
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if((i == 0 && j == 0) || (i == m - 1 && j == n - 1)) {
                    continue;
                }
                
                if(a[i][j] == 1 && b[i][j] == 1) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
