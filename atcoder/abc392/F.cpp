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
    
    fenwick_tree(int _n) : n(_n + 1), ft(_n + 1, 0) {
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

    fenwick_tree ft(N); 
    for(int i = 0; i < N; i++) {
        ft.update(i, 1);
    }

    std::vector<int> ans(N, 0);
    for(int i = N - 1; i >= 0; i--) {
        int lo = 0;
        int hi = N - 1;
        int res = -1;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            int sum = ft.query(mid);
            if(sum >= A[i]) {
                res = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        ans[res] = i;
        ft.update(res, -1);
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] + 1 << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
