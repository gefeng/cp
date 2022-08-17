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
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int>(n - 2, 0));
        
        for(int i = 1; i < n - 1; i++) {
            for(int j = 1; j < n - 1; j++) {
                int max_v = 0;
                for(int r = 0; r < 3; r++) {
                    for(int c = 0; c < 3; c++) {
                        max_v = max(max_v, grid[r + i - 1][c + j - 1]);
                    }
                }
                
                ans[i - 1][j - 1] = max_v;
            }
        }
        
        return ans;
    }
};
