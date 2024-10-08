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
    void dfs(std::vector<std::vector<int>>& g, std::vector<int>& vis, int v) {
        vis[v] = 1;
        
        for(int nei : g[v]) {
            if(!vis[nei]) {
                dfs(g, vis, nei);
            }
        }
    }
    
    std::vector<int> remainingMethods(int n, int k, std::vector<std::vector<int>>& invocations) {
        std::vector<int> ans;
        std::vector<std::vector<int>> g(n);
        int m = invocations.size();
        
        for(int i = 0; i < m; i++) {
            int u = invocations[i][0];
            int v = invocations[i][1];
            g[u].push_back(v);
        }
        
        bool can_delete = true;
        std::vector<int> vis(n, 0);
        
        dfs(g, vis, k);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                for(int nei : g[i]) {
                    if(vis[nei]) {
                        can_delete = false;
                    }
                }
            }
        }
        
        if(can_delete) {
            for(int i = 0; i < n; i++) {
                if(!vis[i]) {
                    ans.push_back(i);
                }
            }
        } else {
            for(int i = 0; i < n; i++) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};
