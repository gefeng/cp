#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <ranges>

constexpr int64_t INF = static_cast<int64_t>(2e18);

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> G(N);
    std::vector<std::vector<int>> R(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        R[V].push_back(U);
    }

    std::vector<int> cnt(N, 0);
    for(int v = 0; v < N; v++) {
        cnt[v] = G[v].size();
    }
    
    std::vector<int64_t> dist(N, INF); 
    std::priority_queue<std::pair<int64_t, int>, std::vector<std::pair<int64_t, int>>, std::greater<std::pair<int64_t, int>>> pq;
        
    dist[N - 1] = 0;
    cnt[N - 1] -= 1;
    pq.emplace(0, N - 1);

    while(!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        
        if(dist[v] != d) {
            continue;
        }

        if(v == 0) {
            break;
        }

        for(int u : R[v]) {
            int64_t nd = d + cnt[u];
            cnt[u] -= 1;
            if(dist[u] > nd) {
                dist[u] = nd;
                pq.emplace(nd, u);
            }
        }
    }

    std::cout << dist[0] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
