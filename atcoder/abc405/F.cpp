#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <tuple>

constexpr int MAX = int(2e6);

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
    int N, M;
    std::cin >> N >> M;

    std::vector<std::pair<int, int>> A(M);
    for(int i = 0; i < M; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    int Q;
    std::cin >> Q;
    std::vector<std::tuple<int, int, int>> B(Q);
    for(int i = 0; i < Q; i++) {
        auto& [U, V, idx] = B[i];
        std::cin >> U >> V;
        idx = i;
    }

    std::sort(A.begin(), A.end(), [](const auto& x, const auto& y) {
                return x.first < y.first;
            });

    std::sort(B.begin(), B.end(), [](const auto& x, const auto& y) {
                return std::get<0>(x) < std::get<0>(y);
            });

    fenwick_tree ft_1(MAX + 10);
    fenwick_tree ft_2(MAX + 10);
    std::vector<int> ans(Q);

    for(int i = 0, j = 0; i < Q; i++) {
        auto [l, r, idx] = B[i];
        while(j < M && A[j].first < l) {
            ft_1.update(A[j++].second, 1);
        } 
        ans[idx] += ft_1.query(l, r); 
    }

    std::sort(A.begin(), A.end(), [](const auto& x, const auto& y) {
                return x.second > y.second;
            });

    std::sort(B.begin(), B.end(), [](const auto& x, const auto& y) {
                return std::get<1>(x) > std::get<1>(y);
            });

    for(int i = 0, j = 0; i < Q; i++) {
        auto [l, r, idx] = B[i];
        while(j < M && A[j].second > r) {
            ft_2.update(A[j++].first, 1);
        }
        ans[idx] += ft_2.query(l, r);
    }

    for(int i = 0; i < Q; i++) {
        std::cout << ans[i] << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
