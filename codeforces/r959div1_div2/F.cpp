#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void dfs1(std::vector<std::vector<int>>& G, std::vector<std::array<int, 3>>& E, std::vector<int>& degree, std::vector<int>& vis, int v) {
    vis[v] = 1;
    
    for(int i : G[v]) {
        int to = v ^ E[i][0] ^ E[i][1];
        if(vis[to] || E[i][2] == 1) {
            continue;
        }
        
        dfs1(G, E, degree, vis, to);
        if(degree[to] & 1) {
            degree[to] ^= 1;
            degree[v] ^= 1;
            E[i][2] = 1;
        }
    }
}

void dfs2(std::vector<std::vector<int>>& G, std::vector<std::array<int, 3>>& E, int v, std::vector<int>& ans) {
    while(!G[v].empty()) {
        int i = G[v].back();
        G[v].pop_back();
        if(E[i][2] == 1) {
            E[i][2] = 0;
            dfs2(G, E, E[i][0] ^ E[i][1] ^ v, ans);
        }
    }
    ans.push_back(v);
}

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> G(N);
    std::vector<std::array<int, 3>> E(M);
    std::vector<int> degree(N, 0);
    for(int i = 0; i < M; i++) {
        int U, V, W;
        std::cin >> U >> V >> W;
        U -= 1;
        V -= 1;
        E[i] = {U, V, W};

        degree[U] ^= W;
        degree[V] ^= W;

        G[U].push_back(i);
        G[V].push_back(i);
    }
    
    std::vector<int> vis(N, 0);
    for(int i = 0; i < N; i++) {
        if(vis[i]) {
            continue;
        } 

        dfs1(G, E, degree, vis, i);
        
        if(degree[i] & 1) {
            std::cout << "No" << '\n';
            return;
        }
    } 

    std::vector<int> ans;
    dfs2(G, E, 0, ans);

    std::cout << "Yes" << '\n';
    int size = ans.size();
    std::cout << size - 1 << '\n';
    for(int i = 0; i < size; i++) {
        std::cout << ans[i] + 1 << " \n"[i == size - 1];
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
