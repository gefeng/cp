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
    int maxSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        
        for(int i = 0; i <= m - 3; i++) {
            
            for(int j = 1; j < n - 1; j++) {
                int sum = 0;
                sum += grid[i][j] + grid[i][j - 1] + grid[i][j + 1];
                sum += grid[i + 1][j];
                sum += grid[i + 2][j] + grid[i + 2][j - 1] + grid[i + 2][j + 1];
                ans = max(ans, sum);
            }
        }
        
        return ans;
    }
};
