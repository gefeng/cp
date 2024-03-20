#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)998244353;

int64_t q_pow(int64_t x, int64_t y) {
    int64_t res = 1;
    while(y) {
        if(y & 1) {
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        y >>= 1;
    }
    return res;
}

std::pair<int64_t, int64_t> dfs(int N, int i, int t, std::vector<std::vector<std::pair<int64_t, int64_t>>>& dp) {
    if(i == N) {
        return {0, 0};
    }

    if(dp[t][i].first != -1) {
        return dp[t][i];
    }

    int64_t p = i * q_pow(N, MOD - 2) % MOD;
    int64_t x = q_pow(((1 - (p * p % MOD) + MOD) % MOD), MOD - 2);
    int64_t p_proceed1 = ((1 - p + MOD) % MOD) * x % MOD;
    int64_t p_proceed2 = p_proceed1 * p % MOD;

    int64_t fa = t == 0 ? p * x % MOD : (p * p % MOD) * x % MOD;
    int64_t fb = t == 0 ? (p * p % MOD) * x % MOD : p * x % MOD;

    std::pair<int, int> f = dfs(N, i + 1, t ^ 1, dp); 

    fa += f.first * p_proceed1 % MOD;
    fa %= MOD;
    fb += f.second * p_proceed1 % MOD;
    fb %= MOD;

    f = dfs(N, i + 1, t, dp);
    fa += f.first * p_proceed2 % MOD;
    fa %= MOD;
    fb += f.second * p_proceed2 % MOD;
    fb %= MOD;

    return dp[t][i] = {fa, fb};
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::vector<std::pair<int64_t, int64_t>>> dp(2, std::vector<std::pair<int64_t, int64_t>>(N + 1, {-1, -1}));
    
    auto [ans1, ans2] = dfs(N, 0, 0, dp);

    std::cout << ans1 << ' ' << ans2 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
