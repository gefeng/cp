#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>
#include <set>

struct fenwick_tree {
    int n;
    std::vector<int64_t> ft;
    
    fenwick_tree(int n_) : n(n_ + 1), ft(n, 0) {}

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

    std::vector<int> A(N);
    std::vector<std::pair<int, int>> a(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        a[i] = {A[i], i};
    }

    std::ranges::sort(a);
    
    std::vector<int> pos(N, 0);
    for(int i = 0; i < N; i++) {
        pos[a[i].second] = i;
    }

    fenwick_tree ft1(N);
    fenwick_tree ft2(N);
    std::set<int> seen;
    std::vector<int64_t> ans(N, 0);
    int st = N;
    for(int i = 0; i < N; i++) {
        int p = pos[i];
        st = std::min(st, p);
        ft1.update(p, A[i]);
        ft2.update(p, 1);
        seen.insert(p);
        
        if(i == 0) {
            continue;
        }
        if(i == 1) {
            ans[i] = (A[0] + A[1]) / 2 - std::min(A[0], A[1]);
            continue;
        }
        
        int lo = st;
        int hi = *std::prev(seen.end());
        int j = hi;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            
            int64_t sum = ft1.query(mid + 1, N - 1);
            int64_t cnt = ft2.query(mid + 1, N - 1);

            int k = *std::prev(seen.upper_bound(mid));
            if(a[k].first * (cnt + 1) <= sum + a[st].first) {
                j = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        ans[i] = (ft1.query(j + 1, N - 1) + a[st].first) / (ft2.query(j + 1, N - 1) + 1) - a[st].first;
    }

    ft1 = fenwick_tree(N);
    ft2 = fenwick_tree(N);
    seen.clear();
    int ed = -1;
    for(int i = 0; i < N; i++) {
        int p = pos[i];
        ed = std::max(ed, p);
        ft1.update(p, A[i]);
        ft2.update(p, 1);
        seen.insert(p);

        if(i == 0) {
            continue;
        }
        if(i == 1) {
            ans[i] = std::max(ans[i], static_cast<int64_t>(std::max(A[0], A[1]) - (A[0] + A[1]) / 2));
            continue;
        }
        
        int lo = *std::next(seen.begin());
        int hi = ed;
        int j = ed;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;

            int64_t sum = ft1.query(mid - 1);
            int64_t cnt = ft2.query(mid - 1);
            int k = *seen.lower_bound(mid);
            
            if(a[k].first * (cnt + 1) >= sum + a[ed].first) {
                j = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        ans[i] = std::max(ans[i], a[ed].first - (ft1.query(j - 1) + a[ed].first) / (ft2.query(j - 1) + 1));
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
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
