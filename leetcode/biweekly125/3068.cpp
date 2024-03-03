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
    void dfs(std::vector<std::vector<int>>& G, std::vector<int>& nums, int k, int v, int p, std::vector<std::vector<int64_t>>& dp) {
        std::vector<int> save;
        for(int nei : G[v]) {
            if(nei != p) {
                dfs(G, nums, k, nei, v, dp);
            }
        }
        
        std::array<int64_t, 2> a = {0, -1};
        for(int nei : G[v]) {
            if(nei != p) {
                std::array<int64_t, 2> na = {};
                
                na[0] = std::max(na[0], a[0] + dp[nei][0]);
                na[0] = a[1] == -1 ? na[0] : std::max(na[0], a[1] + dp[nei][1]);
                na[1] = std::max(na[1], a[0] + dp[nei][1]);
                na[1] = a[1] == -1 ? na[1] : std::max(na[1], a[1] + dp[nei][0]);
                
                std::swap(a, na);
            }
        }
        
        if(p != -1) {
            dp[v][0] = a[0] + nums[v];
            if(a[1] != -1) {
                dp[v][0] = std::max(dp[v][0], a[1] + (nums[v] ^ k));
            }
            dp[v][1] = a[0] + (nums[v] ^ k);
            if(a[1] != -1) {
                dp[v][1] = std::max(dp[v][1], a[1] + nums[v]);
            }
        } else {
            dp[v][0] = a[0] + nums[v];
            dp[v][1] = a[1] + (nums[v] ^ k);
        }
    }
    
    long long maximumValueSum(std::vector<int>& nums, int k, std::vector<std::vector<int>>& edges) {
        int n = nums.size();
        std::vector<std::vector<int>> G(n);
        for(auto e : edges) {
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }
        
        std::vector<std::vector<int64_t>> dp(n, std::vector<int64_t>(2, 0));
        dfs(G, nums, k, 0, -1, dp);
        
        return std::max(dp[0][0], dp[0][1]);
    }
};
