#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

constexpr LL MOD = (LL)1e9 + 7LL;

std::vector<LL> fact;
std::vector<LL> invf;
std::vector<LL> dp;
std::vector<int> save_sz;
std::vector<LL> ans;

LL q_pow(LL x, LL y) {
    LL res = 1LL;

    while(y) {
        if(y & 1LL) {
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        y >>= 1;
    }

    return res;
}

int dfs1(std::vector<std::vector<int>>& G, int v, int p) {
    LL res = 1LL;
    int tot = 0;
    for(int nei : G[v]) {
        if(nei != p) {
            int sz = dfs1(G, nei, v);
            tot += sz;
            res *= invf[sz];     
            res %= MOD;

            res *= dp[nei];
            res %= MOD;
        }
    }

    res *= fact[tot];
    res %= MOD;

    dp[v] = res;
    save_sz[v] = tot + 1;

    return tot + 1;
}

void dfs2(std::vector<std::vector<int>>& G, int v, int p) {
    if(p == -1) {
        ans[v] = dp[0];
    } else {
        LL res = 1LL;
        LL res_p = ans[p]; 
        LL tot_size = save_sz[0];
        LL size = save_sz[v];
        
        LL x = res_p * q_pow(dp[v], MOD - 2LL) % MOD;
        x *= fact[size]; 
        x %= MOD;
        x *= invf[tot_size - 1];
        x %= MOD;
        x *= fact[tot_size - size - 1];
        x %= MOD;

        res = dp[v] * x % MOD;
        res *= invf[tot_size - size];
        res %= MOD;
        res *= invf[size - 1];
        res %= MOD;
        res *= fact[tot_size - 1];
        res %= MOD;
        
        ans[v] = res;
    }

    for(int nei : G[v]) {
        if(nei != p) {
            dfs2(G, nei, v);
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

    fact.resize(N + 1, 1LL);
    invf.resize(N + 1, 1LL);
    dp.resize(N, 0LL);
    save_sz.resize(N, 0LL); 
    ans.resize(N, 0);
    
    for(int i = 2; i <= N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    for(int i = 2; i <= N; i++) {
        invf[i] = q_pow(fact[i], MOD - 2LL);
    }

    std::vector<int> dp(N, 0);
    dfs1(G, 0, -1);

    dfs2(G, 0, -1);
    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
