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
    std::vector<int64_t> ft;

    fenwick_tree(int n) : n(n + 1), ft(n + 1, 0) {}
    
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
    int N;
    std::cin >> N;
    
    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first;
        A[i].second = i;
    }

    std::sort(A.begin(), A.end(), std::greater<std::pair<int, int>>());

    int64_t ans = 0;
    fenwick_tree ft1(N);
    fenwick_tree ft2(N);

    for(int i = 0; i < N; i++) {
        auto [v, p] = A[i];
        int64_t sum = ft2.query(p + 1, N - 1);
        int64_t cnt = ft1.query(p + 1, N - 1);
        ans += sum - cnt * v;

        ft1.update(p, 1);
        ft2.update(p, v);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
