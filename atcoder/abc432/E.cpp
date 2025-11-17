#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = static_cast<int>(5e5);

struct fenwick_tree {
    int n;
    std::vector<int64_t> ft;

    fenwick_tree(int _n) : n(_n + 1) {
        ft.resize(n, 0);
    }

    void update(int i, int64_t v) {
        for(++i; i < n; i += i & -i) {
            ft[i] += v;
        }
    }

    int64_t query(int i) {
        int64_t res = 0;
        for(++i; i > 0; i -= i & -i) {
            res += ft[i];
        }
        return res;
    }

    int64_t query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

void run_case() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    fenwick_tree ft1(MAX + 10);
    fenwick_tree ft2(MAX + 10);
    for(int x : A) {
        ft1.update(x, 1);
        ft2.update(x, x);
    }

    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;
        if(T == 1) {
            int P, X;
            std::cin >> P >> X;
            P -= 1;
            ft1.update(A[P], -1);
            ft2.update(A[P], -A[P]);
            A[P] = X;
            ft1.update(A[P], 1);
            ft2.update(A[P], A[P]);
        } else {
            int L, R;
            std::cin >> L >> R;

            int64_t res = 0;
            if(L <= R) {
                res = ft2.query(L, R) + (L ? ft1.query(L - 1) * L : 0) + (R + 1 <= MAX ? ft1.query(R + 1, MAX) * R : 0);
            } else {
                res = static_cast<int64_t>(N) * L;
            }

            std::cout << res << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
