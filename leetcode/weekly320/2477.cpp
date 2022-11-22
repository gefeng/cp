#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> G(n);
        for(auto& e : roads) {
            int u = e[0];
            int v = e[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        
        vector<bool> vis(n, false);
        return dfs(G, vis, seats, 0)[0];
    }
    
    array<LL, 3> dfs(vector<vector<int>>& G, vector<bool>& vis, int seats, int cur) {
        vis[cur] = true;
        
        LL tot_f = 0LL;
        LL tot_c = 0LL;
        LL tot_p = 1LL;
        for(int nei : G[cur]) {
            if(vis[nei]) continue;
            array<LL, 3> x = dfs(G, vis, seats, nei);
            tot_f += x[0];
            tot_f += x[1];
            tot_p += x[2];
        }
        
        tot_c = tot_p / seats + (tot_p % seats == 0 ? 0 : 1);
        return {tot_f, tot_c, tot_p};
    }
};
