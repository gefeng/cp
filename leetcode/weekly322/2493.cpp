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

using namespace std;

struct dsu {
    int n;
    vector<int> p;
    vector<int> w;
    dsu(int n)  : n(n) {
        p.resize(n, -1);
        w.resize(n, 1);
    }
    int find(int i) {
        if(p[i] < 0) {
            return i;
        }
        return p[i] = find(p[i]);
    }
    void unite(int i, int j) {
        int x = find(i);
        int y = find(j);
        if(x == y) {
            return;
        }
        if(w[x] >= w[y]) {
            p[y] = x;
            w[x] += w[y];
        } else {
            p[x] = y;
            w[y] += w[x];
        }
    }
    bool same(int i, int j) {
        return find(i) == find(j);
    }
};

class Solution {
public:
    int bfs(vector<vector<int>>& g, int n, int s) {
        queue<int> q;
        vector<bool> vis(n, false);
        
        q.push(s);
        vis[s] = true;
        
        int res = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int cur = q.front();
                q.pop();
                
                for(int nei : g[cur]) {
                    if(!vis[nei]) {
                        vis[nei] = true;
                        q.push(nei);
                    }
                }
            }

            res += 1;
        }
        
        
        return res;
    }
    
    bool is_bipartite(vector<vector<int>>& g, int n, vector<int>& color, int v, int c) {
        if(color[v] >= 0) {
            return color[v] == c;
        }
        
        color[v] = c;
        
        for(int nei : g[v]) {
            if(!is_bipartite(g, n, color, nei, c ^ 1)) {
                return false;
            }
        }
        
        return true;
    }
    
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);

        dsu uf(n);
        for(auto& e : edges) {
            g[e[0] - 1].push_back(e[1] - 1);
            g[e[1] - 1].push_back(e[0] - 1);
            uf.unite(e[0] - 1, e[1] - 1);
        }
        
        int ans = 0;
        
        vector<vector<int>> groups(n);
        for(int i = 0; i < n; i++) {
            groups[uf.find(i)].push_back(i);
        }
        
        for(int i = 0; i < n; i++) {
            if(uf.find(i) == i) {
                vector<int> color(n, -1);
                if(!is_bipartite(g, n, color, i, 0)) {
                    return -1;
                }
                
                int res = 0;
                for(int x : groups[i]) {
                    res = max(res, bfs(g, n, x));
                }
                ans += res;
            }
        }
        
        return ans;
    }
};
