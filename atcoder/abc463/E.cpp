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
    int N, M, Y;
    std::cin >> N >> M >> Y;
    
    std::vector<std::vector<std::pair<int, int>>> G(N + 1);
    for(int i = 0; i < M; i++) {
        int U, V, W;
        std::cin >> U >> V >> W;

        U--;
        V--;
        G[U].emplace_back(V, W);
        G[V].emplace_back(U, W);
    }

    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        G[i].emplace_back(N, A[i] + Y);
        G[N].emplace_back(i, A[i]);
    }

    std::vector<int64_t> best(N + 1, INF);
    best[0] = 0;
    std::priority_queue<std::pair<int64_t, int>, std::vector<std::pair<int64_t, int>>, std::greater<std::pair<int64_t, int>>> pq;
    pq.emplace(0, 0);
    
    while(!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        
        if(d != best[v]) {
            continue;
        }

        for(auto [u, w] : G[v]) {
            int64_t nd = d + w;
            if(best[u] > nd) {
                pq.emplace(nd, u);
                best[u] = nd;
            }
        }
    }

    for(int i = 1; i < N; i++) {
        std::cout << best[i] << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
