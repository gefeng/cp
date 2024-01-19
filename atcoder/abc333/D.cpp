#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void dfs(std::vector<std::vector<int>>& G, int v, int p, std::vector<int>& size) {
    size[v] += 1;
    for(int nei : G[v]) {
        if(nei != p) {
            dfs(G, nei, v, size);
            size[v] += size[nei];
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
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    std::vector<int> size(N, 0);
    dfs(G, 0, -1, size);

    int max_v = 0;
    for(int nei : G[0]) {
        max_v = std::max(max_v, size[nei]); 
    }

    std::cout << N - max_v << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
