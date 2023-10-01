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
    std::vector<int> countVisitedNodes(std::vector<int>& edges) {
        int n = edges.size();
        std::vector<int> dp(n, -1);
        
        for(int i = 0; i < n; i++) {
            if(dp[i] != -1) {
                continue;
            }
            
            std::set<int> s;
            int v = i;
            int d = 0;
            while(s.find(v) == s.end() && dp[v] == -1) {
                s.insert(v);
                v = edges[v];
                d += 1;
            }
            
            if(dp[v] != -1) {
                int c = v;
                v = i;
                while(dp[v] == -1) {
                    dp[v] = dp[c] + d;
                    d -= 1;
                    v = edges[v];
                }
            } else {
                int c = v;
                std::set<int> cycle;
                int len = 0;
                while(cycle.find(v) == cycle.end()) {
                    len += 1;
                    cycle.insert(v);
                    v = edges[v];
                }
                
                for(int x : cycle) {
                    dp[x] = len;
                }
                
                v = i;
                d -= len;
                while(cycle.find(v) == cycle.end()) {
                    dp[v] = d + len;
                    v = edges[v];
                    d -= 1;
                }
            }
        }
        
        return dp;
    }
};
