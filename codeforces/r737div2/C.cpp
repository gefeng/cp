#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(1e9) + 7;

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

int64_t dfs(int N, int K, std::vector<int>& a) {
    if(a.size() == N) {
        int s1 = a[0];
        int s2 = a[0];
        for(int i = 1; i < N; i++) {
            s1 &= a[i];
            s2 ^= a[i];
        }
        return s1 >= s2 ? 1 : 0;
    }
    
    int64_t res = 0;
    for(int x = 0; x < (1 << K); x++) {
        a.push_back(x);
        res += dfs(N, K, a);
        a.pop_back();
    }
    return res;
}

int64_t gen(int N, int K) {
    std::vector<int> a;
    return dfs(N, K, a);
}

void run_case() {
    int N, K;
    std::cin >> N >> K;
    
    if(K == 0) {
        std::cout << 1 << '\n';
        return;
    }

    std::vector<int64_t> fact(N + 1, 1);
    std::vector<int64_t> invf(N + 1, 1);
    std::vector<int64_t> p2(K + 1, 1);
    std::vector<int64_t> dp(K + 1, 0);

    for(int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i % MOD; invf[i] = q_pow(fact[i], MOD - 2); }
    
    for(int i = 1; i <= K; i++) {
        p2[i] = p2[i - 1] * 2 % MOD;
    }

    int64_t sum = 0;
    if(N % 2 == 0) {
        for(int i = 2; i <= N; i += 2) {
            sum += (fact[N] * invf[i] % MOD) * invf[N - i] % MOD;
            sum %= MOD;
        }
    } else {
        for(int i = 1; i <= N; i += 2) {
            sum += (fact[N] * invf[i] % MOD) * invf[N - i] % MOD;
            sum %= MOD;
        }
    }

    dp[0] = 1;
    for(int i = 1; i <= K; i++) {
        if(N % 2 == 0) {
            dp[i] = dp[i - 1] * sum % MOD; 
        } else {
            dp[i] += dp[i - 1] * ((sum + 1) % MOD) % MOD; 
        }
        dp[i] %= MOD;
    }

    int64_t ans = dp[K];
    if(N % 2 == 0) {
        for(int i = K - 1; i >= 0; i--) {
            int64_t x = dp[K - 1 - i] * q_pow(p2[i], N) % MOD;
            ans += x;
            ans %= MOD;
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
