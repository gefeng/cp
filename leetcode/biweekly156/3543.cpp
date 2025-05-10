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
    int maxWeight(int n, std::vector<std::vector<int>>& edges, int k, int t) {
        if(k == 0) {
            return 0;
        }
        
        int m = edges.size();
        std::vector<std::vector<std::vector<bool>>> dp(n, std::vector<std::vector<bool>>(k + 1, std::vector<bool>(t, false)));
        
        std::vector<std::vector<std::pair<int, int>>> g(n);
        std::vector<int> degree(n, 0);
        for(int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            g[u].emplace_back(v, w);
            degree[v] += 1;
        }
        
        std::queue<int> now;
        std::vector<int> max_len(n, 0);
        int ans = -1;
        for(int i = 0; i < n; i++) {
            if(degree[i] == 0) {
                now.push(i);
            }
            dp[i][0][0] = true;
        }
        
        while(!now.empty()) {
            int v = now.front();
            now.pop();
            
            int ub = max_len[v];
            
            for(int i = 0; i <= std::min(k - 1, ub); i++) {
                for(int j = 0; j < t; j++) {
                    if(!dp[v][i][j]) {
                        continue;
                    }
                    for(auto [nei, w] : g[v]) {
                        if(j + w < t && dp[v][i][j]) {
                            dp[nei][i + 1][j + w] = true;
                            if(i + 1 == k) {
                                ans = std::max(ans, j + w);
                            }
                        }
                    }
                }
            }

            for(auto [nei, w] : g[v]) {
                max_len[nei] = std::max(max_len[nei], max_len[v] + 1);
                if(--degree[nei] == 0) {
                    now.push(nei);
                }
            }
        }
        
        return ans;
    }
};
