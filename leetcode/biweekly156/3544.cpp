#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int64_t INF = int64_t(2e18);

class Solution {
public:
    int64_t dfs(std::vector<std::vector<int>>& g, std::vector<int>& nums, int k, int v, int p, int inverted, int dist, std::vector<std::vector<std::vector<int64_t>>>& dp) {
        if(dp[inverted][dist][v] != -INF) {
            return dp[inverted][dist][v];
        }
        
        int64_t x = inverted ? -nums[v] : nums[v];
        int64_t y = -INF;
        if(dist == k) {
            y = -x;
        }
        
        for(int nei : g[v]) {
            if(nei != p) {
                x += dfs(g, nums, k, nei, v, inverted, std::min(dist + 1, k), dp);
                
                if(dist == k) {
                    y += dfs(g, nums, k, nei, v, inverted ^ 1, 1, dp);
                }
            }
        }
        
        return dp[inverted][dist][v] = std::max(x, y);
    }
    
    long long subtreeInversionSum(std::vector<std::vector<int>>& edges, std::vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<std::vector<int>> g(n);
        
        for(int i = 0; i < n - 1; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        std::vector<std::vector<std::vector<int64_t>>> dp(2, std::vector<std::vector<int64_t>>(k + 1, std::vector<int64_t>(n,  -INF)));
        
        return dfs(g, nums, k, 0, -1, 0, k, dp);
    }
};
