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
    std::vector<std::vector<int>> constructGridLayout(int n, std::vector<std::vector<int>>& edges) {
        int m = edges.size();
        std::vector<std::vector<int>> g(n);
        std::vector<int> degree(n, 0);
        std::vector<std::vector<int>> ans;
        for(int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            g[u].push_back(v);
            g[v].push_back(u);
            degree[u] += 1;
            degree[v] += 1;
        }
        
        int min_d = n;
        int max_d = 0;
        for(int i = 0; i < n; i++) {
            min_d = std::min(min_d, degree[i]);
            max_d = std::max(max_d, degree[i]);
        }
        
        std::vector<int> vis(n, 0);
        if(min_d == 1) {
            int v = -1;
            for(int i = 0; i < n; i++) {
                if(degree[i] == 1) {
                    v = i;
                    break;
                }
            }   
            ans.resize(1);
            while(true) {
                vis[v] = 1;
                ans[0].push_back(v);
                for(int nei : g[v]) {
                    if(!vis[nei]) {
                        v = nei;
                        break;
                    }
                }
                if(vis[v]) {
                    break;
                }
            }
        } else if(max_d == 4) {
            ans.resize(1);
            int v = -1;
            for(int i = 0; i < n; i++) {
                if(degree[i] == 2) {
                    v = i;
                    break;
                }
            }
            while(true) {
                vis[v] = 1;
                ans[0].push_back(v);
                if(degree[v] == 2 && ans[0].size() > 1) {
                    break;
                }
                for(int nei : g[v]) {
                    if(!vis[nei] && degree[nei] < 4) {
                        v = nei;
                        break;
                    }
                }
            }
            
            std::queue<int> q;
            for(int i : ans[0]) {
                q.push(i);
            }
            
            while(!q.empty()) {
                int size = q.size();
                ans.emplace_back();
                while(size--) {
                    v = q.front();
                    q.pop();
                    for(int nei : g[v]) {
                        if(!vis[nei]) {
                            vis[nei] = 1;
                            q.push(nei);
                            ans.back().push_back(nei);
                        }
                    }
                }
            }
            ans.pop_back();
        } else {
            ans.resize(2);
            int v1 = -1;
            int v2 = -1;
            for(int i = 0; i < n; i++) {
                if(degree[i] == 2) {
                    v1 = i;
                    for(int nei : g[i]) {
                        if(degree[nei] == 2) {
                            v2 = nei;
                            break;
                        }
                    }
                    break;
                }
            }
            
            while(true) {
                vis[v1] = 1;
                vis[v2] = 1;
                ans[0].push_back(v1);
                ans[1].push_back(v2);
                for(int nei : g[v1]) {
                    if(!vis[nei]) {
                        v1 = nei;
                        break;
                    }
                }
                for(int nei : g[v2]) {
                    if(!vis[nei]) {
                        v2 = nei;
                        break;
                    }
                }
                
                if(vis[v1]) {
                    break;
                }
            }
        }
        
        return ans;
    }
};
