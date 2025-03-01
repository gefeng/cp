#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(998244353);

void dfs(std::vector<std::vector<int>>& G, int v, int d, std::vector<std::vector<int>>& lv) {
    if(d == lv.size()) {
        lv.emplace_back();
    }
    lv[d].push_back(v);
    
    for(int nei : G[v]) {
        dfs(G, nei, d + 1, lv);
    }
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> G(N);
    std::vector<int> parent(N, -1);
    for(int i = 0; i < N - 1; i++) {
        int P;
        std::cin >> P;
        P -= 1;
        parent[i + 1] = P;
        G[P].push_back(i + 1);
    }

    std::vector<std::vector<int>> lv;    
    dfs(G, 0, 0, lv);

    int n = lv.size();
    std::vector<int64_t> dp(N, 0);
    std::vector<int64_t> ds(n, 0);
    for(int i = n - 1; i >= 0; i--) {
        for(int v : lv[i]) {
            int64_t sum = 0;
            for(int nei : G[v]) {
                sum += dp[nei];
                sum %= MOD;
            }

            if(v == 0) {
                dp[v] = sum + 1;
                dp[v] %= MOD;
            } else {
                if(i + 1 < n) {
                    dp[v] += (ds[i + 1] - sum + MOD) % MOD;
                    dp[v] %= MOD;
                }
                dp[v] += 1;
                dp[v] %= MOD;
                ds[i] += dp[v];
                ds[i] %= MOD;
            }
        }
    }

    std::cout << dp[0] << '\n';
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
