#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>
    
const int64_t INF = int64_t(2e18);

class Solution {
public:
    void dfs(int k, std::vector<std::vector<std::pair<int, int>>>& g, int v, int p, std::vector<std::vector<int64_t>>& dp) {
        int d = g[v].size();
        if(p != -1 && d == 1) {
            dp[0][v] = 0;
            dp[1][v] = 0;
            return;
        }

        std::vector<int64_t> a;
        int64_t sum_1 = 0;
        int64_t sum_2 = 0;
        for(auto [nei, w] : g[v]) {
            if(nei != p) {
                dfs(k, g, nei, v, dp);
                a.push_back(dp[0][nei] + w - dp[1][nei]);
                sum_1 += dp[1][nei];
            }
        }
        sum_2 = sum_1;
        
        std::sort(a.begin(), a.end(), std::greater<int64_t>());
        int m = a.size();
        int cnt = 0;
        
        for(int i = 0; i < std::min(m, k); i++) {
            if(a[i] > 0) {
                sum_1 += a[i];
                if(i) {
                    sum_2 += a[i - 1];
                }
                cnt += 1;
            } else {
                break;
            }
        }
        
        if(cnt == k) {
            dp[0][v] = sum_2;
            dp[1][v] = sum_1;
        } else {
            dp[0][v] = sum_1;
            dp[1][v] = sum_1;
        }
    }
    
    long long maximizeSumOfWeights(std::vector<std::vector<int>>& edges, int k) {
        int n = edges.size() + 1;
        std::vector<std::vector<std::pair<int, int>>> g(n);
        
        for(int i = 0; i < n - 1; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
        
        std::vector<std::vector<int64_t>> dp(2, std::vector<int64_t>(n, -INF));
        
        dfs(k, g, 0, -1, dp);
        
        return std::max(dp[0][0], dp[1][0]);
    }
};
