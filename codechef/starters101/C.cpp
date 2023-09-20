#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr int64_t MOD = (int64_t)1e9 + 7;

int64_t inv2;

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

int64_t dfs(int64_t N, int64_t L, int64_t R) {
    if(N == 1) {
        return 1;
    }
    
    int64_t sum = 0;

    if(L == 1 && R == N) {
        N %= MOD;
        sum = (((N + 1) % MOD) * N % MOD) * inv2 % MOD;
        return sum;
    }
    
    if(L > N / 2) {
        sum = dfs(N / 2, L - N / 2, R - N / 2) * 2 % MOD;
    } else if(R <= N / 2) {
        sum = dfs(N / 2, L, R) * 2 % MOD;
        int64_t x = (((R - L + MOD) % MOD) + 1) % MOD;
        sum = (sum - x + MOD) % MOD;
    } else {
        int64_t l = dfs(N / 2, L, N / 2) * 2 % MOD;
        int64_t r = dfs(N / 2, 1, R - N / 2) * 2 % MOD;
        int64_t x = (((N / 2 - L + MOD) % MOD) + 1) % MOD;
        l = (l - x + MOD) % MOD;
        sum = (l + r) % MOD;
    }

    return sum;
}

void run_case() {
    int64_t N, L, R;
    std::cin >> N >> L >> R;
    std::cout << dfs(N, L, R) << '\n'; 
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    inv2 = q_pow(2, MOD - 2);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
