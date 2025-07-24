#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = static_cast<int>(2e9);

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> G(N + 1);
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    int max_t = N * 3;
    int min_t = INF;
    int min_w = INF;
    std::vector<int> dp(N, INF);
    dp[0] = 0;

    for(int i = 0; i <= max_t; i++) {
        std::vector<int> n_dp(N, INF);

        for(int v = 0; v < N; v++) {
            if(dp[v] == INF) {
                continue;
            }

            int size = G[v].size();
            int u = G[v][i % size];
            n_dp[v] = std::min(n_dp[v], dp[v] + 1);
            n_dp[u] = std::min(n_dp[u], dp[v]);
        } 

        dp = std::move(n_dp);
        
        if(dp[N - 1] != INF) {
            min_t = i + 1;
            min_w = dp[N - 1];
            break;
        }
    }

    std::cout << min_t << ' ' << min_w << '\n';
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
