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
    std::vector<int> findMissingAndRepeatedValues(std::vector<std::vector<int>>& grid) {
        std::vector<int> ans(2);
        int n = grid.size();
        
        std::vector<int> s(n * n + 1, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                s[grid[i][j]] += 1;
            }
        }
        
        for(int i = 1; i <= n * n; i++) {
            if(s[i] == 2) {
                ans[0] = i;
            } else if(s[i] == 0) {
                ans[1] = i;
            }
        }
    
        return ans;
    }
};
