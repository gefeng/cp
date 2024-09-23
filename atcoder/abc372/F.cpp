#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(998244353);

void run_case() {
    int N, M, K;
    std::cin >> N >> M >> K;
 
    std::vector<int> indegree(N, 1);
    std::vector<int> outdegree(N, 1);
    
    std::vector<std::pair<int, int>> E(M);
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        E[i] = {U, V};
        outdegree[U] += 1;
        indegree[V] += 1;
    }
    
    if(M == 0) {
        std::cout << 1 << '\n';
        return;
    }

    std::vector<int> vertices;
    std::vector<int> mapping(N, -1);
    for(int i = 0; i < N; i++) {
        if(i == 0 || indegree[i] > 1 || outdegree[i] > 1) {
            vertices.push_back(i);
            mapping[i] = vertices.size() - 1;
        }
    }
    
    int n = vertices.size();
    std::vector<std::vector<std::pair<int, int>>> G(n);
    for(int i = 0; i < n; i++) {
        int w = (vertices[(i + 1) % n] - vertices[i] + N) % N;
        G[i].emplace_back((i + 1) % n, w);
    }
    
    for(auto [u, v] : E) {
        G[mapping[u]].emplace_back(mapping[v], 1); 
    }

    std::vector<std::vector<int64_t>> dp(K + 1, std::vector<int64_t>(n, 0));
    dp[0][0] = 1;
    for(int k = 0; k < K; k++) {
        for(int i = 0; i < n; i++) {
            for(auto [j, w] : G[i]) {
                dp[std::min(w + k, K)][j] += dp[k][i];
                dp[std::min(w + k, K)][j] %= MOD;
            }
        }
    }

    int64_t ans = 0;
    for(int i = 0; i < n; i++) {
        ans += dp[K][i];
        ans %= MOD;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
