#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void dfs(std::vector<std::vector<std::pair<int, int>>>& G, int v, int p, int pe, std::vector<int>& color) {
    if(p == -1) {
        int c = 1;
        for(auto [nei, e] : G[v]) {
            color[e] = c++;
        }
    } else {
        int c = 1;
        for(auto [nei, e] : G[v]) {
            if(nei != p) {
                if(c == color[pe]) {
                    c += 1;
                }
                color[e] = c++;
            }
        }
    }

    for(auto [nei, e] : G[v]) {
        if(nei != p) {
            dfs(G, nei, v, e, color);
        }
    }
}

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<std::vector<std::pair<int, int>>> G(N);
    std::vector<std::pair<int, int>> E(N - 1);
    std::vector<int> degree(N, 0);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].emplace_back(V, i);
        G[V].emplace_back(U, i);
        E[i] = {U, V};
        degree[U] += 1;
        degree[V] += 1;
    }

    int k = 0;
    for(int i = 0; i < N; i++) {
        k = std::max(k, degree[i]);
    }

    std::vector<int> color(N - 1, 0);
    dfs(G, 0, -1, -1, color);

    std::cout << k << '\n';
    for(int c = 1; c <= k; c++) {
        std::vector<int> paint(N, 0);
        int j = 1;
        for(int e = 0; e < N - 1; e++) {
            if(color[e] == c) {
                paint[E[e].first] = j;
                paint[E[e].second] = j;
                j += 1;
            }
        }
        
        for(int i = 0; i < N; i++) {
            if(paint[i] == 0) {
                paint[i] = j++;
            }
        }

        for(int i = 0; i < N; i++) {
            std::cout << paint[i] << " \n"[i == N - 1];
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
