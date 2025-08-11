#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

constexpr int64_t MOD = static_cast<int64_t>(1e9) + 7;
constexpr int MAX = 30;

void dfs(std::vector<int64_t>& dp, int now, int& K, int64_t& coe) {
    coe *= now;
    coe %= MOD;
    K -= 1;
    if(K == 0) {
        return;
    }
     
    for(int i = 0; i <= std::min(now - 2, MAX); i++) {
        int p2 = 1 << i;
        if(K >= p2) {
            K -= p2;
            coe *= dp[i];
            coe %= MOD;
            if(K == 0) {
                return;
            }

            continue;
        }

        dfs(dp, i + 1, K, coe);

        break;
    } 
}

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> dp(MAX + 1, 1);
    int64_t prod = 1;
    for(int i = 1; i <= MAX; i++) {
        dp[i] = prod * (i + 1) % MOD;
        prod *= dp[i];
        prod %= MOD;
    }

    std::ranges::sort(A);

    int64_t ans = 1;
    for(int i = 0; i < N; i++) {
        int64_t coe = 1;
        dfs(dp, A[i], K, coe);
        ans *= coe;
        ans %= MOD;

        if(K == 0) {
            break;
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
