#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int INF = (int)2e9;

class Solution {
    int ans = INF;
public:
    int collectTheCoins(std::vector<int>& coins, std::vector<std::vector<int>>& edges) {
        int n = coins.size();
        
        std::vector<int> dp1(n, 0);  // edges need to be traversed to collect all the coins in subtree rooted at i
        std::vector<std::unordered_map<int, int>> dp2(n);
        std::vector<std::vector<int>> G(n);
        
        for(auto& e : edges) {
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }
        
        dfs1(G, coins, dp1, dp2, 0, -1, 0);
        dfs2(G, coins, dp1, dp2, 0, -1, -1);
        
        return ans;
    }
    
    // return the depth of deepest node with coin
    int dfs1(std::vector<std::vector<int>>& G, std::vector<int>& coins, std::vector<int>& dp1, std::vector<std::unordered_map<int, int>>& dp2, int v, int p, int d) {
        int depth = -1;
        
        if(coins[v]) {
            depth = d;
        }
        
        for(int nei : G[v]) {
            if(nei == p) {
                continue;
            }
            
            int res = dfs1(G, coins, dp1, dp2, nei, v, d + 1);
         
            // depth difference >=  2
            if(res != -1 && res - d > 2) {
                dp1[v] += dp1[nei] + 2;
            }
            
            dp2[v][nei] = res == -1 ? -1 : res - d; 
            
            depth = std::max(depth, res);
        }
        
        return depth;
    }
    
    void dfs2(std::vector<std::vector<int>>& G, std::vector<int>& coins, std::vector<int>& dp1, std::vector<std::unordered_map<int, int>>& dp2, int v, int p, int max_d) {
        if(coins[v]) {
            max_d = std::max(0, max_d);
        }
        if(v != 0) {
            bool visit = max_d > 2;
            
            bool free = true;
            for(int nei : G[v]) {
                if(nei != p && dp2[v][nei] > 1) {
                    free = false;
                    break;
                } 
            }
            
            if(visit) {
                if(free) {
                    dp1[v] += dp1[p] - dp1[v] + 2;
                } else {
                    dp1[v] += dp1[p] - (dp1[v] + 2) + 2;   
                }
            }
        }
        
        ans = std::min(ans, dp1[v]);
        
        int max_1 = max_d;
        int max_2 = max_d;
        for(int nei : G[v]) {
            if(nei != p) {
                if(dp2[v][nei] > max_1) {
                    max_2 = max_1;
                    max_1 = dp2[v][nei];
                } else if(dp2[v][nei] > max_2) {
                    max_2 = dp2[v][nei];
                }
            }
        }
        
        for(int nei : G[v]) {
            if(nei != p) {
                int n_max_d = -1;
                if(dp2[v][nei] == max_1) {
                    n_max_d = max_2;
                } else {
                    n_max_d = max_1;
                }
                
                dfs2(G, coins, dp1, dp2, nei, v, n_max_d == -1 ? -1 : n_max_d + 1);
            }
        }
    }
};
