#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <tuple>

constexpr int INF = static_cast<int>(2e9);

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<std::vector<std::pair<int, int>>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].emplace_back(V, i);
        G[V].emplace_back(U, i + N - 1);
    }

    std::vector<std::vector<int>> vis(N << 1, std::vector<int>(K, 0));
    std::vector<std::vector<int>> cnt(N, std::vector<int>(K, 0));
    std::vector<int> dist(N, INF);
    std::queue<std::tuple<int, int, int>> q;
    q.emplace(0, -1, 0);

    int d = 0;
    int c = 0;
    while(!q.empty()) {
        int size = q.size();
        if(++c == K) {
            d += 1;
            c = 0;
        }
        while(size--) {
            auto [v, p, k] = q.front();
            q.pop();
            
            int n_k = (k + 1) % K;
            for(auto [nei, e] : G[v]) {
                if((nei != p || k == 0) && !vis[e][n_k] && ++cnt[nei][n_k] <= 2) {
                    q.emplace(nei, v, n_k);
                    vis[e][n_k] = 1;
                    if(n_k == 0) {
                        dist[nei] = std::min(dist[nei], d);
                    }
                }
            }
        }
    }

    for(int i = 1; i < N; i++) {
        std::cout << (dist[i] == INF ? -1 : dist[i]) << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
