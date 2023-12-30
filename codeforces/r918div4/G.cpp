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
constexpr int MAX = 1000;

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

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    auto cmp = [](const auto& a, const auto& b) {
        return a[2] > b[2];
    };

    std::priority_queue<std::array<int64_t, 3>, std::vector<std::array<int64_t, 3>>, decltype(cmp)> pq(cmp);
    std::vector<std::vector<int64_t>> best(N, std::vector<int64_t>(MAX + 1, INF));

    pq.push({0, A[0], 0});
    best[0][A[0]] = 0;
    while(!pq.empty()) {
        std::array<int64_t, 3> cur = pq.top();
        pq.pop();
        
        int v = cur[0];
        int s = cur[1];
        int64_t d = cur[2];
        
        if(d != best[v][s]) {
            continue;
        }

        for(auto [nv, w] : G[v]) {
            int64_t nd = d + ((int64_t)s * w);
            int ns = std::min(s, A[nv]);
            if(best[nv][ns] > nd) {
                best[nv][ns] = nd;
                pq.push({nv, ns, nd});
            }
        }
    }

    int64_t ans = INF;
    for(int i = 0; i <= MAX; i++) {
        ans = std::min(ans, best[N - 1][i]);
    }

    std::cout << ans << '\n';
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
