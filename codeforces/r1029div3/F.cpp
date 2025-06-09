#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(1e9) + 7;

void dfs(std::vector<std::vector<int>>& G, int v, int p, std::vector<int>& par, std::vector<int>& leaf) {
    par[v] = p;

    if(p != -1 && G[v].size() == 1) {
        leaf.push_back(v);
    }
    
    for(int nei : G[v]) {
        if(nei != p) {
            dfs(G, nei, v, par, leaf);
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

    std::vector<int> par(N, -1);
    std::vector<int> leaf;
    dfs(G, 0, -1, par, leaf);

    if(leaf.size() > 2) {
        std::cout << 0 << '\n';
        return;
    }

    std::vector<int64_t> p_2(N + 1, 1);
    for(int i = 1; i <= N; i++) {
        p_2[i] = p_2[i - 1] * 2 % MOD;
    }

    if(leaf.size() == 1) {
        std::cout << p_2[N] << '\n';
        return;
    }

    std::vector<int> vis(N, 0);
    int now = leaf[0];
    int tot = 0;
    while(now != -1) {
        vis[now] = 1;
        now = par[now];
        tot += 1;
    }

    int lca = -1;
    int x = 0;
    int y = 0;
    now = leaf[1];
    while(now != -1 && !vis[now]) {
        now = par[now];
        y += 1;
    }
    lca = now;
    
    now = leaf[0];
    while(now != lca) {
        now = par[now];
        x += 1;
    }

    int64_t ans = 0;
    if(x == y) {
        ans = p_2[tot - x] * 2 % MOD;
    } else {
        int d = std::min(x, y);
        
        ans = p_2[std::max(x, y) - d + tot - x];
        ans += p_2[std::max(x, y) - d - 1 + tot - x]; 
        ans %= MOD;
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
