#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void dfs(std::vector<std::vector<int>>& G, int v, int p, int& cnt_leaf) {
    if(G[v].size() == 1) {
        cnt_leaf += 1;
    }

    for(int nei : G[v]) {
        if(nei != p) {
            dfs(G, nei, v, cnt_leaf);
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

    if(N == 2) {
        std::cout << 0 << '\n';
        return;
    }

    int cnt_leaf = 0;
    dfs(G, 0, -1, cnt_leaf);

    int ans = cnt_leaf;
    for(int i = 0; i < N; i++) {
        int cnt = cnt_leaf;
        for(int nei : G[i]) {
            if(G[nei].size() == 1) {
                cnt -= 1;
            }
        }
        ans = std::min(ans, cnt);
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
