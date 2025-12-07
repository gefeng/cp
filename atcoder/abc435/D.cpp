#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void dfs(std::vector<std::vector<int>>& R, int v, std::vector<int>& vis) {
    if(vis[v]) {
        return;
    }

    vis[v] = 1;
    for(int nei : R[v]) {
        if(!vis[nei]) {
            dfs(R, nei, vis);
        }
    }
}

void run_case() {
    int N, M, Q;
    std::cin >> N >> M;

    std::vector<std::vector<int>> R(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        R[V].push_back(U);
    } 

    std::vector<int> vis(N, 0);
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int T, V;
        std::cin >> T >> V;

        V -= 1;
        if(T == 1) {
            dfs(R, V, vis);
        } else {
            std::cout << (vis[V] ? "Yes" : "No") << '\n';
        }
    } 
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
