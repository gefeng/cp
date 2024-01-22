#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int INF = 1e9;

class Solution {
public:
    std::array<int, 7> dfs(std::vector<std::vector<int>>& g, std::vector<int>& cost, int v, int p, std::vector<long long>& ans) {
        int tot = 1;
        int max1 = -INF;
        int max2 = -INF;
        int max3 = -INF;
        int min1 = INF;
        int min2 = INF;
        int min3 = INF;
        
        auto comp = [&](int x) {
            if(x > 0) {
                if(x > max1) {
                    max3 = max2;
                    max2 = max1;
                    max1 = x;
                } else if(x > max2) {
                    max3 = max2;
                    max2 = x;
                } else if(x > max3) {
                    max3 = x;
                }
            }
            
            if(x < 0) {
                if(x < min1) {
                    min3 = min2;
                    min2 = min1;
                    min1 = x;
                } else if(x < min2) {
                    min3 = min2;
                    min2 = x;
                } else if(x < min3) {
                    min3 = x;
                }
            }
        };
        
        for(int nei : g[v]) {
            if(nei == p) {
                continue;
            }
            std::array<int, 7> x = dfs(g, cost, nei, v, ans);
            tot += x[0];
            
            for(int i = 1; i < 7; i++) {
                if(std::abs(x[i]) != INF) {
                    comp(x[i]);
                }
            }
        }
        
        comp(cost[v]);
    
        if(tot < 3) {
            ans[v] = 1;
        } else {
            int64_t p = 0;
            if(max1 != -INF && max2 != -INF && max3 != -INF) {
                p = (int64_t)max1 * max2 * max3;
            }
            if(min1 != INF && min2 != INF && max1 != -INF) {
                p = std::max(p, (int64_t)min1 * min2 * max1);
            }
            
            ans[v] = p;
        }
        
        return {tot, max1, max2, max3, min1, min2, min3};
    }
    
    std::vector<long long> placedCoins(std::vector<std::vector<int>>& edges, std::vector<int>& cost) {
        int n = cost.size();
        std::vector<long long> ans(n);
        
        std::vector<std::vector<int>> g(n);
        for(auto& e : edges) {
            int u = e[0];
            int v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        dfs(g, cost, 0, -1, ans);
        
        return ans;
    }
};
