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
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> bad(N, std::vector<int>(N, 0));
    for(int i = 0; i < M; i++) {
        int P, X;
        std::cin >> P >> X;
        P -= 1;
        X -= 1;
        bad[P][X] = 1;
    }

    std::vector<std::vector<std::vector<int>>> good(N, std::vector<std::vector<int>>(N + 1, std::vector<int>(N, 1)));
    for(int i = 0; i < N; i++) {
        for(int j = i; j < N; j++) {
            int len = j - i + 1;
            for(int k = 0; k < len; k++) {
                for(int p = 0; p < len; p++) {
                    int x = ((p + k) % len) + i;
                    if(bad[x][p]) {
                        good[i][len][k] = 0;
                        break;
                    }
                }
            }
        }
    }

    std::vector<std::vector<int64_t>> dp(N + 1, std::vector<int64_t>(N + 1, 0));
    dp[0][0] = 1;

    for(int i = 1; i <= N; i++) {
        for(int j = i - 1; j >= 0; j--) {
            int s = i - j;
            for(int k = 0; k < s; k++) {
                if(!good[j][s][k]) {
                    continue;
                }
                
                int first = (s - k) % s;
                for(int l = 0; l <= j; l++) {
                    if(l && l == first) {
                        continue;
                    }
                    dp[i][k == 0 ? s : 0] += dp[j][l];
                    dp[i][k == 0 ? s : 0] %= MOD;
                }
            }
        }
    }

    int64_t ans = 0;
    for(int i = 0; i <= N; i++) {
        ans += dp[N][i];
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
