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

const array<int, 8> DR{-2, -2, 2, 2, 1, -1, 1, -1};
const array<int, 8> DC{-1, 1, -1, 1, 2, 2, -2, -2};

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        
        return dfs(n, grid, 0, 0, 0);
    }
    
    bool dfs(int n, vector<vector<int>>& g, int r, int c, int v) {
        if(v == n * n - 1) {
            return true;
        }
        
        for(int i = 0; i < 8; i++) {
            int nr = r + DR[i];
            int nc = c + DC[i];
            if(nr >= 0 && nc >= 0 && nr < n && nc < n && g[nr][nc] == v + 1) {
                return dfs(n, g, nr, nc, v + 1);
            }
        }
        
        return false;
    }
};
