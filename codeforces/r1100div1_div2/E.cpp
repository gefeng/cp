#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int64_t MOD = static_cast<int64_t>(998244353);

int dfs(std::vector<std::vector<int>>& G, int v, int p, std::vector<int>& maxsub, std::vector<int>& par) {
    par[v] = p;
    for(int u : G[v]) {
        if(u != p) {
            maxsub[v] = std::max(maxsub[v], dfs(G, u, v, maxsub, par));
        }
    }
    return std::max(maxsub[v], v);
}

void dfs2(std::vector<std::vector<int>>& G, int v, int p, int t, std::vector<int64_t>& dp) {
    if(v > t) {
        dp[G.size() - 1] += dp[v];
        dp[G.size() - 1] %= MOD;
    }
    for(int u : G[v]) {
        if(u != p) {
            dfs2(G, u, v, t, dp);
        }
    }
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> G(N);
    std::vector<int> degree(N, 0);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U--;
        V--;
        G[U].push_back(V);
        G[V].push_back(U);
        degree[U]++;
        degree[V]++;
    }

    if(G[N - 1].size() == 1) {
        std::cout << 1 << '\n';
        return;
    }

    std::vector<int> maxsub(N, -1); // max node of subtree rooted at v excluding v
    std::vector<int> par(N, -1);
    dfs(G, N - 1, -1, maxsub, par);

    int s = 0;
    for(int v = 0; v < N; v++) {
        if(G[v].size() == 1 && v != N - 1) {
            s = std::max(s, v);
        }
    }

    std::vector<int64_t> dp(N, 0);
    std::vector<int64_t> ds(N + 1, 0);
    dp[s] = 1;
    ds[s + 1] = 1;
    for(int v = s + 1; v < N - 1; v++) {
        int max_v = maxsub[v];
        if(v >= max_v + 1) {
            dp[v] = (ds[v] - ds[max_v + 1] + MOD) % MOD;
        }
        ds[v + 1] = (ds[v] + dp[v]) % MOD;
    }

    int t = -1;
    int c = -1;
    for(int v : G[N - 1]) {
        int max_v = std::max(v, maxsub[v]);
        if(max_v != N - 2) {
            t = std::max(t, max_v);
        } else {
            c = v;
        }
    }

    dfs2(G, c, N - 1, t, dp);

    std::cout << dp[N - 1] << '\n';
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
