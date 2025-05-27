#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = int64_t(4e18);

void dfs(std::vector<std::vector<int>>& G, std::vector<int>& A, int v, int p, int64_t min_v, int64_t max_v, std::vector<int64_t>& ans) {
    int64_t nxt_max = std::max(int64_t(A[v]), A[v] - min_v);
    int64_t nxt_min = std::min(int64_t(A[v]), A[v] - max_v);
    ans[v] = nxt_max;
    for(int nei : G[v]) {
        if(nei != p) {
            dfs(G, A, nei, v, nxt_min, nxt_max, ans);
        }
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

    std::vector<int64_t> ans(N, 0);
    dfs(G, A, 0, -1, 0, 0, ans);
    
    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
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
