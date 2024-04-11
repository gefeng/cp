#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = (int64_t)2e18;

void dfs1(std::vector<std::vector<int>>& G, std::vector<int>& A, int v, int p, std::vector<int64_t>& dp1, std::vector<int64_t>& sum) {
    int64_t c = A[v];
    int64_t f = 0; 
    for(int nei : G[v]) {
        if(nei != p) {
            dfs1(G, A, nei, v, dp1, sum);
            f += dp1[nei] + sum[nei];
            c += sum[nei];
        }
    }

    dp1[v] = f;
    sum[v] = c;
}

void dfs2(std::vector<std::vector<int>>& G, std::vector<int>& A, int v, int p, std::vector<int64_t>& dp1, std::vector<int64_t>& sum, 
        std::vector<int64_t>& dp2) {
    dp2[v] = dp1[v];
    if(p != -1) {
        int64_t r = dp2[p] - (dp1[v] + sum[v]) + (sum[0] - sum[v]);
        dp2[v] += r; 
    }
    
    for(int nei : G[v]) {
        if(nei != p) {
            dfs2(G, A, nei, v, dp1, sum, dp2);
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

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> dp1(N, 0);
    std::vector<int64_t> dp2(N, 0);
    std::vector<int64_t> sum(N, 0);
    dfs1(G, A, 0, -1, dp1, sum);
    dfs2(G, A, 0, -1, dp1, sum, dp2);

    int64_t ans = INF;
    for(int i = 0; i < N; i++) {
        ans = std::min(ans, dp2[i]);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
