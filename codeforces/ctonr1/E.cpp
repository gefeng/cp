#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void bipart(std::vector<std::vector<int>>& G, std::vector<int>& color, int v, int c) {
    color[v] = c;
    
    for(int nei : G[v]) {
        if(color[nei] == -1) {
            bipart(G, color, nei, c ^ 1);
        }
    }
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> G(N);
    std::vector<int> degree(N, 0);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
        degree[U] += 1;
        degree[V] += 1;
    }

    std::vector<int> color(N, -1);
    bipart(G, color, 0, 0);

    for(int i = 0; i < N; i++) {
        int v = color[i] == 1 ? -degree[i] : degree[i];
        std::cout << v << " \n"[i == N - 1];
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
