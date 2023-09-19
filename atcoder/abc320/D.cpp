#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <set>

constexpr int64_t INF = (int64_t)1e18;

void dfs(std::vector<std::vector<std::vector<int>>>& G, int v, std::vector<std::pair<int64_t, int64_t>>& pos) {
    for(auto& nei : G[v]) {
        int nv = nei[0];
        int dx = nei[1];
        int dy = nei[2];
        if(pos[nv].first == INF) {
            pos[nv] = {pos[v].first + dx, pos[v].second + dy}; 
            dfs(G, nv, pos);
        }
    } 
}

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<std::vector<std::vector<int>>> G(N);
    for(int i = 0; i < M; i++) {
        int A, B, X, Y;
        std::cin >> A >> B >> X >> Y;
        A -= 1;
        B -= 1;
        G[A].push_back({B, X, Y});
        G[B].push_back({A, -X, -Y});
    }

    std::vector<std::pair<int64_t, int64_t>> pos(N, {INF, INF});

    pos[0] = {0, 0};

    dfs(G, 0, pos);

    for(int i = 0; i < N; i++) {
        if(pos[i].first != INF) {
            std::cout << pos[i].first << ' ' << pos[i].second << '\n'; 
        } else {
            std::cout << "undecidable" << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
