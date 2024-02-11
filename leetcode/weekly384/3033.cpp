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
    std::vector<std::vector<int>> modifiedMatrix(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        std::vector<std::vector<int>> ans(n, std::vector<int>(m, 0));
        
        for(int i = 0; i < m; i++) {
            int max_v = -1;
            for(int j = 0; j < n; j++) {
                max_v = std::max(max_v, matrix[j][i]);
            }
            for(int j = 0; j < n; j++) {
                if(matrix[j][i] == -1) {
                    ans[j][i] = max_v;
                } else {
                    ans[j][i] = matrix[j][i];
                }
            }
        }
        
        return ans;
    }
};
