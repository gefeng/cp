#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)998244353;

void dfs(std::vector<std::vector<int>>& G, int v, int p, std::vector<int64_t>& dp, int64_t& ans) {
    int64_t res = 0;
    int size = 1;
    
    for(int nei : G[v]) {
        if(nei != p) {
            dfs(G, nei, v, dp, ans);
        }
    }

    if(p == -1 || G[v].size() > 1) {
        int64_t x = 1;
        int64_t y = 0;
        for(int nei : G[v]) {
            if(nei != p) {
                x *= dp[nei];
                x %= MOD;
                y += (dp[nei] - 1 + MOD) % MOD;
                y %= MOD;
            }
        } 
        res = (x + 1) % MOD;
        ans += y;
        ans %= MOD;
    } else {
        res = 2;
    }

    dp[v] = res;
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

    std::vector<int64_t> dp(N, 0); // how many sets that none of pair (u, v) where u is ancestor of v
    int64_t ans = 0;
    dfs(G, 0, -1, dp, ans);

    ans += dp[0];
    ans %= MOD;

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
