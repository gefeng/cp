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
    void dfs(int sr, int sc, int tr, int tc, int l, int r, std::vector<std::vector<int>>& ans) {
        if(l == r) {
            ans[sr][sc] = l;
            return;
        }
        
        int m_r = (sr + tr) / 2;
        int m_c = (sc + tc) / 2;
        int v = (r - l + 1) / 4;

        dfs(sr, m_c + 1, m_r, tc, l, l + v - 1, ans);
        dfs(m_r + 1, m_c + 1, tr, tc, l + v, l + 2 * v - 1, ans);
        dfs(m_r + 1, sc, tr, m_c, l + 2 * v, l + 3 * v - 1, ans);
        dfs(sr, sc, m_r, m_c, l + 3 * v, r, ans);
    }
    
    std::vector<std::vector<int>> specialGrid(int n) {
        int m = int(std::pow(2, n));
        int max_v = int(std::pow(2, n * 2));
        std::vector<std::vector<int>> ans(m, std::vector<int>(m, 0));
        
        dfs(0, 0, m - 1, m - 1, 0, max_v - 1, ans);
        
        return ans;
    }
};
