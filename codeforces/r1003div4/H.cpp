#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(998244353);

struct fenwick_tree {
    int n;
    std::vector<int64_t> ft; fenwick_tree(int _n) : n(_n + 1), ft(n, 0) {}
    
    void update(int i, int64_t v) {
        for(++i; i < n; i += i & -i) {
            ft[i] += v;
            ft[i] += MOD;
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
    std::string S;
    std::cin >> S;

    int n = S.size();

    std::vector<int64_t> p_2(n + 1, 1);
    for(int i = 1; i <= n; i++) {
        p_2[i] = p_2[i - 1] * 2 % MOD;
    }

    fenwick_tree ft_1(n + 1);
    fenwick_tree ft_2(n + 1);
    fenwick_tree ft_3(n + 1);
    fenwick_tree ft_4(n + 1);
    int64_t ans = p_2[n] - 1;
    for(int i = 0; i < n; i++) {
        if(S[i] == '0') {
            ft_1.update(i, p_2[i]);
        } else {
            ft_2.update(i, p_2[i]);
        }
    }

    for(int i = n - 1; i >= 0; i--) {
        if(S[i] == '0') {
            ft_3.update(i, p_2[n - 1 - i]);
        } else {
            ft_4.update(i, p_2[n - 1 - i]);
        }
    }

    for(int i = 0; i < n; i++) {
        if(S[i] == '0') { 
            ans += ft_2.query(i) * p_2[n - 1 - i] % MOD;
        } else {
            ans += ft_1.query(i) * p_2[n - 1 - i] % MOD;
        }
    }

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int P;
        std::cin >> P;
        P -= 1;

        if(S[P] == '0') {
            ans -= ft_2.query(P) * p_2[n - 1 - P] % MOD;
            ans += MOD;
            ans %= MOD;
            
            ans -= ft_4.query(P, n - 1) * p_2[P] % MOD;
            ans += MOD;
            ans %= MOD;

            ft_1.update(P, -p_2[P]);
            ft_3.update(P, -p_2[n - 1 - P]);
            ft_2.update(P, p_2[P]);
            ft_4.update(P, p_2[n - 1 - P]);

            ans += ft_1.query(P) * p_2[n - 1 - P] % MOD;
            ans %= MOD;
            ans += ft_3.query(P, n - 1) * p_2[P] % MOD;
            ans %= MOD;
        } else {
            ans -= ft_1.query(P) * p_2[n - 1 - P] % MOD;
            ans += MOD;
            ans %= MOD;
            
            ans -= ft_3.query(P, n - 1) * p_2[P] % MOD;
            ans += MOD;
            ans %= MOD;

            ft_2.update(P, -p_2[P]);
            ft_4.update(P, -p_2[n - 1 - P]);
            ft_1.update(P, p_2[P]);
            ft_3.update(P, p_2[n - 1 - P]);
            
            ans += ft_2.query(P) * p_2[n - 1 - P] % MOD;
            ans %= MOD;
            ans += ft_4.query(P, n - 1) * p_2[P] % MOD;
            ans %= MOD;
        }

        S[P] = char(((S[P] - '0') ^ 1) + '0');

        std::cout << ans << " \n"[i == Q - 1];
    }
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
