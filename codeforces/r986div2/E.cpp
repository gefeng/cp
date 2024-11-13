#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = int(2e9);
constexpr int64_t MOD = int64_t(998244353);

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

void dfs1(std::vector<std::vector<int>>& G, int v, int p, int dep, std::vector<int64_t>& dp, std::vector<int>& depth) {
    if(p != -1 && G[v].size() == 1) {
        dp[v] = 0;
        depth[v] = dep;
        return;
    }

    int min_depth = INF;
    int min_c = -1;
    for(int nei : G[v]) {
        if(nei != p) {
            dfs1(G, nei, v, dep + 1, dp, depth);
            if(depth[nei] < min_depth) {
                min_depth = depth[nei];
                min_c = nei;
            }
        }
    }

    if(v != 0) {
        dp[v] = q_pow((2 - dp[min_c] + MOD) % MOD, MOD - 2);
    }
    depth[v] = min_depth;
}

void dfs2(std::vector<std::vector<int>>& G, int v, int p, std::vector<int64_t>& dp, std::vector<int64_t>& ans) {
    if(v == 0) {
        ans[v] = 1;
    } else {
        ans[v] = ans[p] * dp[v] % MOD;
    }
    
    for(int nei : G[v]) {
        if(nei != p) {
            dfs2(G, nei, v, dp, ans);
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

    std::vector<int64_t> dp(N);
    std::vector<int> depth(N);
    std::vector<int64_t> ans(N);
    dfs1(G, 0, -1, 0, dp, depth);
    dfs2(G, 0, -1, dp, ans);

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
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
