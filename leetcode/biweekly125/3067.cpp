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
    int dfs(std::vector<std::vector<std::pair<int, int>>>& G, int s, int v, int p, int d) {
        std::vector<int> a;
        int cnt = 0;
        for(auto nei : G[v]) {
            if(nei.first != p) {
                int x = dfs(G, s, nei.first, v, d + nei.second);
                cnt += x;
                if(p == -1 && x != 0) {
                    a.push_back(x);
                }
            }
        }
        
        if(p == -1) {
            int res = 0;
            cnt = 0;
            if(a.size() > 1) {
                for(int x : a) {
                    res += cnt * x;
                    cnt += x;
                }
            }
            return res;
        } else {
            cnt += d % s == 0 ? 1 : 0;
            return cnt;
        }
    }

    std::vector<int> countPairsOfConnectableServers(std::vector<std::vector<int>>& edges, int signalSpeed) {
        int n = edges.size() + 1;
        std::vector<int> ans(n, 0);
        
        std::vector<std::vector<std::pair<int, int>>> G(n);
        for(auto e : edges) {
            G[e[0]].emplace_back(e[1], e[2]);
            G[e[1]].emplace_back(e[0], e[2]);
        }
        
        for(int i = 0; i < n; i++) {
            ans[i] = dfs(G, signalSpeed, i, -1, 0); 
        }
        return ans;
    }
};
