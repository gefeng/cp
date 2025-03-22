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
    int N, M;
    std::cin >> N >> M;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    fenwick_tree ft_1(M + 1);
    fenwick_tree ft_2(M + 1);

    for(int x : A) {
        ft_2.update(x, 1);
    }

    std::vector<int64_t> diff(M + 1, 0);
    for(int i = 0; i < N; i++) {
        ft_2.update(A[i], -1);
        int a = ft_1.query(0, M) - ft_1.query(A[i], A[i]);
        int b = ft_1.query(A[i] + 1, M);
        int c = ft_2.query(0, M) - ft_2.query(A[i], A[i]);
        diff[M - A[i]] += a;
        diff[0] += b;
        diff[M - A[i]] -= c;
        diff[M] -= b;
        ft_1.update(A[i], 1);
    }
    
    int64_t rolling = 0;
    for(int i = 0; i < M; i++) {
        rolling += diff[i];
        std::cout << rolling << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
