#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

bool dfs(std::vector<std::vector<int>>& G, int v, int c, std::vector<int>& color) {
    color[v] = c;
    
    for(int nei : G[v]) {
        if(color[nei] == -1) {
            if(!dfs(G, nei, c ^ 1, color)) {
                return false;
            }
        } else if(color[nei] == c) {
            return false;
        }
    }
    return true;
}

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> G(N, std::vector<int>(N, 0));
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U][V] = 1;
        G[V][U] = 1;
    }

    int ans = M;
    for(int i = 0; i < (1 << N); i++) {
        std::vector<std::vector<int>> g(G);
        int remove = 0;
        for(int v = 0; v < N; v++) {
            for(int u = v + 1; u < N; u++) {
                if(G[v][u]) {
                    int c1 = i & (1 << v) ? 1 : 0;
                    int c2 = i & (1 << u) ? 1 : 0;
                    if(c1 == c2) {
                        remove += 1;
                    }
                }
            }
        }
        ans = std::min(ans, remove);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
