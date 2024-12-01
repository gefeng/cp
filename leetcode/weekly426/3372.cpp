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
    std::vector<int> maxTargetNodes(std::vector<std::vector<int>>& edges1, std::vector<std::vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        
        std::vector<std::vector<int>> g_1(n);
        std::vector<std::vector<int>> g_2(m);
        for(int i = 0; i < n - 1; i++) {
            int u = edges1[i][0];
            int v = edges1[i][1];
            g_1[u].push_back(v);
            g_1[v].push_back(u);
        }
        
        for(int i = 0; i < m - 1; i++) {
            int u = edges2[i][0];
            int v = edges2[i][1];
            g_2[u].push_back(v);
            g_2[v].push_back(u);
        }
    
        std::vector<int> cnt_1(n, 0);
        std::vector<int> cnt_2(m, 0);
        for(int i = 0; i < n; i++) {
            std::queue<int> q;
            std::vector<int> vis(n, 0);
            q.push(i);
            vis[i] = 1;
            int d = 0;
            while(!q.empty()) {
                int size = q.size();
                while(size--) {
                    int v = q.front();
                    q.pop();
                    
                    cnt_1[i] += 1;
                    
                    for(int nei : g_1[v]) {
                        if(!vis[nei]) {
                            q.push(nei);
                            vis[nei] = 1;
                        }
                    }
                }
                d += 1;
                if(d > k) {
                    break;
                }
            }
        }
        
        if(k) {
            for(int i = 0; i < m; i++) {
                std::queue<int> q;
                std::vector<int> vis(m, 0);
                q.push(i);
                vis[i] = 1;
                int d = 0;
                while(!q.empty()) {
                    int size = q.size();
                    while(size--) {
                        int v = q.front();
                        q.pop();

                        cnt_2[i] += 1;

                        for(int nei : g_2[v]) {
                            if(!vis[nei]) {
                                q.push(nei);
                                vis[nei] = 1;
                            }
                        }
                    }
                    d += 1;
                    if(d == k) {
                        break;
                    }
                }
            }
        }
        
        std::vector<int> ans(n, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans[i] = std::max(ans[i], cnt_1[i] + cnt_2[j]);
            }
        }
        
        return ans;
    }
};
