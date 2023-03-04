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

class Solution {
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n = edges.size() + 1;
        vector<vector<int>> G(n);
        
        for(int i = 0; i < n - 1; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        
        vector<set<int>> gs(n);
        for(auto& g : guesses) {
            gs[g[0]].insert(g[1]);
        }
        
        int correct = dfs1(G, gs, 0, -1);
        
        vector<bool> root(n);
        dfs2(G, gs, k, correct, root, 0, -1, 0, 0);
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(root[i]) {
                ans += 1;
            }
        }
        
        return ans;
    }
    
    int dfs1(vector<vector<int>>& G, vector<set<int>>& gs, int v, int p) {
        int res = 0;
        
        for(int nei : G[v]) {
            if(nei == p) {
                continue;
            }
            res += dfs1(G, gs, nei, v);
        }
        
        if(p != -1) {
            if(gs[p].find(v) != gs[p].end()) {
                res += 1;
            }
        }
        
        return res;
    }
    
    void dfs2(vector<vector<int>>& G, vector<set<int>>& gs, int k, int tot_correct, vector<bool>& root, int v, int p, int correct, int wrong) {
        if(p != -1) {
            if(gs[p].find(v) != gs[p].end()) {
                correct += 1;
            }
        }
        if(gs[v].find(p) != gs[v].end()) {
            wrong += 1;
        }
        
        for(int nei : G[v]) {
            if(nei == p) {
                continue;
            }
            
            dfs2(G, gs, k, tot_correct, root, nei, v, correct, wrong);
        }
    
        if(tot_correct - correct + wrong >= k) {
            root[v] = true;
        }
     }
};
