#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <queue>

constexpr int64_t INF = 1e18;

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<std::pair<int, int>>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V, D;
        std::cin >> U >> V >> D;
        U -= 1;
        V -= 1;
        G[U].emplace_back(V, D);
        G[V].emplace_back(U, -D);
    }

    std::vector<int64_t> pos(N, INF);
    for(int i = 0; i < N; i++) {
        if(pos[i] != INF) {
            continue;
        }

        std::queue<int> q;
        q.push(i);
        pos[i] = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int v = q.front();
                q.pop();
                for(std::pair<int, int> nei : G[v]) {
                    int u = nei.first;
                    int64_t d = nei.second;

                    if(pos[u] != INF && pos[u] - pos[v] != d) {
                        std::cout << "NO" << '\n';
                        return;
                    }

                    if(pos[u] == INF) {
                        pos[u] = pos[v] + d;
                        q.emplace(u);
                    }
                }
            }
        }
    }

    std::cout << "YES" << '\n';
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
