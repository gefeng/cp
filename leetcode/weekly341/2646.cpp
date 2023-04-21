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
    int minimumTotalPrice(int n, std::vector<std::vector<int>>& edges, 
            std::vector<int>& price, std::vector<std::vector<int>>& trips) {
        std::vector<std::vector<int>> G(n);
        
        for(auto& e : edges) {
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }
        
        std::vector<int> freq(n, 0);
        for(auto& t : trips) {
            std::vector<int> path;
            dfs1(G, t[0], -1, t[1], path);
            
            for(int v : path) {
                freq[v] += 1;
            }
        }
        
        std::vector<std::vector<int>> dp(3, std::vector<int>(n, -1));
        
        return dfs2(G, price, freq, 0, -1, 2, dp);
    }
    
    bool dfs1(std::vector<std::vector<int>>& G, int v, int p, int t, std::vector<int>& path) {
        path.push_back(v);
        if(v == t) {
            return true;
        }
        
        for(int nei : G[v]) {
            if(nei != p) {
                if(dfs1(G, nei, v, t, path)) {
                    return true;
                }
            }
        }
        
        path.pop_back();
        
        return false;
    }
    
    int dfs2(std::vector<std::vector<int>>& G, std::vector<int>& price, 
            std::vector<int>& freq, int v, int p, int pick_p, std::vector<std::vector<int>>& dp) {
        if(dp[pick_p][v] != -1) {
            return dp[pick_p][v];
        }
        
        if(pick_p == 1) {
            int res = freq[v] * price[v];
            for(int nei : G[v]) {
                if(nei == p) {
                    continue;
                }
                
                res += dfs2(G, price, freq, nei, v, 0, dp);
            }
            
            return dp[pick_p][v] = res;
        } else {
            int pick = freq[v] * (price[v] / 2);
            int skip = freq[v] * price[v];
            
            for(int nei : G[v]) {
                if(nei == p) {
                    continue;
                }
                
                pick += dfs2(G, price, freq, nei, v, 1, dp);
            }
            
            for(int nei : G[v]) {
                if(nei == p) {
                    continue;
                }
                
                skip += dfs2(G, price, freq, nei, v, 0, dp);
            }
            
            return dp[pick_p][v] = std::min(pick, skip);
        }
    }
};
