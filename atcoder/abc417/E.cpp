#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

bool dfs_2(std::vector<std::vector<int>>& G, int Y, std::vector<int>& banned, int v, std::vector<int>& vis) {
    vis[v] = 1;
    if(v == Y) {
        return true;
    }

    for(int nei : G[v]) {
        if(!vis[nei] && !banned[nei]) {
            if(dfs_2(G, Y, banned, nei, vis)) {
                return true;
            }
        }
    }

    return false;
}

void dfs_1(int N, std::vector<std::vector<int>>& G, int Y, int v, std::vector<int>& vis, std::vector<int>& path) {
    vis[v] = 1;
    path.push_back(v);
    if(v == Y) {
        return;
    }
    
    for(int nei : G[v]) {
        if(!vis[nei]) {
            std::vector<int> seen(N, 0);
            if(dfs_2(G, Y, vis, nei, seen)) {
                dfs_1(N, G, Y, nei, vis, path);
                return;
            }
            vis[nei] = 1;
        }
    }
}

void run_case() {
    int N, M, X, Y;
    std::cin >> N >> M >> X >> Y;
    X -= 1;
    Y -= 1;

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    for(int i = 0; i < N; i++) {
        std::ranges::sort(G[i]);
    }

    std::vector<int> path;
    std::vector<int> vis(N, 0);
    dfs_1(N, G, Y, X, vis, path);

    int size = path.size();
    for(int i = 0; i < size; i++) {
        std::cout << path[i] + 1 << " \n"[i == size - 1];
    }
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
