#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void dfs_1(std::vector<std::vector<int>>& G, int v, int par, int d, int& p) {
    p = std::max(p, d);
    
    for(int nei : G[v]) {
        if(nei != par) {
            dfs_1(G, nei, v, d + 1, p);
        }
    }
}

int dfs_2(int K, std::vector<std::vector<int>>& G, int v, int par, int p, int64_t& q) {
    int size = G[v].size() - (par == -1 ? 0 : 1);

    if(size) {
        q += K - size;
    }

    std::vector<int> dep;
    for(int nei : G[v]) {
        if(nei == par) {
            continue;
        }
        dep.push_back(dfs_2(K, G, nei, v, p, q));
    }

    if(dep.empty()) {
        return 1;
    }

    int max_d = *std::max_element(dep.begin(), dep.end());
    for(int d : dep) {
        q += d < max_d ? 1 : 0;
    }
    
    return max_d + 1;
}

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    if(N == 1) {
        std::cout << 0 << ' ' << 0 << '\n';
        return;
    }

    int p = 0;
    int64_t q = 0;
    dfs_1(G, 0, -1, 0, p);
    dfs_2(K, G, 0, -1, p, q);

    std::cout << p << ' ' << q << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
