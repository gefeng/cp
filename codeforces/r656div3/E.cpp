#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <tuple>
#include <queue>

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<std::vector<int>> G(N);
    std::vector<std::tuple<int, int, int>> E(M);
    std::vector<int> degree(N, 0);

    for(int i = 0; i < M; i++) {
        auto& [u, v, t] = E[i];
        std::cin >> t >> u >> v;
        u -= 1;
        v -= 1;
        if(t == 1) {
            G[u].push_back(v);
            degree[v] += 1;
        }
    }

    std::vector<int> topo;
    std::queue<int> q;

    for(int i = 0; i < N; i++) {
        if(degree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        
        topo.push_back(v);
        
        for(int nei : G[v]) {
            if(--degree[nei] == 0) {
                q.push(nei);
            }
        }
    }

    if(topo.size() != N) {
        std::cout << "NO" << '\n';
        return;
    }

    std::vector<int> pos(N, 0);
    for(int i = 0; i < N; i++) {
        pos[topo[i]] = i;
    }

    std::cout << "YES" << '\n';
    for(auto [u, v, t] : E) {
        if(t == 0) {
            if(pos[u] < pos[v]) {
                std::cout << u + 1 << ' ' << v + 1 << '\n';
            } else {
                std::cout << v + 1 << ' ' << u + 1 << '\n';
            }
        } else {
            std::cout << u + 1 << ' ' << v + 1 << '\n';
        }
    }
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
