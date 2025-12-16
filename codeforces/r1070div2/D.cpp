#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>
#include <numeric>
#include <map>

constexpr int64_t MOD = static_cast<int64_t>(998244353);

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<std::pair<int, int>>> R(N);
    std::vector<std::pair<int, int>> E(M);
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        R[V].emplace_back(U, A[U]);
        E[i] = {U, V};
    }

    std::vector<int> order(M, 0);
    std::iota(order.begin(), order.end(), 0);
    
    std::ranges::sort(order, [&](int i, int j) {
                return A[E[i].first] + A[E[i].second] < A[E[j].first] + A[E[j].second];
            });

    std::vector<std::map<int64_t, int64_t>> dp(N);
    int64_t ans = 0;

    for(int i = 0; i < M; i++) {
        int e = order[i];
        auto [u, v] = E[e];

        dp[v][A[u]] += 1;
        dp[v][A[u]] %= MOD;
        
        if(A[v] > A[u]) {
            int64_t sum = A[v] - A[u];
            if(dp[u].find(sum) != dp[u].end()) {
                dp[v][A[u]] += dp[u][sum];
                dp[v][A[u]] %= MOD;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(auto [_, s] : dp[i]) {
            ans += s;
            ans %= MOD;
        }
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
