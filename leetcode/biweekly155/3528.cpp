#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int MOD = int(1e9) + 7;

class Solution {
public:
    void dfs(std::vector<std::vector<std::pair<int, int64_t>>>& g, int v, int64_t x, std::vector<int>& ans) {
        ans[v] = x;
        
        for(auto [nei, mul] : g[v]) {
            dfs(g, nei, x * mul % MOD, ans);
        }
    }
    
    std::vector<int> baseUnitConversions(std::vector<std::vector<int>>& conversions) {
        int n = conversions.size();
        
        std::vector<std::vector<std::pair<int, int64_t>>> g(n + 1);
        for(int i = 0; i < n; i++) {
            int u = conversions[i][0];
            int v = conversions[i][1];
            int64_t mul = conversions[i][2];
            g[u].emplace_back(v, mul);
        }
        
        std::vector<int> ans(n + 1);
        dfs(g, 0, 1, ans);
        
        return ans;
    }
};
