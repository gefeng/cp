#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int64_t INF = (int64_t)2e18;

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
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

    auto cmp = [](const auto& a, const auto& b) {
        return a.first > b.first;
    };

    std::priority_queue<std::pair<int64_t, int>, std::vector<std::pair<int64_t, int>>, decltype(cmp)> pq(cmp);
    std::vector<int64_t> best(N, INF);

    best[0] = A[0];
    pq.emplace(A[0], 0);
    
    while(!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();

        if(d != best[v]) {
            continue;
        }
        
        for(auto [nei, w] : G[v]) {
            int64_t nd = w + A[nei] + d;
            if(best[nei] > nd) {
                best[nei] = nd;
                pq.emplace(nd, nei);
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
