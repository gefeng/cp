#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

bool dfs(std::vector<std::vector<int>>& G, std::vector<std::string>& A, int W, int v, int d, std::vector<std::vector<int>>& vis) {
    vis[d][v] = 1;

    int nd = (d + 1) % W;
    
    if(A[v][nd] == 'o') {
        if(vis[nd][v] == 1) {
            return true;
        }
        if(vis[nd][v] == 0) {
            if(dfs(G, A, W, v, nd, vis)) {
                return true;
            }
        }
    }
    
    for(int u : G[v]) {
        if(A[u][nd] == 'o') {
            if(vis[nd][u] == 1) {
                return true;
            }
            if(vis[nd][u] == 0) {
                if(dfs(G, A, W, u, nd, vis)) {
                    return true;
                }
            }
        }
    }

    vis[d][v] = 2;

    return false;
}

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U--;
        V--;
        G[U].push_back(V);
        G[V].push_back(U);
    }
    
    int W;
    std::cin >> W;
    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> vis(W, std::vector<int>(N, 0));
    for(int v = 0; v < N; v++) {
        for(int d = 0; d < W; d++) {
            if(vis[d][v] == 0 && A[v][d] == 'o') {
                if(dfs(G, A, W, v, d, vis)) {
                    std::cout << "Yes" << '\n';
                    return;
                }
            }
        }
    }

    std::cout << "No" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
