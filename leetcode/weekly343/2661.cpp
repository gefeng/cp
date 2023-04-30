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
    int firstCompleteIndex(std::vector<int>& arr, std::vector<std::vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        std::vector<int> row(n, 0);
        std::vector<int> col(m, 0);
        std::vector<int> v_r(m * n + 1, 0);
        std::vector<int> v_c(m * n + 1, 0);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                v_r[mat[i][j]] = i;
                v_c[mat[i][j]] = j;
            }
        }
        
        int ans = 0;
        for(int i = 0; i < m * n; i++) {
            int r = v_r[arr[i]];
            int c = v_c[arr[i]];

            if(++row[r] == m) {
                ans = i;
                break;
            }
            if(++col[c] == n) {
                ans = i;
                break;
            }
        }
        
        return ans;
    }
};
