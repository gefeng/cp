#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = static_cast<int64_t>(1e9) + 7;

void dfs1(std::vector<std::vector<int>>& G, int v, int& time, std::vector<int>& dp) {
    int t_in = time;
    for(int u : G[v]) {
        time++;
        dfs1(G, u, time, dp);
    }

    dp[v] = time - t_in;
    time++;
}

void dfs2(std::vector<std::vector<int>>& G, int v, int p, std::vector<int>& dp, std::vector<int64_t>& ds) {
    if(v == 0) {
        ds[v] = 0;
    } else if(v == 1) {
        ds[v] = (dp[1] + 1) % MOD;
    } else {
        ds[v] = ((dp[v] + 1) % MOD) + ds[p];
        ds[v] %= MOD;
    }

    for(int u : G[v]) {
        dfs2(G, u, v, dp, ds);
    }
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> G(N + 1);
    G[0].push_back(1);
    for(int i = 1; i <= N; i++) {
        int L, R;
        std::cin >> L >> R;
        if(L) {
            G[i].push_back(L);
            G[i].push_back(R);
        }
    }

    int time = 0;
    std::vector<int> dp(N + 1, 0);
    dfs1(G, 0, time, dp);

    std::vector<int64_t> ds(N + 1, 0);
    dfs2(G, 0, -1, dp, ds);

    for(int i = 1; i <= N; i++) {
        std::cout << ds[i] << " \n"[i == N];
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
