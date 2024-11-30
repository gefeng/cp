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
    int N, M;
    std::cin >> N >> M;
    
    std::vector<std::vector<std::pair<int, int>>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V, W;
        std::cin >> U >> V >> W;
        U -= 1;
        V -= 1;
        G[U].emplace_back(V, W);
        G[V].emplace_back(U, W);
    }

    auto cmp = [](const auto& a, const auto& b) {
        return a[0] > b[0];
    };
    
    std::vector<std::vector<int64_t>> best(4, std::vector<int64_t>(N, INF));
    std::priority_queue<std::array<int64_t, 3>, std::vector<std::array<int64_t, 3>>, decltype(cmp)> pq(cmp);
    best[0][0] = 0;
    pq.push({0, 0, 0});
    
    while(!pq.empty()) {
        auto now = pq.top();
        pq.pop();
        
        int64_t d = now[0];
        int s = now[1];
        int v = now[2];

        if(d != best[s][v]) {
            continue;
        }
        
        for(auto& [nei, w] : G[v]) {
            int64_t nd = d + w;
            
            if(best[s][nei] > nd) {
                best[s][nei] = nd;
                pq.push({nd, s, nei});
            }
            if(s == 0) {
                if(best[1][nei] > nd + w) {
                    best[1][nei] = nd + w;
                    pq.push({nd + w, 1, nei});
                }
                if(best[2][nei] > nd - w) {
                    best[2][nei] = nd - w;
                    pq.push({nd - w, 2, nei});
                }
                if(best[3][nei] > nd) {
                    best[3][nei] = nd;
                    pq.push({nd, 3, nei});
                }
            } else if(s == 1) {
                if(best[3][nei] > nd - w) {
                    best[3][nei] = nd - w;
                    pq.push({nd - w, 3, nei});
                }
            } else if(s == 2) {
                if(best[3][nei] > nd + w) {
                    best[3][nei] = nd + w;
                    pq.push({nd + w, 3, nei});
                }
            }
        }
    }

    for(int i = 1; i < N; i++) {
        std::cout << best[3][i] << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
