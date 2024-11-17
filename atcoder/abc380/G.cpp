#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(998244353);

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

struct fenwick_tree {
    int n;
    std::vector<int> ft;
    fenwick_tree(int _n) : n(_n + 1), ft(n, 0) {}

    void update(int i, int v) {
        for(++i; i < n; i += i & -i) {
            ft[i] += v;
        }
    }

    int query(int i) {
        int res = 0;
        for(++i; i > 0; i -= i & -i) {
            res += ft[i];
        }
        return res;
    }

    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

void run_case() {
    int N, K;
    std::cin >> N >> K;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] -= 1;
    }

    std::vector<int64_t> fact(K + 1, 1);
    for(int i = 1; i <= K; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    int64_t e = K == 1 ? 0 : (fact[K] * q_pow(fact[K - 2], MOD - 2) % MOD) * q_pow(2, MOD - 2) % MOD;
    e *= q_pow(2, MOD - 2);
    e %= MOD;

    int64_t p = q_pow(N - K + 1, MOD - 2);
    
    fenwick_tree ft_1(N);
    fenwick_tree ft_2(N);
    int64_t inv = 0;
    for(int i = 0; i < N; i++) {
        inv += ft_1.query(A[i] + 1, N - 1);
        inv %= MOD;
        ft_1.update(A[i], 1);
    }

    int64_t ans = 0;
    int64_t cnt = 0;
    for(int l = 0, r = 0; r < N; r++) {
        
        if(r - l + 1 > K) {
            cnt -= ft_2.query(A[l] - 1);
            cnt += MOD;
            cnt %= MOD;
            ft_2.update(A[l++], -1);
        }

        cnt += ft_2.query(A[r] + 1, N - 1);
        cnt %= MOD;

        ft_2.update(A[r], 1);

        if(r - l + 1 == K) {
            ans += ((((inv - cnt + MOD) % MOD) + e) % MOD) * p % MOD;
            ans %= MOD;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
