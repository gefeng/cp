#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = int(2e9);

void dfs_1(std::vector<std::vector<int>>& G, std::vector<int>& A, int v, int p, std::vector<int>& dp_1) {
    int res = A[v] == 0 ? -1 : 1;
    for(int nei : G[v]) {
        if(nei == p) {
            continue;
        }
        dfs_1(G, A, nei, v, dp_1);
        if(dp_1[nei] > 0) {
            res += dp_1[nei];
        }
    }     
    dp_1[v] = res;
}

void dfs_2(std::vector<std::vector<int>>& G, std::vector<int>& A, int v, int p, std::vector<int>& dp_1, std::vector<int>& dp_2) {
    dp_2[v] = dp_1[v];
    if(p != -1) {
        int x = dp_1[v];
        int y = dp_2[p];
        if(x > 0) {
            y -= x;
        }
        dp_2[v] = std::max(dp_2[v], dp_1[v] + y);
    }

    for(int nei : G[v]) {
        if(nei == p) {
            continue;
        }
        dfs_2(G, A, nei, v, dp_1, dp_2);
    }
}

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    std::vector<int> dp_1(N, -INF);
    std::vector<int> dp_2(N, -INF);

    dfs_1(G, A, 0, -1, dp_1);
    dfs_2(G, A, 0, -1, dp_1, dp_2);
    
    for(int i = 0; i < N; i++) {
        std::cout << dp_2[i] << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
