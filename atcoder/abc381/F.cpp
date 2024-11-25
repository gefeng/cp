#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = 20;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] -= 1;
    }

    std::vector<std::array<int, MAX>> nxt(N);
    for(int i = N - 1; i >= 0; i--) {
        if(i == N - 1) {
            for(int j = 0; j < 20; j++) {
                nxt[i][j] = N;
            }
        } else {
            for(int j = 0; j < 20; j++) {
                nxt[i][j] = A[i + 1] == j ? i + 1 : nxt[i + 1][j];
            }
        }
    }

    std::vector<int> dp(1 << MAX, N);
    for(int i = 0; i < 20; i++) {
        int p = i == A[0] ? 0 : nxt[0][i];
        if(p == N) {
            continue;
        }
        p = nxt[p][i];
        if(p == N) {
            continue;
        }
        dp[1 << i] = p;
    }

    int ans = 0;
    for(int i = 1; i < (1 << MAX); i++) {
        if(dp[i] != N) {
            ans = std::max(ans, 2 * __builtin_popcount(i));
            for(int j = 0; j < 20; j++) {
                if(i & (1 << j)) {
                    continue;
                }
                int p = nxt[dp[i]][j];
                if(p == N) {
                    continue;
                }
                p = nxt[p][j];
                if(p == N) {
                    continue;
                }
                dp[i | (1 << j)] = std::min(dp[i | (1 << j)], p);
            }
        }
    }
    
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
