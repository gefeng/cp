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
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> ans(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++) {
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                cnt += grid[i][j];
            }
            
            for(int j = 0; j < n; j++) {
                ans[i][j] = cnt - (n - cnt);
            }
        }
        
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(int j = 0; j < m; j++) {
                cnt += grid[j][i];
            }
            
            for(int j = 0; j < m; j++) {
                ans[j][i] += cnt - (m - cnt);
            }
        }
        
        return ans;
    }
};
