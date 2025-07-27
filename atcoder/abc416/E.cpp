#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = static_cast<int64_t>(2e18);

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int64_t>> G(N + 1, std::vector<int64_t>(N + 1, INF));
    std::vector<std::vector<int64_t>> dist(N + 1, std::vector<int64_t>(N + 1, INF));
    for(int i = 0; i <= N; i++) {
        G[i][i] = 0;
        dist[i][i] = 0;
    }

    for(int i = 0; i < M; i++) {
        int U, V, W;
        std::cin >> U >> V >> W;
        U -= 1;
        V -= 1;
        G[U][V] = std::min(G[U][V], static_cast<int64_t>(W));
        G[V][U] = std::min(G[V][U], static_cast<int64_t>(W));
        dist[U][V] = std::min(dist[U][V], static_cast<int64_t>(W));
        dist[V][U] = std::min(dist[V][U], static_cast<int64_t>(W));
    }

    int K, T;
    std::cin >> K >> T;
    std::vector<int> has_airport(N, 0);
    for(int i = 0; i < K; i++) {
        int X;
        std::cin >> X;
        has_airport[X - 1] = 1;
    }
    
    for(int u = 0; u < N; u++) {
        if(!has_airport[u]) {
            continue;
        }
        G[u][N] = T;
        G[N][u] = 0;
        dist[u][N] = T;
        dist[N][u] = 0;
    }

    for(int k = 0; k <= N; k++) {
        for(int i = 0; i <= N; i++) {
            for(int j = 0; j <= N; j++) {
                if(i != j && dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    auto update = [&](int u, int v, int w) {
        dist[u][v] = std::min(dist[u][v], static_cast<int64_t>(w));
        for(int x = 0; x <= N; x++) {
            for(int y = 0; y <= N; y++) {
                if(x == y) {
                    continue;
                }
                if(dist[x][u] != INF && dist[v][y] != INF) {
                    dist[x][y] = std::min(dist[x][y], dist[x][u] + dist[v][y] + w);
                }
                if(dist[y][u] != INF && dist[v][x] != INF) {
                    dist[y][x] = std::min(dist[y][x], dist[y][u] + dist[v][x] + w);
                }
            }
        }
    };

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int C;
        std::cin >> C;
        if(C == 1) {
            int U, V, W;
            std::cin >> U >> V >> W;
            U -= 1;
            V -= 1;
            G[U][V] = std::min(G[U][V], static_cast<int64_t>(W));
            G[V][U] = std::min(G[V][U], static_cast<int64_t>(W));
            update(U, V, W);
            update(V, U, W);
        } else if(C == 2) {
            int X;
            std::cin >> X;
            X -= 1;
            
            if(has_airport[X]) {
                continue;
            }

            has_airport[X] = 1;
            G[X][N] = T;
            G[N][X] = 0;
            update(X, N, T);
            update(N, X, 0);
        } else {
            int64_t sum = 0;
            for(int x = 0; x < N; x++) {
                for(int y = 0; y < N; y++) {
                    sum += dist[x][y] == INF ? 0 : dist[x][y]; 
                }
            }
            std::cout << sum << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
