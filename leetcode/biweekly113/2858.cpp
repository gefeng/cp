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
    int dfs1(std::vector<std::vector<std::pair<int, int>>>& g, int v, int p, std::vector<int>& save) {
        int res = 0;
        for(auto& nei : g[v]) {
            if(nei.first != p) {
                res += dfs1(g, nei.first, v, save) + (nei.second == 1 ? 0 : 1);
            }
        }
        save[v] = res;
        return res;
    }

    void dfs2(std::vector<std::vector<std::pair<int, int>>>& g, int v, int p, int d, std::vector<int>& save, std::vector<int>& ans) {
        if(p == -1) {
            ans[v] = save[v];
        } else {
            int x = ans[p] - (d == 1 ? 0 : 1) - save[v];
            ans[v] = x + save[v] + (d == 1 ? 1 : 0);
        }
        
        for(auto& nei : g[v]) {
            if(nei.first != p) {
                dfs2(g, nei.first, v, nei.second, save, ans);
            }
        }
    }
    
    std::vector<int> minEdgeReversals(int n, std::vector<std::vector<int>>& edges) {
        std::vector<int> ans(n, 0);
        std::vector<std::vector<std::pair<int, int>>> g(n);
        
        for(auto& e : edges) {
            g[e[0]].emplace_back(e[1], 1);
            g[e[1]].emplace_back(e[0], 0);
        }
        
        std::vector<int> save(n, 0);
        dfs1(g, 0, -1, save);
        dfs2(g, 0, -1, -1, save, ans);
        
        return ans;
    }
};
