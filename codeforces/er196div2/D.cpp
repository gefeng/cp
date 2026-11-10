#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void dfs(std::vector<std::vector<int>>& G, int v, int p, int c, std::vector<int>& color) {
    color[v] = c;
    
    for(int u : G[v]) {
        if(u != p) {
            dfs(G, u, v, c, color);
        }
    }
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;

        U--;
        V--;
        
        G[U].push_back(V);
        G[V].push_back(U);
    }

    if(N % 2 == 0) {
        std::cout << N + 1 << '\n';
        return;
    }

    for(int t = N; t <= N + 2; t++) {
        int root = t == N ? N - 1 : (t == N + 1 ? N / 2 : 0);

        std::vector<int> color(N, 0);
        int c = 0;
        for(int u : G[root]) {
            dfs(G, u, root, c++, color);
        }

        for(int i = 1; i <= N; i++) {
            int u = i - 1;
            int v = t - i - 1;
            if(u != v && u >= 0 && u < N && v >= 0 && v < N) {
                if(color[u] != color[v]) {
                    std::cout << t << '\n';
                    return;
                }
            }
        }
    }

    std::cout << N << '\n';
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
