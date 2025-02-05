#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(1e9) + 7;

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

int64_t q_pow(int64_t x, int64_t y) {
    int64_t res = 1;
    while(y) {
        if(y & 1) {
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        y >>= 1;
    }
    return res;
}

void dfs(std::vector<std::vector<int>>& G, int v, int p, std::vector<int>& dist) {
    if(p != -1) {
        dist[v] = dist[p] + 1; 
    }

    for(int nei : G[v]) {
        if(nei != p) {
            dfs(G, nei, v, dist);
        }
    }
}

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    // dp[i][j] denotes probability of reaching y before reaching x
    // dp[i][j] = 1/2 * dp[i][j - 1] + 1/2 * dp[i - 1][j]
    std::vector<std::vector<int64_t>> dp(N + 1 + 1, std::vector<int64_t>(N + 1, 0));
    int64_t inv_2 = q_pow(2, MOD - 2);
    for(int i = 1; i <= N; i++) {
        dp[i][0] = 1;
    }
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            dp[i][j] = ((dp[i - 1][j] + dp[i][j - 1]) % MOD) * inv_2 % MOD; 
        }
    }

    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        std::vector<int> dist(N, 0);
        lca lca(N, 10, i, G);

        dfs(G, i, -1, dist);
        
        for(int a = 0; a < N; a++) {
            for(int b = a + 1; b < N; b++) {
                int c = lca.get(a, b);
                ans += dp[dist[a] - dist[c]][dist[b] - dist[c]];
                ans %= MOD;
            }
        }
    }

    ans *= q_pow(N, MOD - 2);
    ans %= MOD;
    
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
