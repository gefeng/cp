#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = int64_t(2e18);

void dfs(std::vector<std::vector<std::pair<int, int>>>& G, int v, int64_t x, std::vector<int64_t>& ans) {
    ans[v] = x;
    
    for(auto [nei, w] : G[v]) {
        if(ans[nei] == INF) {
            dfs(G, nei, x + w, ans);
        }
    }
}

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<std::pair<int, int>>> G(N);
    std::vector<std::vector<std::pair<int, int>>> RG(N);
    for(int i = 0; i < M; i++) {
        int U, V, W;
        std::cin >> U >> V >> W;
        U -= 1;
        V -= 1;
        G[U].emplace_back(V, W);
        G[V].emplace_back(U, -W);
    }

    std::vector<int64_t> ans(N, INF);
    for(int i = 0; i < N; i++) {
        if(ans[i] == INF) {
            dfs(G, i, 0, ans);
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
