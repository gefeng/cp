#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int INF = (int)2e9;

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<std::pair<int, int>>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V, W;
        std::cin >> U >> V >> W;
        U -= 1;
        V -= 1;
        G[U].emplace_back(V, W);
    }

    std::vector<std::vector<int>> dist(N, std::vector<int>(N, INF));
    for(int i = 0; i < N; i++) {
        dist[i][i] = 0;
        for(auto [j, w] : G[i]) {
            dist[i][j] = w;
        }
    }

    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]); 
                }
            }
        }
    }

    std::vector<std::vector<int>> dp(1 << N, std::vector<int>(N, INF)); 
    for(int i = 0; i < N; i++) {
        dp[1 << i][i] = 0;
    }

    for(int m = 0; m < (1 << N); m++) {
        for(int i = 0; i < N; i++) {
            if(dp[m][i] != INF) {
                for(int j = 0; j < N; j++) {
                    if(!(m & (1 << j)) && dist[i][j] != INF) {
                        int nm = m | (1 << j);
                        dp[nm][j] = std::min(dp[nm][j], dp[m][i] + dist[i][j]);
                    }
                }
            }
        } 
    }

    int ans = INF;
    for(int i = 0; i < N; i++) {
        ans = std::min(ans, dp[(1 << N) - 1][i]);
    }


    if(ans == INF) {
        std::cout << "No" << '\n';
    } else {
        std::cout << ans << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
