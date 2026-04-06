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
    
    fenwick_tree(int n_) : n(n_ + 1) {
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
    int64_t K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    auto count = [&](int64_t k) {
        fenwick_tree ft(N + 10);
        int64_t ans = 0;
        int64_t now = 0;

        for(int l = 0, r = 0; r < N; r++) {
            ft.update(A[r], 1);
            now += ft.query(A[r] + 1, N);
            while(l <= r && now > k) {
                now -= ft.query(A[l] - 1);
                ft.update(A[l], -1);
                l++;
            }
            ans += r - l + 1;
        }
        return ans;
    };

    std::cout << count(K) - count(K - 1) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
