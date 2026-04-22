#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

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
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    fenwick_tree ft1(N + 1);
    fenwick_tree ft2(N + 1);

    std::vector<int> l(N, 0);
    std::vector<int> r(N, 0);
    for(int i = 0; i < N; i++) {
        l[i] = ft1.query(1, A[i] - 1);
        ft1.update(A[i], 1);
    }

    for(int i = N - 1; i >= 0; i--) {
        r[i] = ft2.query(A[i] + 1, N);
        ft2.update(A[i], 1);
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        ans += l[i] == r[i] ? 1 : 0;
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
