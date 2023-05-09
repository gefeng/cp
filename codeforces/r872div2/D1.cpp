#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using LL = long long;

constexpr LL MOD = (LL)1e9 + 7LL;

LL q_pow(LL x, LL y) {
    LL res = 1LL;

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

void dfs1(std::vector<std::vector<int>>& G, int v, int p, std::vector<LL>& save_cnt) {
    LL cnt = 1LL;

    for(int nei : G[v]) {
        if(nei != p) {
            dfs1(G, nei, v, save_cnt);

            cnt += save_cnt[nei];
            cnt %= MOD;
        }
    }

    save_cnt[v] = cnt;
}

void dfs2(std::vector<std::vector<int>>& G, int v, int p, std::vector<LL>& save_cnt, std::vector<LL>& res) {
    LL n = G.size();
    LL inv_2 = q_pow(2LL, MOD - 2LL); 

    res[v] = (n * ((n - 1 + MOD) % MOD) % MOD) * inv_2 % MOD;

    for(int nei : G[v]) {
        if(nei != p) {
            LL sz = save_cnt[nei]; 
            res[v] -= (sz * ((sz - 1LL + MOD) % MOD) % MOD) * inv_2 % MOD;
            res[v] += MOD;
            res[v] %= MOD;
        }
    }

    if(p != -1) {
        LL sz = (n - save_cnt[v] + MOD) % MOD;
        res[v] -= (sz * ((sz - 1LL + MOD) % MOD) % MOD) * inv_2 % MOD;
        res[v] += MOD;
        res[v] %= MOD;
    }

    for(int nei : G[v]) {
        if(nei != p) {
            dfs2(G, nei, v, save_cnt, res);
        }
    }
}

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<std::vector<int>> G(N);

    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    LL ans = 0LL;
    if(K % 2 == 1) {
        ans = 1LL;
    } else {
        std::vector<LL> save_cnt(N, 0LL);
        std::vector<LL> res(N, 0LL); 

        dfs1(G, 0, -1, save_cnt); 
        dfs2(G, 0, -1, save_cnt, res);
        
        for(LL x : res) {
            ans += x;
            ans %= MOD;
        }

        LL sz = N;
        LL x = (sz * ((sz - 1LL + MOD) % MOD) % MOD) * q_pow(2LL, MOD - 2LL) % MOD;
        ans = ans * q_pow(x, MOD - 2LL) % MOD;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
