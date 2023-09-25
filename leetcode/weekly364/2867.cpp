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
    std::vector<int> is_prime;
    long long countPaths(int n, std::vector<std::vector<int>>& edges) {
        if(n == 1) {
            return 0;
        }
        std::vector<std::vector<int>> g(n);
        
        for(auto& e : edges) {
            e[0] -= 1;
            e[1] -= 1;
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        is_prime.resize(n + 1, 1);
        is_prime[0] = 0;
        is_prime[1] = 0;
        for(int i = 2; i <= n; i++) {
            if(is_prime[i]) {
                for(int j = i + i; j <= n; j += i) {
                    is_prime[j] = 0;
                }   
            }
        }
        
        std::vector<std::vector<int64_t>> dp(n, std::vector<int64_t>(3, 0));
        
        return dfs(n, g, 0, -1, dp);
    }
    
    int64_t dfs(int n, std::vector<std::vector<int>>& g, int v, int p, std::vector<std::vector<int64_t>>& dp) {
        int64_t res = 0;
        
        if(is_prime[v + 1]) {
            dp[v][1] += 1;
        } else {
            dp[v][0] += 1;
        }
        
        int64_t sum0 = 0;
        int64_t sum1 = 0;
        for(int nei : g[v]) {
            if(nei != p) {
                res += dfs(n, g, nei, v, dp);
                sum0 += dp[nei][0];
                sum1 += dp[nei][1];
                
                if(is_prime[v + 1]) {
                    dp[v][2] += dp[nei][2] + dp[nei][1];
                    dp[v][1] += dp[nei][0];
                } else {
                    for(int i = 0; i < 3; i++) {
                        dp[v][i] += dp[nei][i];
                    }
                }
            }
        }
        
        if(g[v].size() != 1 || g[v].front() != p) {
            res += dp[v][1] - (is_prime[v + 1] ? 1 : 0);
        }
        
        if(is_prime[v + 1]) {
            for(int nei : g[v]) {
                if(nei != p) {
                    sum0 -= dp[nei][0];
                    res += dp[nei][0] * sum0;
                }
            }
        } else {
            for(int nei : g[v]) {
                if(nei != p) {
                    res += dp[nei][0] * (sum1 - dp[nei][1]);
                }
            }
        }
    
        return res;
    }
};
