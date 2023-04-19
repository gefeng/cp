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

using LL = long long;

constexpr LL INF = (LL)2e11;

class Solution {
    std::vector<std::vector<std::pair<int, int>>> G;
    int n;
public:
    Solution(int n, std::vector<std::vector<int>>& edges) {
        this->n = n;
        G.resize(n);
        for(auto& e : edges) {
            G[e[0]].emplace_back(e[1], e[2]);
        }
    }
    
    void addEdge(std::vector<int> edge) {
        G[edge[0]].emplace_back(edge[1], edge[2]);
    }
    
    int shortestPath(int node1, int node2) {
        auto cmp = [](const auto& a, const auto& b) {
            return a.second > b.second;
        };
        
        std::priority_queue<std::pair<int, LL>, std::vector<std::pair<int, LL>>, decltype(cmp)> pq(cmp);
        std::vector<LL> best(n, INF);
        
        best[node1] = 0LL;
        pq.emplace(node1, 0LL);
        
        while(!pq.empty()) {
            std::pair<int, LL> cur = pq.top();
            pq.pop();
            
            int v = cur.first;
            LL c = cur.second;
            
            if(best[v] != c) {
                continue;
            } 
            
            if(v == node2) {
                break;
            }
            
            for(auto& nei : G[v]) {
                int nv = nei.first;
                int nc = c + nei.second;
                
                if(best[nv] > nc) {
                    best[nv] = nc;
                    pq.emplace(nv, nc);
                }
            }
        }
        
        return best[node2] == INF ? -1 : best[node2];
    }
};
