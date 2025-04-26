#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>
#include <queue>

class Solution {
public:
    int maxProfit(int n, std::vector<std::vector<int>>& edges, std::vector<int>& score) {
        int m = edges.size();
        int ans = 0;
        std::vector<std::vector<int>> g(n);
        std::vector<int> degree(n, 0);
        
        for(int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            g[u].push_back(v);
            degree[v] += 1;
        }
        
        std::vector<int> dep(n);
        std::vector<int> rdep(n);
        
        std::queue<int> q;
        for(int i = 0; i < n; i++) {
            if(degree[i] == 0) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            int v = q.front();
            q.pop();

            for(int nei : g[v]) {
                dep[nei] |= 1 << v;
                
                for(int i = 0; i < n; i++) {
                    if(dep[v] & (1 << i)) {
                        dep[nei] |= 1 << i;
                    }
                }
                
                if(--degree[nei] == 0) {
                    q.push(nei);
                }
            }   
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dep[i] & (1 << j)) {
                    rdep[j] |= 1 << i;
                }
            }
        }
        
        std::vector<int> dp(1 << n, 0);
        for(int i = 0; i < (1 << n); i++) {
            int cnt = __builtin_popcount(i);
            
            for(int j = 0; j < n; j++) {
                if(i & (1 << j)) {
                    continue;
                }
                
                if((dep[j] & i) == dep[j] && (rdep[j] & i) == 0) {
                    dp[i | (1 << j)] = std::max(dp[i | (1 << j)], dp[i] + (cnt + 1) * score[j]);
                }
            }
        }
        
        ans = dp[(1 << n) - 1];
        
        return ans;
    }
};
