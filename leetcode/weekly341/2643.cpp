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
    std::vector<int> rowAndMaximumOnes(std::vector<std::vector<int>>& mat) {
        int row = 0;
        int max_f = 0;
        
        int m = mat.size();
        int n = mat[0].size();
        
        for(int i = 0; i < m; i++) {
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(mat[i][j]) {
                    cnt += 1;
                }
            }
            
            if(cnt > max_f) {
                max_f = cnt;
                row = i;
            }
        }
        
        return {row, max_f};
    }
};
