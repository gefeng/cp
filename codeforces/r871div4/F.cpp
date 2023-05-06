#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

bool dfs(std::vector<std::vector<int>>& G, std::vector<bool>& vis, int v, int d) {
    if(d > 2) {
        return false;
    } 

    vis[v] = true;

    for(int nei : G[v]) {
        if(!vis[nei]) {
            if(!dfs(G, vis, nei, d + 1)) {
                return false;
            }
        }
    }

    return true;
}

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> G(N);
    std::vector<int> degree(N, 0);
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
        degree[U] += 1;
        degree[V] += 1;
    }

    int ans_x = 0;
    int ans_y = 0;
    for(int i = 0; i < N; i++) {
        std::vector<bool> vis(N, false);
        if(dfs(G, vis, i, 0)) {
            ans_x = degree[i]; 
            ans_y = degree[G[i][0]] - 1;
            break;
        }
    }

    std::cout << ans_x << ' ' << ans_y << '\n';
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
