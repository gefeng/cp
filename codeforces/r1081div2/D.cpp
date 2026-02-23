#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void dfs(std::vector<std::vector<int>>& G, std::vector<int>& A, int v, int p, std::vector<int64_t>& ds, std::vector<int64_t>& depth, std::vector<std::vector<int64_t>>& dp) {
    ds[v] += A[v]; 

    int64_t max1 = 0;
    int64_t max2 = 0;
    for(int u : G[v]) {
        if(u != p) {
            dfs(G, A, u, v, ds, depth, dp);
            ds[v] += ds[u];
            int64_t d = depth[u];
            if(d > max1) {
                max2 = max1;
                max1 = d;
            } else if(d > max2) {
                max2 = d;
            }
        }
    }
    
    if(max2 == 0) {
        for(int u : G[v]) {
            if(u != p) {
                dp[0][v] = dp[0][u] + ds[u];
                dp[1][v] = std::max(dp[0][u], dp[1][u]) + ds[u];
            }
        }
    } else {
        int64_t max_d = 0;
        for(int u : G[v]) {
            if(u != p) {
                dp[0][v] += dp[0][u] + ds[u];
                max_d = std::max(max_d, dp[1][u] - dp[0][u]);
            }
        }
        dp[1][v] = dp[0][v] + max_d; 

        for(int u : G[v]) {
            if(u != p) {
                int64_t d = depth[u] == max1 ? max2 : max1;
                int64_t s = dp[0][v] - dp[0][u] - ds[u] + dp[0][u] + ds[u] * (d + 1);
                dp[1][v] = std::max(dp[1][v], s);
            }
        } 
    }

    depth[v] = max1 + 1;
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    std::vector<int64_t> ds(N, 0);
    std::vector<int64_t> depth(N, 0);
    std::vector<std::vector<int64_t>> dp(2, std::vector<int64_t>(N, 0));
    dfs(G, A, 0, -1, ds, depth, dp);

    for(int i = 0; i < N; i++) {
        std::cout << std::max(dp[0][i], dp[1][i]) << " \n"[i == N - 1];
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
