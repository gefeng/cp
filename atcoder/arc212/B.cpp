#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int64_t INF = static_cast<int64_t>(2e18);

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<std::pair<int, int>>> G(N);
    int st = 0;
    for(int i = 0; i < M; i++) {
        int U, V, W;
        std::cin >> U >> V >> W;
        U -= 1;
        V -= 1;
        if(i == 0) {
            st = U;
        }
        if((i && U != st) || i == 0) {
            G[U].emplace_back(V, W);
        }
    }

    std::priority_queue<std::pair<int64_t, int>, std::vector<std::pair<int64_t, int>>, std::greater<std::pair<int64_t, int>>> pq;
    std::vector<int64_t> best(N, INF);
    int64_t ans = INF;

    best[st] = 0;
    pq.emplace(0, st);

    while(!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();

        if(best[v] != d) {
            continue;
        }

        for(auto [u, w] : G[v]) {
            if(u == st) {
                ans = std::min(ans, d + w);
                continue;
            }            
            if(best[u] > d + w) {
                best[u] = d + w;
                pq.emplace(d + w, u);
            }
        }
    }

    std::cout << (ans == INF ? -1 : ans) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
