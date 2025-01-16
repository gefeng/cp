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
    void dfs(std::vector<std::vector<int>>& g, std::vector<int>& vis, std::vector<int>& cnt, int v) {
        vis[v] = 1;
        for(int nei : g[v]) {
            if(!vis[nei]) {
                cnt[nei] += 1;
                dfs(g, vis, cnt, nei);
            }
        }
    }
    
    int minMaxWeight(int n, std::vector<std::vector<int>>& edges, int threshold) {
        int lo = 1;
        int hi = int(1e6);
        int ans = -1;
        
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            int good = 1;
            std::vector<std::vector<int>> g(n);
            for(auto& e : edges) {
                if(e[2] > mid) {
                    continue;
                }
                g[e[1]].push_back(e[0]);
            }
            
            std::vector<int> vis(n, 0);
            std::vector<int> cnt(n, 0);
            dfs(g, vis, cnt, 0);
            for(int i = 0; i < n; i++) {
                if(!vis[i] || cnt[i] > threshold) {
                    good = 0;
                    break;
                }
            }
            
            if(good) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return ans;
    }
};
