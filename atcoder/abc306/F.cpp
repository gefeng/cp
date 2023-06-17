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

struct fenwick_tree {
    int n;
    std::vector<int> ft;

    fenwick_tree(int _n) : n(_n + 1) {
        ft.resize(n, 0);
    }

    void update(int i, int v) {
        for(i += 1; i < n; i += i & -i) {
            ft[i] += v;
        }
    }

    int query(int i) {
        int res = 0;
        for(i += 1; i > 0; i -= i & -i) {
            res += ft[i];
        }
        return res;
    }

    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> A(N, std::vector<int>(M, 0));
    std::map<int, int> m;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> A[i][j];
            m[A[i][j]] = 0;
        }
    }

    int generator = 0;
    for(auto& [_, v] : m) {
        v = generator++;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            A[i][j] = m[A[i][j]];
        }
    }

    fenwick_tree ft(m.size());
    LL ans = (1LL * N * (N - 1) / 2LL) * (1LL * M * (M + 1LL) / 2LL);

    for(int i = N - 1; i >= 0; i--) {
        for(int j = 0; j < M; j++) {
            ans += ft.query(A[i][j] - 1);
        }

        for(int j = 0; j < M; j++) {
            ft.update(A[i][j], 1);
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
