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

constexpr int64_t INF = int64_t(2e18);

class Solution {
public:
    std::vector<bool> findAnswer(int n, std::vector<std::vector<int>>& edges) {
        int m = edges.size();
        std::vector<std::vector<std::pair<int, int>>> g(n);
        std::vector<bool> ans(m, false);
        
        for(int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
    
        auto dijkstra = [&](int st) {
            std::priority_queue<std::pair<int64_t, int>, std::vector<std::pair<int64_t, int>>, std::greater<std::pair<int64_t, int>>> pq;
            std::vector<int64_t> best(n, INF);
            best[st] = 0;
            pq.emplace(0, st);
            while(!pq.empty()) {
                auto [d, v] = pq.top();
                pq.pop();

                if(best[v] != d) {
                    continue;
                }

                for(auto [u, w] : g[v]) {
                    int nd = d + w;
                    if(best[u] > nd) {
                        best[u] = nd;
                        pq.emplace(nd, u);
                    }
                }
            }
            
            return best;
        };
        
        std::vector<int64_t> d1 = dijkstra(0);
        std::vector<int64_t> d2 = dijkstra(n - 1);
        
        for(int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            if(d1[u] + d2[v] + w == d1[n - 1]) {
                ans[i] = true;
            }
            if(d1[v] + d2[u] + w == d1[n - 1]) {
                ans[i] = true;
            }
        }
        
        return ans;
    }
};
