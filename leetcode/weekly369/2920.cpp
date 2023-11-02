#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int MAX = 15;
constexpr int INF = (int)2e9;

class Solution {
public:
    int dfs(int n, std::vector<std::vector<int>>& g, std::vector<int>& coins, int k, int v, int p, int cnt, std::vector<std::vector<int>>& dp) {
        if(dp[v][cnt] != -1) {
            return dp[v][cnt];
        }
        
        int res = 0;
        int x = coins[v];
        for(int i = 0; i < cnt; i++) {
            x /= 2;
        }
        
        int sum1 = x - k;
        int sum2 = -INF;
        for(int nei : g[v]) {
            if(nei != p) {
                sum1 += dfs(n, g, coins, k, nei, v, cnt, dp);
            }
        }
        
        if(cnt < MAX) {
            sum2 = x / 2;
            for(int nei : g[v]) {
                if(nei != p) {
                    sum2 += dfs(n, g, coins, k, nei, v, cnt + 1, dp);
                }
            }    
        }
        
        return dp[v][cnt] = std::max(sum1, sum2);
    }
    
    int maximumPoints(std::vector<std::vector<int>>& edges, std::vector<int>& coins, int k) {
        int n = edges.size() + 1;
        std::vector<std::vector<int>> g(n);
        
        for(auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        std::vector<std::vector<int>> dp(n, std::vector<int>(MAX + 1, -1));
        
        return dfs(n, g, coins, k, 0, -1, 0, dp);
    }
};
