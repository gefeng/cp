#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

struct lca {
    public:   
        lca(int n, int log, int root, std::vector<std::vector<int>>& adj) : _n(n), _log(log), _root(root), _timer(0) {
            _up.resize(_n, std::vector<int>(log + 1, 0));
            _t_in.resize(_n, 0);
            _t_out.resize(_n, 0);
            preprocess(adj);
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
};

void get_size(std::vector<std::vector<int>>& G, int v, int p, std::vector<int>& size, std::vector<int>& par) {
    size[v] = 1;
    par[v] = p;
    for(int nei : G[v]) {
        if(nei == p) {
            continue;
        }
        get_size(G, nei, v, size, par);
        size[v] += size[nei];
    }
}

bool get_path(std::vector<std::vector<int>>& G, int t, int v, std::vector<int>& par, std::vector<int>& path, int bad = -1) {
    path.push_back(v);

    if(v == t) {
        return true;
    }

    for(int nei : G[v]) {
        if(nei == par[v] || nei == bad) {
            continue;
        }
        if(get_path(G, t, nei, par, path)) {
            return true;
        }
    }

    path.pop_back();

    return false;
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    std::vector<int> size(N, 0);
    std::vector<int> par(N, -1);
    get_size(G, 0, -1, size, par);    

    int64_t ans = static_cast<int64_t>(size[0] - 1) * size[0] / 2 + 1;
    for(int nei : G[0]) {
        ans -= static_cast<int64_t>(size[nei] - 1) * size[nei] / 2;
    }

    lca lca(N, 30, 0, G);
    int p1 = 0;
    int p2 = 0;
    int z = -1;
    for(int i = 1; i < N; i++) {
        int x = lca.get(p1, i);
        int y = lca.get(p2, i);
        if(i == 1) {
            p1 = i;
        } else {
            if(x == i && y == 0) {
            } else if(x == 0 && y == i) {
            } else if(x == p1 && y == 0) {
                p1 = i;
            } else if(x == 0 && y == p2) {
                p2 = i;
            } else {
                break;
            }
        }

        if(p2 == 0) {
            if(z == -1) {
                for(int nei : G[0]) {
                    if(lca.get(nei, 1) == nei) {
                        z = nei;
                        break;
                    }
                }
            }
            ans += static_cast<int64_t>(size[0] - size[z]) * size[p1];
        } else {
            ans += static_cast<int64_t>(size[p1]) * size[p2];
        }
    }
    
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
