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
    void dfs_1(std::vector<std::vector<int>>& g, int v, int p, std::vector<std::vector<int>>& dp_1) {
        dp_1[0][v] = 1;
        dp_1[1][v] = 0;
        for(int nei : g[v]) {
            if(nei != p) {
                dfs_1(g, nei, v, dp_1);
                dp_1[0][v] += dp_1[1][nei];
                dp_1[1][v] += dp_1[0][nei];
            }
        }
    }
    
    void dfs_2(std::vector<std::vector<int>>& g, int v, int p, std::vector<std::vector<int>>& dp_1, std::vector<std::vector<int>>& dp_2) {
        if(p == -1) {
            dp_2[0][v] = dp_1[0][v];
            dp_2[1][v] = dp_1[1][v];
        } else {
            int p_eve = dp_2[0][p];
            int p_odd = dp_2[1][p];
            p_eve -= dp_1[1][v];
            p_odd -= dp_1[0][v];
            
            dp_2[0][v] = p_odd + dp_1[0][v];
            dp_2[1][v] = p_eve + dp_1[1][v];
        }
        
        for(int nei : g[v]) {
            if(nei != p) {
                dfs_2(g, nei, v, dp_1, dp_2);
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
        std::vector<std::vector<int>> dp_1(2, std::vector<int>(n, 0));
        std::vector<std::vector<int>> dp_2(2, std::vector<int>(n, 0));
        std::vector<std::vector<int>> dp_3(2, std::vector<int>(m, 0));
        std::vector<std::vector<int>> dp_4(2, std::vector<int>(m, 0));
        dfs_1(g_1, 0, -1, dp_1);
        dfs_2(g_1, 0, -1, dp_1, dp_2);
    
        dfs_1(g_2, 0, -1, dp_3);
        dfs_2(g_2, 0, -1, dp_3, dp_4);
        
        int max_odd = 0;
        for(int i = 0; i < m; i++) {
            max_odd = std::max(max_odd, dp_4[1][i]);
        }
        
        for(int i = 0; i < n; i++) {
            ans[i] = dp_2[0][i] + max_odd;
        }
        
        return ans;
    }
};
