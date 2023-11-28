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
    bool areSimilar(std::vector<std::vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        k %= m;
        std::vector<std::vector<int>> a(n, std::vector<int>(m, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                a[i][j] = i % 2 == 0 ? mat[i][((j - k) + m) % m] : mat[i][(j + k) % m];
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(a[i][j] != mat[i][j]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
