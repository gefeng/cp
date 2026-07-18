#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int MAX = static_cast<int>(2e5);

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::tuple<int, int, int>> E(M);
    for(int i = 0; i < M; i++) {
        int O, U, V;
        std::cin >> O >> U >> V;
        U--;
        V--;
        O--;
        E[i] = {O, U, V};
    }

    std::vector<std::vector<std::pair<int, int>>> g(N);
    std::vector<std::vector<int>> degree(2, std::vector<int>(N, 0));
    for(auto [o, u, v] : E) {
        g[u].emplace_back(v, o);
        g[v].emplace_back(u, o);
        degree[o][v]++;
        degree[o][u]++;
    }

    std::queue<std::pair<int, int>> q;
    std::vector<int> ans(N, 0);
    std::vector<std::vector<int>> vis(2, std::vector<int>(N, 0));
    for(int i = 0; i < N; i++) {
        if(degree[0][i] == 0 || degree[1][i] == 0) {
            if(degree[0][i] == 0) {
                q.emplace(i, 1);
                vis[1][i] = 1;
            } else {
                q.emplace(i, 0);
                vis[0][i] = 1;
            }
        }
    }

    int now = MAX;
    while(!q.empty()) {
        auto [v, k] = q.front();
        q.pop();

        if(ans[v] == 0) {
            ans[v] = k == 0 ? now : -now;
        } else {
            if(degree[0][v] == 0 && degree[1][v] == 0) {
                continue;
            }
            if((k == 0 && ans[v] < 0) || (k == 1 && ans[v] > 0)) {
                std::cout << "NO" << '\n';
                return;
            }
        }
        now--;
        
        for(auto [u, o] : g[v]) {
            if(--degree[o][u] == 0) {
                if(!vis[o ^ 1][u]) {
                    vis[o ^ 1][u] = 1;
                    q.emplace(u, o ^ 1);
                }
            }
        }
    }

    for(int i = 0; i < N; i++) {
        if(ans[i] == 0) {
            std::cout << "NO" << '\n';
            return;
        }
    }

    std::cout << "YES" << '\n';
    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
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
