#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = static_cast<int64_t>(998244353);

struct fenwick_tree {
    int n;
    std::vector<int> ft;

    fenwick_tree(int _n) : n(_n + 1) {
        ft.resize(n, 0);
    }

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
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<int> pos(N + 1, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        pos[A[i]] = i;
    }

    fenwick_tree ft(N);
    for(int i = 0; i < N; i++) {
        ft.update(i, 1);
    }

    int64_t ans = 1;
    for(int i = N; i > 1; i--) {
        int p = pos[i];
        int l = ft.query(0, p - 1);
        int r = ft.query(p + 1, N - 1);
        if(l != 0 && r != 0) {
            ans += 1;
            ans %= MOD;
        } else if(l == 0) {
            ans += r + 1; 
            ans %= MOD;
        } else {
            ans += l + 1;
            ans %= MOD;
        }
        ft.update(p, -1);
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
