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
    void bipartite(std::vector<std::vector<int>>& g, int v, int c, std::vector<int>& color) {
        color[v] = c;
        for(int nei : g[v]) {
            if(color[nei] == -1) {
                bipartite(g, nei, c ^ 1, color);
            }
        }
    }
    
    std::vector<int> maxTargetNodes(std::vector<std::vector<int>>& edges1, std::vector<std::vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        
        std::vector<std::vector<int>> g_1(n);
        std::vector<std::vector<int>> g_2(m);
        for(int i = 0; i < n - 1; i++) {
            int u = edges1[i][0];
            int v = edges1[i][1];
            g_1[u].push_back(v);
            g_1[v].push_back(u);
        }
        
        for(int i = 0; i < m - 1; i++) {
            int u = edges2[i][0];
            int v = edges2[i][1];
            g_2[u].push_back(v);
            g_2[v].push_back(u);
        }
        
        std::vector<int> ans(n, 0);
        std::vector<int> color_1(n, -1);
        std::vector<int> color_2(m, -1);
        
        bipartite(g_1, 0, 0, color_1);
        bipartite(g_2, 0, 0, color_2);
        
        std::array<int, 2> cnt_1 = {};
        std::array<int, 2> cnt_2 = {};
    
        for(int i = 0; i < n; i++) {
            cnt_1[color_1[i]] += 1;
        }
        for(int i = 0; i < m; i++) {
            cnt_2[color_2[i]] += 1;
        }
        
        for(int i = 0; i < n; i++) {
            ans[i] = cnt_1[color_1[i]] + std::max(cnt_2[color_1[i]], cnt_2[color_1[i] ^ 1]);
        }
        return ans;
    }
};
