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

class Solution {
    const int INF = (int)2e9;
public:
    std::vector<std::vector<int>> modifiedGraphEdges(int n, std::vector<std::vector<int>>& edges, int source, int destination, int target) {
        int m = edges.size();
        std::vector<std::vector<std::array<int, 3>>> g(n);
        
        for(int i = 0; i < m; i++) {
            auto e = edges[i];
            g[e[0]].push_back({e[1], e[2], i});
            g[e[1]].push_back({e[0], e[2], i});
        }
        
        auto cmp = [](const auto a, const auto b) {
            if(a[1] == b[1]) {
                return a[2] > b[2];
            }
            return a[1] > b[1];
        };
        
        std::priority_queue<std::array<int, 4>, std::vector<std::array<int, 4>>, decltype(cmp)> pq(cmp);
        std::vector<std::vector<int>> best(n, std::vector<int>(m + 1, INF));
        std::vector<std::vector<int>> pre_e(n, std::vector<int>(m + 1, -1));
        std::vector<std::vector<int>> pre_v(n, std::vector<int>(m + 1, -1));
        
        pq.push({source, 0, 0, -1});
        best[source][0] = 0;
        
        std::vector<std::vector<int>> ans;
        
        int shortest = INF;
        while(!pq.empty()) {
            std::array<int, 4> cur = pq.top();
            pq.pop();
            
            int v = cur[0];
            int c = cur[1];
            int d = cur[2];
            int p_e = cur[3];
            
            if(best[v][c] != d) {
                continue;
            }
            
            if(v == destination) {
                if(c == 0) {
                    shortest = d;
                    if(shortest < target) {
                        break;
                    }
                }
                
                if((c == 0 && d == target) || (c && d + c <= target)) {
                    int cur_c = c;
                    int cur_v = v;
                    std::vector<bool> vis(m, false);

                    while(cur_v != source) {
                        int cur_e = pre_e[cur_v][cur_c];
                        int nxt_c = cur_c;
                        vis[cur_e] = true;
                        
                        if(edges[cur_e][2] == -1) {
                            ans.push_back({edges[cur_e][0], edges[cur_e][1], cur_c == 1 ? target - d - c + 1 : 1});
                            nxt_c -= 1;
                        } else {
                            ans.push_back({edges[cur_e][0], edges[cur_e][1], edges[cur_e][2]});
                        }
                        
                        cur_v = pre_v[cur_v][cur_c];
                        cur_c = nxt_c;
                    }

                    for(int i = 0; i < m; i++) {
                        if(!vis[i]) {
                            ans.push_back({edges[i][0], edges[i][1], edges[i][2] == -1 ? (int)2e9 : edges[i][2]});
                        }
                    }

                    return ans;
                }
            }
        
            
            for(auto nei : g[v]) {
                int nv = nei[0];
                int nw = nei[1];
                int ne = nei[2];
                if(nw == -1) {
                    if(c + 1 <= m && best[nv][c + 1] > d) {
                        best[nv][c + 1] = d;
                        pre_e[nv][c + 1] = ne;
                        pre_v[nv][c + 1] = v;
                        pq.push({nv, c + 1, d, ne});
                    }
                } else {
                    if(best[nv][c] > d + nw) {
                        best[nv][c] = d + nw;
                        pre_e[nv][c] = ne;
                        pre_v[nv][c] = v;
                        pq.push({nv, c, d + nw, ne});
                    }
                }
            }
        }
        
        
        return ans;
    }
};
