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
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int ans = 0;
        
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++) {
            sort(grid[i].begin(), grid[i].end());
        }
        
        for(int i = 0; i < m; i++) {
            int max_v = 0;
            for(int j = 0; j < n; j++) {
                max_v = max(max_v, grid[j][i]);
            }
            ans += max_v;
        }
        
        return ans;
    }
};
