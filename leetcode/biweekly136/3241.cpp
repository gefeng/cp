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
    int dfs1(std::vector<std::vector<int>>& g, int v, int p, std::vector<int>& dp1) {
        if(p != -1 && g[v].size() == 1) {
            return 0;
        }
        
        int max_t = 0;
        
        for(int nei : g[v]) {
            if(nei == p) {
                continue;
            }
            int ret = dfs1(g, nei, v, dp1);
            
            max_t = std::max(max_t, ret + (nei % 2 == 0 ? 2 : 1));
        }
        
        return dp1[v] = max_t;
    }
    
    void dfs2(std::vector<std::vector<int>>& g, int v, int p, std::vector<int>& dp1, std::vector<int>& dp2, std::vector<int>& ans) {
        int max_t = p == -1 ? 0 : dp2[v] + (p % 2 == 0 ? 2 : 1);
        int max1 = p == -1 ? 0 : max_t;
        int max2 = 0;
        for(int nei : g[v]) {
            if(nei == p) {
                continue;
            }
            
            int t = dp1[nei] + (nei % 2 == 0 ? 2 : 1);
            
            if(t > max1) {
                max2 = max1;
                max1 = t;
            } else if(t > max2) {
                max2 = t;
            }
        }
        
        ans[v] = max1;
        
        for(int nei : g[v]) {
            if(nei == p) {
                continue;
            }
            
            int t = dp1[nei] + (nei % 2 == 0 ? 2 : 1);
            
            dp2[nei] = t == max1 ? max2 : max1;
        }
        
        for(int nei : g[v]) {
            if(nei == p) {
                continue;
            }
            dfs2(g, nei, v, dp1, dp2, ans);
        }
    }
    
    std::vector<int> timeTaken(std::vector<std::vector<int>>& edges) {
        int n = edges.size() + 1;
        std::vector<std::vector<int>> g(n);
        
        for(auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        std::vector<int> dp1(n, 0);
        dfs1(g, 0, -1, dp1);
        
        std::vector<int> ans(n, 0);
        std::vector<int> dp2(n, 0);
        dfs2(g, 0, -1, dp1, dp2, ans);
        
        return ans;
    }
};
