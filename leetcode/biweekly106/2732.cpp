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
    std::vector<int> goodSubsetofBinaryMatrix(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        std::map<int, int> seen;
        std::vector<int> ans;
        
        for(int i = 0; i < m; i++) {
            int x = 0;
            for(int c = 0; c < n; c++) {
                x = x * 2 + grid[i][c];
            }
            
            if(x == 0) {
                ans.emplace_back(i);
                return ans;
            }
            
            for(int j = 0; j < (1 << n); j++) {
                if(seen.find(j) != seen.end() && (j & x) == 0) {
                    ans.emplace_back(seen[j]);
                    ans.emplace_back(i);
                    return ans;
                }
            }
            
            seen[x] = i;
        }
        
        return ans;
    }
};
