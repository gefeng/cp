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
public:
    int minimumDiameterAfterMerge(std::vector<std::vector<int>>& edges1, std::vector<std::vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        
        std::vector<std::vector<int>> g1(n);
        std::vector<std::vector<int>> g2(m);
        for(int i = 0; i < n - 1; i++) {
            int u = edges1[i][0];
            int v = edges1[i][1];
            g1[u].push_back(v);
            g1[v].push_back(u);
        }
        
        for(int i = 0; i < m - 1; i++) {
            int u = edges2[i][0];
            int v = edges2[i][1];
            g2[u].push_back(v);
            g2[v].push_back(u);
        }
        
        auto bfs = [](std::vector<std::vector<int>>& g, int root, std::vector<int>& dist) {
            int n = g.size();
            std::queue<int> q;
            q.push(root);
            dist[root] = 0;
            int max_d = 0;
            int max_v = root;
            while(!q.empty()) {
                int size = q.size();
                while(size--) {
                    int v = q.front();
                    q.pop();
                    if(dist[v] > max_d) {
                        max_d = dist[v];
                        max_v = v;
                    }
                    
                    for(int nei : g[v]) {
                        if(dist[nei] == -1) {
                            dist[nei] = dist[v] + 1;
                            q.push(nei);
                        }
                    }
                }
            }
            return max_v;
        };
        
        int ans = 0;
        int a1 = -1;
        int a2 = -1;
        int b1 = -1;
        int b2 = -1;
        std::vector<int> dist1(n, -1);
        std::vector<int> dist2(m, -1);
        a1 = bfs(g1, 0, dist1);
        dist1.clear();
        dist1.resize(n, -1);
        b1 = bfs(g1, a1, dist1);
        int mid1 = -1;
        for(int v = 0; v < n; v++) {
            if(dist1[v] == dist1[b1] / 2) {
                mid1 = v;
                break;
            }
        }
    
        a2 = bfs(g2, 0, dist2);
        dist2.clear();
        dist2.resize(m, -1);
        b2 = bfs(g2, a2, dist2);
        int mid2 = -1;
        for(int v = 0; v < m; v++) {
            if(dist2[v] == dist2[b2] / 2) {
                mid2 = v;
                break;
            }
        }
        
        ans = std::max(dist1[b1], dist2[b2]);
        ans = std::max(ans, std::max(dist1[mid1], dist1[b1] - dist1[mid1]) + std::max(dist2[mid2], dist2[b2] - dist2[mid2]) + 1);
        
        return ans;
    }
};
