#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

struct fenwick_tree {
    int n;
    std::vector<int> ft;

    fenwick_tree(int n_) : n(n_ + 1), ft(n, 0) {}

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

    int64_t ans = 0;
    fenwick_tree ft(N);
    for(int b = 1; b <= N; b++) {
        int p = pos[b];
        int l = ft.query(p - 1);
        int r = ft.query(p + 1, N - 1);
        ans += static_cast<int64_t>(r + 1) * (l + 1);
        ft.update(p, 1);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
