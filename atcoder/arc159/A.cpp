#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = (int)2e9;

using LL = long long;

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<std::vector<int>> G(N, std::vector<int>(N, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> G[i][j];
        }
    }

    std::vector<std::vector<int>> dp(N, std::vector<int>(N, INF));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(G[i][j]) {
                dp[i][j] = 1;
            }
        }
    }

    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(dp[i][k] != INF && dp[k][j] != INF) {
                    dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
    }

    auto f = [&](LL x, LL y) {
        return std::make_pair(x % N, y % N);
    };

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        LL S, T;
        std::cin >> S >> T;

        S -= 1LL;
        T -= 1LL;
        
        auto [r, c] = f(S, T);

        /*if(r == c) {
            if(G[r][c]) {
                std::cout << 1 << '\n';
            } else {
                bool ok = false;
                for(int i = 0; i < N; i++) {
                    if(G[r][i]) {
                        ok = true;
                    }
                }

                if(ok) {
                    std::cout << 3 << '\n';
                } else {
                    std::cout << -1 << '\n';
                }
            }
        } else {
            std::cout << (dp[r][c] == INF ? -1 : dp[r][c]) << '\n';
        }*/
        std::cout << (dp[r][c] == INF ? -1 : dp[r][c]) << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
