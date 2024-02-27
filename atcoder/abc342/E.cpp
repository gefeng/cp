#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int64_t INF = 2e18;

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<std::array<int, 5>>> G(N);
    for(int i = 0; i < M; i++) {
        int L, D, K, C, U, V;
        std::cin >> L >> D >> K >> C >> U >> V;
        U -= 1;
        V -= 1;
        
        G[V].push_back({U, L, D, K, C});
    }

    std::priority_queue<std::pair<int64_t, int>> pq;
    std::vector<int64_t> best(N, -INF);

    pq.emplace(0, N - 1);
    best[N - 1] = 0;

    while(!pq.empty()) {
        auto [t, v] = pq.top();
        pq.pop();

        if(best[v] != t) {
            continue;
        }

        for(auto& nei : G[v]) {
            int u = nei[0];
            int l = nei[1];
            int d = nei[2];
            int k = nei[3];
            int c = nei[4];

            int64_t nt = 0;
            if(v == N - 1) {
                nt = l + (int64_t)(k - 1) * d;
                if(best[u] < nt) {
                    best[u] = nt;
                    pq.emplace(nt, u);
                } 
            } else {
                if(l > t) {
                    continue;
                }

                int64_t x = std::min((int64_t)k, (t - l - c) / d + 1);
                int64_t nt = l + (x - 1) * d;
                if(best[u] < nt) {
                    best[u] = nt;
                    pq.emplace(nt, u);
                }
            }
        }
    }

    for(int i = 0; i < N - 1; i++) {
        if(best[i] == -INF) {
            std::cout << "Unreachable" << '\n';
        } else {
            std::cout << best[i] << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
