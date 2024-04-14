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

constexpr int64_t INF = (int64_t)1e18;

class Solution {
public:
    std::vector<int> minimumTime(int n, std::vector<std::vector<int>>& edges, std::vector<int>& disappear) {
        std::vector<int64_t> best(n, INF);
        std::priority_queue<std::pair<int64_t, int>, std::vector<std::pair<int64_t, int>>, std::greater<std::pair<int64_t, int>>> pq;
        
        std::vector<std::vector<std::pair<int, int>>> g(n);
        int m = edges.size();
        for(int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
        
        pq.emplace((int64_t)0, 0);
        best[0] = 0;
        while(!pq.empty()) {
            auto [t, v] = pq.top();
            pq.pop();
            
            if(best[v] != t) {
                continue;
            }
            
            for(auto [u, d] : g[v]) {
                int64_t nt = t + d;
                if(nt >= disappear[u]) {
                    continue;
                }
                if(best[u] > nt) {
                    best[u] = nt;
                    pq.emplace(nt, u);
                }
            }
        }
        
        std::vector<int> ans(n, -1);
        for(int i = 0; i < n; i++) {
            if(best[i] != INF) {
                ans[i] = best[i];
            }
        }
        
        return ans;
    }
};
