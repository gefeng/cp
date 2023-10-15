#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)12345;

class Solution {
public:
    std::vector<std::vector<int>> constructProductMatrix(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        std::vector<std::vector<int>> ans(n, std::vector<int>(m, 0));
        
        std::vector<int64_t> save(n * m, 1);
        std::vector<int64_t> res(n * m, 1);
        save[n * m - 1] = grid[n - 1][m - 1];
        for(int i = n * m - 2; i >= 0; i--) {
            save[i] = save[i + 1] * grid[i / m][i % m] % MOD;
        }
        
        int64_t p = 1;
        for(int i = 0; i < n * m; i++) {
            res[i] = p * (i + 1 < n * m ? save[i + 1] : (int64_t)1) % MOD;
            ans[i / m][i % m] = res[i];
            p *= grid[i / m][i % m];
            p %= MOD;
        }
        
        return ans;
    }
};
