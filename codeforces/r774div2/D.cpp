#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void dfs(std::vector<std::vector<int>>& G, int v, int p, std::vector<std::vector<int>>& dp, 
        std::vector<std::vector<int>>& ds, std::vector<int>& to) {
    if(G[v].size() == 1 && p != -1) {
        dp[0][v] = 0;
        dp[1][v] = 1;
        ds[0][v] = 1;
        ds[1][v] = 1;
        return;
    }

    for(int nei : G[v]) {
        if(nei == p) {
            continue;
        }

        dfs(G, nei, v, dp, ds, to);
        
        dp[1][v] += dp[0][nei];
        ds[1][v] += ds[0][nei];

        if(dp[0][nei] == dp[1][nei]) {
            dp[0][v] += dp[0][nei];
            ds[0][v] += std::min(ds[0][nei], ds[1][nei]);
            to[nei] = ds[0][nei] < ds[1][nei] ? 0 : 1;
        } else {
            dp[0][v] += dp[0][nei] > dp[1][nei] ? dp[0][nei] : dp[1][nei];
            ds[0][v] += dp[0][nei] > dp[1][nei] ? ds[0][nei] : ds[1][nei];
            to[nei] = dp[0][nei] > dp[1][nei] ? 0 : 1;
        }
    }

    ds[0][v] += 1;
    ds[1][v] += G[v].size();
    dp[1][v] += 1;
}

void build(std::vector<std::vector<int>>& G, std::vector<int>& to, int v, int p, int picked, std::vector<int>& ans) {
    ans[v] = picked ? G[v].size() : 1;
    
    for(int nei : G[v]) {
        if(nei == p) {
            continue;
        }
        if(picked) {
            build(G, to, nei, v, 0, ans);
        } else {
            build(G, to, nei, v, to[nei], ans);
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

    if(N == 2) {
        std::cout << 2 << ' ' << 2 << '\n' << 1 << ' ' << 1 << '\n';
        return;
    }

    std::vector<std::vector<int>> dp(2, std::vector<int>(N, 0));
    std::vector<std::vector<int>> ds(2, std::vector<int>(N, 0));
    std::vector<int> to(N, 0);
    std::vector<int> ans(N, 0);
    dfs(G, 0, -1, dp, ds, to);
    
    int max_cnt = std::max(dp[0][0], dp[1][0]);
    int min_sum = dp[0][0] == dp[1][0] ? std::min(ds[0][0], ds[1][0]) : (dp[0][0] > dp[1][0] ? ds[0][0] : ds[1][0]);
    if(dp[0][0] == dp[1][0]) {
        build(G, to, 0, -1, ds[0][0] < ds[1][0] ? 0 : 1, ans);
    } else {
        build(G, to, 0, -1, dp[0][0] > dp[1][0] ? 0 : 1, ans);
    }

    std::cout << max_cnt << ' ' << min_sum << '\n';
    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
