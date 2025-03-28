#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(998244353);

int64_t sqrt_d = 0;

void run_case() {
    int N, M, D;
    std::cin >> N >> M >> D;

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N; i++) {
        std::string S;
        std::cin >> S;
        for(int j = 0; j < M; j++) {
            if(S[j] == 'X') {
                G[i].push_back(j);
            }
        }
    }

    sqrt_d = int64_t(sqrtl(int64_t(D) * D - 1));
    
    int64_t ans = 0;
    std::vector<std::vector<std::vector<int64_t>>> dp(2, std::vector<std::vector<int64_t>>(N, std::vector<int64_t>(M, 0)));
    std::vector<std::vector<std::vector<int64_t>>> ds(2, std::vector<std::vector<int64_t>>(N, std::vector<int64_t>(M + 1, 0)));

    for(int c : G[N - 1]) {
        dp[0][N - 1][c] = 1;
    }
    
    for(int r = N - 1; r >= 0; r--) {
        for(int i = 0; i < M; i++) {
            ds[0][r][i + 1] = (ds[0][r][i] + dp[0][r][i]) % MOD;
        }

        for(int c : G[r]) {
            auto lb = std::lower_bound(G[r].begin(), G[r].end(), std::max(0, c - D));
            auto ub = std::upper_bound(G[r].begin(), G[r].end(), std::min(M - 1, c + D));

            int x = lb == G[r].end() ? M : *lb;
            int y = ub == G[r].end() ? M : *ub;
            dp[1][r][c] += ((ds[0][r][y] - ds[0][r][x] + MOD) % MOD) - dp[0][r][c];
            dp[1][r][c] += MOD;
            dp[1][r][c] %= MOD;
        }

        for(int i = 0; i < M; i++) {
            ds[1][r][i + 1] = (ds[1][r][i] + dp[1][r][i]) % MOD;
        }

        if(r - 1 >= 0) {
            for(int c : G[r - 1]) {
                auto lb = std::lower_bound(G[r].begin(), G[r].end(), std::max(int64_t(0), c - sqrt_d));
                auto ub = std::upper_bound(G[r].begin(), G[r].end(), std::min(int64_t(M - 1), c + sqrt_d));
                
                int x = lb == G[r].end() ? M : *lb;
                int y = ub == G[r].end() ? M : *ub;
                for(int k = 0; k < 2; k++) {
                    dp[0][r - 1][c] += (ds[k][r][y] - ds[k][r][x] + MOD) % MOD;
                    dp[0][r - 1][c] %= MOD;
                }
            }
        }
    }

    for(int c : G[0]) {
        ans += (dp[0][0][c] + dp[1][0][c]) % MOD;
        ans %= MOD;
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
