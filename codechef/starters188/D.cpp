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
    int N, Q;
    std::cin >> N >> Q;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    fenwick_tree ft_1(N + 1);
    fenwick_tree ft_2(N + 1);
    std::vector<int64_t> psum_1(N + 2, 0);
    std::vector<int64_t> psum_2(N + 2, 0);
    int64_t tot = 0;
    for(int i = 0; i < N; i++) {
        int x = ft_1.query(A[i] + 1, N);
        psum_1[A[i] + 1] = x;
        ft_1.update(A[i], 1);
        tot += x;
    }

    for(int i = N - 1; i >= 0; i--) {
        int x = ft_2.query(1, A[i] - 1); 
        psum_2[A[i] + 1] = x;
        ft_2.update(A[i], 1);
    }

    for(int i = 1; i <= N + 1; i++) {
        psum_1[i] += psum_1[i - 1];
        psum_2[i] += psum_2[i - 1];
    }

    for(int i = 0; i < Q; i++) {
        int L, R;
        std::cin >> L >> R;
         
        if(L == R) {
            std::cout << 0 << '\n';
            continue;
        }
        int64_t res = tot - (psum_1[N + 1] - psum_1[R]) - psum_2[L + 1];
        std::cout << res << '\n';
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
