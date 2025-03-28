#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void dfs(std::vector<std::vector<int>>& G, int s, int v, int p, int d, std::vector<std::vector<int>>& odd) {
    if(d % 2 == 1 && d != 1) {
        odd[s].push_back(v);
    }
    
    for(int nei : G[v]) {
        if(nei == p) {
            continue;
        }
        dfs(G, s, nei, v, d + 1, odd);
    }
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    std::vector<std::vector<int>> odd(N);
    for(int i = 0; i < N; i++) {
        dfs(G, i, i, -1, 0, odd);
    }

    std::vector<std::vector<int>> vis(N, std::vector<int>(N, 0));
    std::vector<std::pair<int, int>> edges;
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        for(int j : odd[i]) {
            if(vis[i][j]) {
                continue;
            }
            edges.emplace_back(i, j);
            vis[i][j] = 1;
            vis[j][i] = 1;
            cnt += 1;
        }
    }
    
    int t = 0;
    if(cnt % 2 == 1) {
        std::cout << "First" << std::endl;
        t = 1;
    } else {
        std::cout << "Second" << std::endl;
    }

    for(int i = 0; i < N; i++) {
        vis[i].assign(N, 0);
    }

    int p = 0;
    while(true) {
        if(t) {
            while(p < edges.size()) {
                auto [u, v] = edges[p];
                if(vis[u][v]) {
                    p += 1;
                    continue;
                }
                vis[u][v] = 1;
                vis[v][u] = 1;
                std::cout << u + 1 << ' ' << v + 1 << std::endl;
                p += 1;
                break;
            }
        } else {
            int U, V;
            std::cin >> U >> V;
            if(U == -1) {
                return;
            }
            U -= 1;
            V -= 1;
            vis[U][V] = 1;
            vis[V][U] = 1;
        }
        t ^= 1;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
