#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)998244353;
constexpr int MAX = (int)2e5;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int sqr = (int)std::sqrt(MAX);
    std::vector<std::vector<int64_t>> save(sqr + 1, std::vector<int64_t>(sqr + 1, 0));
    std::vector<int64_t> dp(N + 1, 0);
    dp[1] = 1;

    int64_t ans = 0;
    for(int i = 1; i <= N; i++) {
        int v = A[i - 1];

        for(int d = 1; d <= sqr; d++) {
            dp[i] += save[d][i % d];
            dp[i] %= MOD;
        }

        if(v > sqr) {
            for(int x = 1; i + v * x <= N; x++) {
                int j = i + v * x;
                dp[j] += dp[i];
                dp[j] %= MOD;
            }
        } else {
            save[v][i % v] += dp[i];
            save[v][i % v] %= MOD;
        }

        ans += dp[i];
        ans %= MOD;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
