#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <functional>

constexpr int64_t MOD = static_cast<int64_t>(998244353);

struct fenwick_tree {
    int n;
    std::vector<int64_t> ft;
    
    fenwick_tree(int n_) : n(n_ + 1), ft(n, static_cast<int64_t>(0)) {}

    void update(int i, int64_t v) {
        for(++i; i < n; i += i & -i) {
            ft[i] += v;
            ft[i] %= MOD;
        } 
    }

    int64_t query(int i) {
        int64_t res = 0;
        for(++i; i > 0; i -= i & -i) {
            res += ft[i];
            res %= MOD;
        }
        return res;
    }

    int64_t query(int l, int r) {
        return (query(r) - query(l - 1) + MOD) % MOD;
    }
};

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<fenwick_tree> dp(3, fenwick_tree(N + 1));
    for(int i = 0; i < N; i++) {
        dp[0].update(A[i], 1);
        dp[1].update(A[i], dp[0].query(1, A[i] - 1));
        dp[1].update(A[i], dp[1].query(1, A[i] - 1));
        dp[1].update(A[i], dp[2].query(1, A[i] - 1));
        
        dp[2].update(A[i], dp[1].query(A[i] + 1, N));
        dp[2].update(A[i], dp[2].query(A[i] + 1, N));
    }

    std::cout << dp[2].query(1, N) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
