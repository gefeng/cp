#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int64_t INF = int64_t(2e18);

void run_case() {
    int N, M, H;
    std::cin >> N >> M >> H;
    
    std::vector<int> A(N);
    for(int i = 0; i < H; i++) {
        int V;
        std::cin >> V;
        A[V - 1] = 1;
    }

    std::vector<std::vector<std::pair<int, int>>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V, W;
        std::cin >> U >> V >> W;
        U -= 1;
        V -= 1;
        G[U].emplace_back(V, W);
        G[V].emplace_back(U, W);
    }

    auto dijkstra = [&](int st) {
        auto cmp = [](const auto& a, const auto& b) {
            return a[0] > b[0];
        };

        std::vector<std::vector<int64_t>> best(N, std::vector<int64_t>(2, INF));
        std::priority_queue<std::array<int64_t, 3>, std::vector<std::array<int64_t, 3>>, decltype(cmp)> pq(cmp);

        best[st][0] = 0;
        pq.push({0, 0, st});
        while(!pq.empty()) {
            std::array<int64_t, 3> now = pq.top();
            pq.pop();
            int64_t t = now[0];
            int mounted = now[1];
            int v = now[2];

            if(t != best[v][mounted]) {
                continue;
            }

            for(auto [nv, w] : G[v]) {
                if(!mounted) {
                    if(A[v]) {
                        int64_t nt = t + w / 2;
                        if(nt < best[nv][1]) {
                            best[nv][1] = nt;
                            pq.push({nt, 1, nv});
                        }
                    } 
                    int64_t nt = t + w;
                    if(nt < best[nv][0]) {
                        best[nv][0] = nt;
                        pq.push({nt, 0, nv});
                    }
                } else {
                    int64_t nt = t + w / 2;
                    if(nt < best[nv][1]) {
                        best[nv][1] = nt;
                        pq.push({nt, 1, nv});
                    } 
                }
            }
        }

        std::vector<int64_t> res(N, INF);
        for(int i = 0; i < N; i++) {
            res[i] = std::min(best[i][0], best[i][1]);
        }
        return res;
    };

    std::vector<int64_t> marian = dijkstra(0);
    std::vector<int64_t> robin = dijkstra(N - 1);

    int64_t ans = INF;
    for(int i = 0; i < N; i++) {
        ans = std::min(ans, std::max(marian[i], robin[i])); 
    }

    std::cout << (ans == INF ? -1 : ans) << '\n';
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
