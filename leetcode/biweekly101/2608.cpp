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
    int findShortestCycle(int n, std::vector<std::vector<int>>& edges) {
        std::vector<std::vector<int>> G(n);
        
        for(auto& e : edges) {
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }
        
        std::vector<int> color(n, 0);
        std::vector<int> time(n, -1);
        int ans = -1;
        for(int i = 0; i < n; i++) {
            if(color[i] == 0) {
                std::vector<int> cycle;
                dfs(G, color, time, cycle, i, -1, 0);
                
                for(int c : cycle) {
                    ans = ans == -1 ? c : std::min(ans, c);
                }
            }
        }
        
        return ans;
    }
    
    void dfs(std::vector<std::vector<int>>& G, std::vector<int>& color, std::vector<int>& time, std::vector<int>& cycle, int v, int p, int t) {
        if(color[v] == 1) {
            cycle.push_back(t - time[v]);
            return;
        }
        
        color[v] = 1;
        time[v] = t;
        
        for(int nei : G[v]) {
            if(nei == p) {
                continue;
            }
            
            if(color[nei] == 2) {
                if(time[nei] <= t) {
                    continue;
                }
                time[nei] = t;
            }
            
            dfs(G, color, time, cycle, nei, v, t + 1);
        }
        
        color[v] = 2;
    }
};
