#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int INF = 1e9;

struct lca {
public:   
    lca(int n, int log, int root, std::vector<std::vector<int>>& adj) : _n(n), _log(log), _root(root), _timer(0) {
        _up.resize(n, std::vector<int>(log + 1, 0));
        _t_in.resize(n, 0);
        _t_out.resize(n, 0);
        preprocess(adj);
    }

    void preprocess(std::vector<std::vector<int>>& adj) {
        dfs(adj, _root, _root); 
    }  

    void dfs(std::vector<std::vector<int>>& adj, int v, int p) {
        _t_in[v] = _timer++; 
       
        _up[v][0] = p;
        for(int i = 1; i <= _log; i++) {
            _up[v][i] = _up[_up[v][i - 1]][i - 1]; 
        } 

        for(int u : adj[v]) {
            if(u != p) {
                dfs(adj, u, v);
            }
        }

        _t_out[v] = _timer++;
    }

    bool is_ancestor(int u, int v) {
        return _t_in[u] <= _t_in[v] && _t_out[u] >= _t_out[v];
    }

    int get(int u, int v) {
        if(is_ancestor(u, v)) {
            return u;
        } 

        if(is_ancestor(v, u)) {
            return v;
        }

        // climb u to the highest node which is not the ancestor of v
        for(int i = _log; i >= 0; i--) {
            if(!is_ancestor(_up[u][i], v)) {
                u = _up[u][i];
            }
        }

        return _up[u][0];
    }
         
private:
    int _n;
    int _log;
    int _root;
    int _timer;

    // jump table
    std::vector<std::vector<int>> _up;

    // the time of first visit of each node
    std::vector<int> _t_in;

    // the time when left each node
    std::vector<int> _t_out;
};

class Solution {
public:
    void dfs(int n, std::vector<std::vector<std::pair<int, int>>>& g, int v, int p, int d, int w, std::vector<int>& save_sz, std::vector<std::vector<int>>& save_freq) {
        save_sz[v] = d;
        
        if(p != -1) {
            for(int i = 1; i <= 26; i++) {
                save_freq[v][i] = save_freq[p][i] + (i == w ? 1 : 0);
            }
        }
        
        for(auto [nv, nw] : g[v]) {
            if(nv != p) {
                dfs(n, g, nv, v, d + 1, nw, save_sz, save_freq);
            }
        }
    }
    
    std::vector<int> minOperationsQueries(int n, std::vector<std::vector<int>>& edges, std::vector<std::vector<int>>& queries) {
        std::vector<std::vector<int>> g1(n);
        std::vector<std::vector<std::pair<int, int>>> g2(n);
        
        for(auto& e : edges) {
            g1[e[0]].push_back(e[1]);
            g1[e[1]].push_back(e[0]);
            g2[e[0]].emplace_back(e[1], e[2]);
            g2[e[1]].emplace_back(e[0], e[2]);
        }
        
        lca lca(n, 30, 0, g1);
        
        std::vector<std::vector<int>> save_freq(n, std::vector<int>(27, 0));
        std::vector<int> save_sz(n, 0);
        
        dfs(n, g2, 0, -1, 0, 0, save_sz, save_freq);
        
        std::vector<int> ans;
        for(auto& q : queries) {
            int u = q[0];
            int v = q[1];
            int x = lca.get(u, v);
            int sz = save_sz[u] + save_sz[v] - 2 * save_sz[x];
            int res = INF;
            for(int w = 1; w <= 26; w++) {
                int cnt = save_freq[u][w] + save_freq[v][w] - 2 * save_freq[x][w];
                res = std::min(res, sz - cnt);
            }
            
            ans.push_back(res);
        }
        
        return ans;
    }
};
