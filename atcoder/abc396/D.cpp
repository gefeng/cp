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

constexpr int64_t INF = int64_t(2e18);

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<std::pair<int, int64_t>>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        int64_t W;
        std::cin >> U >> V >> W;
        U -= 1;
        V -= 1;
        G[U].emplace_back(V, W);
        G[V].emplace_back(U, W);
    }

    std::queue<std::tuple<int, int, int64_t>> q;
    q.emplace(0, 1, 0);

    int64_t ans = INF;
    while(!q.empty()) {
        auto [v, s, c] = q.front();
        q.pop();
        
        if(v == N - 1) {
            ans = std::min(ans, c);
            continue;
        }

        for(auto [nei, w] : G[v]) {
            if(s & (1 << nei)) {
                continue;
            }
            q.emplace(nei, s | (1 << nei), c ^ w);
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
