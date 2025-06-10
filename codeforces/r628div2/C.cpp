#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> E(N - 1);
    std::vector<std::vector<std::pair<int, int>>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].emplace_back(V, i);
        G[V].emplace_back(U, i);
    }

    std::vector<int> ans(N - 1, -1);
    int e = 0;
    for(int i = 0; i < N; i++) {
        if(G[i].size() > 2) {
            auto [u, x] = G[i][0];
            auto [v, y] = G[i][1];
            auto [w, z] = G[i][2];
            ans[x] = e++;
            ans[y] = e++;
            ans[z] = e++;
            break;
        }
    }

    for(int i = 0; i < N - 1; i++) {
        if(ans[i] == -1) {
            ans[i] = e++;
        }
        std::cout << ans[i] << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
