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
    int64_t dfs(std::vector<std::vector<int>>& g, std::vector<int>& values, int v, int p, int s, std::vector<std::vector<int64_t>>& dp) {
        if(g[v].size() == 1 && p != -1) {
            return s == 0 ? 0 : values[v];
        }
        if(dp[v][s] != -1) {
            return dp[v][s];
        }
    
        if(s == 0) {
            int64_t take = values[v];
            int64_t skip = 0;
            for(int nei : g[v]) {
                if(nei != p) {
                    take += dfs(g, values, nei, v, s, dp);
                }
            }
            for(int nei : g[v]) {
                if(nei != p) {
                    skip += dfs(g, values, nei, v, s ^ 1, dp);
                }
            }
            return dp[v][s] = std::max(take, skip);
        } else {
            int64_t take = values[v];
            for(int nei : g[v]) {
                if(nei != p) {
                    take += dfs(g, values, nei, v, s, dp);
                }
            }
            return dp[v][s] = take;
        }
    }
    
    long long maximumScoreAfterOperations(std::vector<std::vector<int>>& edges, std::vector<int>& values) {
        int n = values.size();
        std::vector<std::vector<int>> g(n);
        for(auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        std::vector<std::vector<int64_t>> dp(n, std::vector<int64_t>(2, -1));
        return dfs(g, values, 0, -1, 0, dp);
    }
};
