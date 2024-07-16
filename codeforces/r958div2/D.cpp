#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = int64_t(2e18);
constexpr int MAX_R = 20;

void dfs(std::vector<std::vector<int>>& G, std::vector<int64_t>& A, int v, int p, std::vector<std::vector<int64_t>>& dp) {
    if((p != -1 && G[v].size() == 1) || (p == -1 && G[v].empty())) {
        for(int r = 1; r <= MAX_R; r++) {
            dp[v][r] = A[v] * r;
        }
        return;
    }

    for(int nei : G[v]) {
        if(nei == p) {
            continue; 
        }

        dfs(G, A, nei, v, dp);
    }

    for(int r = 1; r <= MAX_R; r++) {
        int64_t sum = 0;
        for(int nei : G[v]) {
            if(nei == p) {
                continue;
            }
            int64_t min_v = INF;
            for(int i = 1; i <= MAX_R; i++) {
                if(i != r) {
                    min_v = std::min(min_v, dp[nei][i]);
                }
            }
            sum += min_v;
        }
        dp[v][r] = std::min(dp[v][r], sum + r * A[v]);
    }
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int64_t> A(N);
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

    std::vector<std::vector<int64_t>> dp(N, std::vector<int64_t>(MAX_R + 1, INF));
    
    dfs(G, A, 0, -1, dp);
    
    int64_t ans = *std::min_element(dp[0].begin(), dp[0].end());
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
