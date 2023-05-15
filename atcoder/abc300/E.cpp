#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using LL = long long;

constexpr LL MOD = 998244353LL;

LL dfs(LL N, LL inv_6, LL inv_5, LL x, std::map<LL, LL>& dp) {
    if(x == N) {
        return 1LL;
    }
    if(x > N) {
        return 0LL;
    }

    if(dp.find(x) != dp.end()) {
        return dp[x];
    }

    LL res = 0LL;
    for(LL i = 2LL; i <= 6; i++) {
        res += dfs(N, inv_6, inv_5, x * i, dp) * inv_5 % MOD;
        res %= MOD;
    }

    dp[x] = res;
    return res;
}

LL q_pow(LL x, LL y) {
    LL res = 1LL;
    while(y) {
        if(y & 1LL) {
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        y >>= 1;
    }
    return res;
}

void run_case() {
    LL N;
    std::cin >> N;

    LL inv_6 = q_pow(6LL, MOD - 2LL);
    LL inv_5 = q_pow(5LL, MOD - 2LL);

    std::map<LL, LL> dp;

    std::cout << dfs(N, inv_6, inv_5, 1LL, dp) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
