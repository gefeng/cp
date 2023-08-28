#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<std::pair<int, int>>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V, W;
        std::cin >> U >> V >> W;

        U -= 1;
        V -= 1;

        G[U].emplace_back(V, W);
        G[V].emplace_back(U, W);
    }

    int ans = 0;
    std::vector<std::vector<int>> dp(N, std::vector<int>(1 << N, 0));

    for(int i = 0; i < (1 << N); i++) {
        for(int j = 0; j < N; j++) {
            if(i & (1 << j)) {
               for(auto& nei : G[j]) {
                   int k = nei.first;
                   int w = nei.second;

                   if((i & (1 << k)) == 0) {
                       dp[k][i | (1 << k)] = std::max(dp[k][i | (1 << k)], dp[j][i] + w);
                   }
               }
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < (1 << N); j++) {
            ans = std::max(ans, dp[i][j]);
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
