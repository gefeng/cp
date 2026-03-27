#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

bool dfs(std::vector<std::vector<int>>& G, int v, int c, std::vector<int>& color, int& cnt0, int& cnt1) {
    color[v] = c;
    if(c == 0) {
        cnt0 += 1;
    } else {
        cnt1 += 1;
    }

    bool bipartite = true;
    for(int u : G[v]) {
        if(color[u] == -1) {
            if(!dfs(G, u, c ^ 1, color, cnt0, cnt1)) {
                bipartite = false;
            }
        } else {
            if(color[u] == c) {
                bipartite = false;
            }
        }
    }

    return bipartite;
}

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    int ans = 0;
    std::vector<int> color(N, -1);
    for(int v = 0; v < N; v++) {
        if(color[v] != -1) {
            continue;
        }

        int cnt0 = 0;
        int cnt1 = 0;
        if(dfs(G, v, 0, color, cnt0, cnt1)) {
            ans += std::max(cnt0, cnt1);
        }
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
