#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = int64_t(2e18);

void dfs(int C, std::vector<std::vector<int>>& G, std::vector<int>& A, int v, int p, std::vector<std::vector<int64_t>>& dp) {
    if(p != -1 && G[v].size() == 1) {
        dp[v][0] = 0;
        dp[v][1] = A[v];
        return;
    }

    std::vector<std::pair<int64_t, int64_t>> a;
    for(int nei : G[v]) {
        if(nei != p) {
            dfs(C, G, A, nei, v, dp);
            a.emplace_back(dp[nei][0], dp[nei][1]);
        }
    }

    int n = a.size();
    for(int i = 0; i < n; i++) {
        dp[v][0] += std::max(a[i].first, a[i].second);
    }

    std::vector<int64_t> best(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        best[i] = best[i - 1] + std::max(a[i - 1].first, a[i - 1].second - C * 2);
    }

    dp[v][1] = best[n] + A[v];
}

void run_case() {
    int N, C;
    std::cin >> N >> C;

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

    if(N == 1) {
        std::cout << std::max(A[0], 0) << '\n';
        return;
    }

    std::vector<std::vector<int64_t>> dp(N, std::vector<int64_t>(2, 0));
    dfs(C, G, A, 0, -1, dp);

    std::cout << std::max(dp[0][0], dp[0][1]) << '\n';
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
