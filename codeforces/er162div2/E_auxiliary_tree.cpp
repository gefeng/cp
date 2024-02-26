#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

struct lca {
    public:   
        lca(int n, int log, int root, std::vector<std::vector<int>>& adj) : _n(n), _log(log), _root(root), _timer(0) {
            _up.resize(n, std::vector<int>(log + 1, 0));
            _t_in.resize(n, 0);
            _t_out.resize(n, 0);
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

// retrive pre-order (dist[u] < dist[v] means u is before v in pre-order)
void preorder(std::vector<std::vector<int>>& G, int v, int p, int& d, std::vector<int>& dist) {
    dist[v] = d++;
    for(int nei : G[v]) {
        if(nei != p) {
            preorder(G, nei, v, d, dist);
        }
    }
}

// build auxiliary tree (virtual tree)
// v is a set of points on which the auxiliary tree is constructed.
// dist saves pre-order, see comment of preorder() function.
// m is used for saving mapping from origional tree node's id to compressed tree node' id, this should be a vector
// of orignal tree's size. This should be global to make sure TC for building auxiliary tree is amortized.
// return nodes, parents and mapping of node's id to node's id in original tree (cv[0] is the root of the compressed tree).
void compress(std::vector<int>& v, std::vector<int>& dist, std::vector<int>& m, lca& lca, 
        std::vector<int>& cv, std::vector<int>& cp, std::vector<int>& cm) {
    int n = v.size();
    auto cmp = [&](int u, int v) {
        return dist[u] < dist[v];
    };
    cv.resize(n, -1);
    for(int i = 0; i < n; i++) {
        cv[i] = v[i];
    }
    std::sort(cv.begin(), cv.end(), cmp);
    for(int i = 1; i < n; i++) {
        cv.push_back(lca.get(cv[i - 1], cv[i])); 
    }
    std::sort(cv.begin(), cv.end(), cmp);
    cv.erase(std::unique(cv.begin(), cv.end()), cv.end());

    n = cv.size();
    cm.resize(n, -1);
    for(int i = 0; i < n; i++) {
        cm[i] = cv[i];
        m[cv[i]] = i;
        cv[i] = i;
    }

    cp.resize(n, -1);
    for(int i = 1; i < n; i++) {
        cp[i] = m[lca.get(cm[cv[i - 1]], cm[cv[i]])];
    }
}

int64_t dfs(std::vector<std::vector<int>>& g, std::vector<int>& A, std::vector<int>& cm, int tc, int v, int64_t& ans) {
    int c = A[cm[v]]; 
    
    int64_t res = 0;
    for(int nei : g[v]) {
        int64_t cnt = dfs(g, A, cm, tc, nei, ans);
        
        if(c != tc) {
            ans += res * cnt;
        } else {
            ans += cnt;
        }
        
        res += cnt;
    }
    
    if(c == tc) {
        res = 1;
    }

    return res;
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    lca lca(N, 30, 0, G);
    
    int d = 0;
    std::vector<int> dist(N, 0);
    preorder(G, 0, -1, d, dist);

    std::vector<std::vector<int>> groups(N + 1);
    for(int i = 0; i < N; i++) {
        groups[A[i]].push_back(i);
    }

    std::vector<int> m(N, -1);
    int64_t ans = 0;
    for(int c = 1; c <= N; c++) {
        std::vector<int>& group = groups[c];

        if(group.empty()) {
            continue;
        }

        std::vector<int> cv, cp, cm;
        compress(group, dist, m, lca, cv, cp, cm);

        int n = cv.size();
        std::vector<std::vector<int>> g(n);
        for(int i = 1; i < n; i++) {
            g[cp[i]].push_back(i);
        }

        dfs(g, A, cm, c, 0, ans);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
