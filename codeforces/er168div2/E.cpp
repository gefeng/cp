#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

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
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    fenwick_tree ft(N);
    std::vector<std::vector<int>> pos(N + 1);
    for(int i = 0; i < N; i++) {
        ft.update(i, 1); 
        pos[A[i]].push_back(i);
    }

    std::vector<std::vector<int>> lv_pos(N + 1);
    std::vector<int> last_pos(N + 1, -1);
    std::vector<int> now(N);
    std::iota(now.begin(), now.end(), 1);

    for(int lv = 1; lv <= N; lv++) {
        std::vector<int> nxt;
        for(int x : now) {
            int lo = last_pos[x] + 1;
            int hi = N - 1;
            int nxt_p = N;
            while(lo <= hi) {
                int mid = (lo + hi) >> 1;
                if(ft.query(last_pos[x] + 1, mid) >= x) {
                    nxt_p = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }

            if(nxt_p != N) {
                lv_pos[x].push_back(nxt_p);
                last_pos[x] = nxt_p;
                nxt.push_back(x);
            }
        }

        for(int p : pos[lv]) {
            ft.update(p, -1);
        }

        std::swap(now, nxt);
    }

    for(int i = 0; i < Q; i++) {
        int P, X;
        std::cin >> P >> X;
        P -= 1;
        
        auto it = std::lower_bound(lv_pos[X].begin(), lv_pos[X].end(), P);
        int lv = it - lv_pos[X].begin() + 1;

        std::cout << (lv <= A[P] ? "YES" : "NO") << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
