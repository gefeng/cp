#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr int64_t INF = (int64_t)1e18;

struct fenwick_tree {
    int n;
    std::vector<int> ft;
    
    fenwick_tree(int size) : n(size + 1), ft(n, 0) {

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

    std::map<int, int> m;
    int id = 1;
    for(int i = 0; i < N; i++) {
        m[A[i]] = 0;
    }

    for(auto& [_, v] : m) {
        v = id++;
    }

    
    std::vector<int> a(N);
    for(int i = 0; i < N; i++) {
        a[i] = m[A[i]];
    }

    std::sort(a.begin(), a.end(), std::greater<int>());
    
    int64_t tot_inv = 0;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && a[i] == a[j]) {
            i += 1;
        }

        tot_inv += (int64_t)j * (i - j);
    }

    fenwick_tree ft(N + 10);

    int64_t ans = INF;
    int64_t cnt_inv = 0;
    int64_t cnt_op = 0;
    
    for(int i = 0; i < N; i++) {
        int v = m[A[i]];
        cnt_inv += ft.query(v + 1, N);
        ft.update(v, 1);
    }

    if(cnt_inv == 0) {
        std::cout << 0 << '\n';
        return;
    }

    for(int i = N - 1; i >= 0; i--) {
        int v = m[A[i]]; 
        cnt_inv -= ft.query(v + 1, N);
        cnt_inv += ft.query(v - 1); 
        cnt_op += 1;

        if(cnt_inv == 0) {
            ans = std::min(ans, cnt_op);
        } else if(cnt_inv == tot_inv) {
            ans = std::min(ans, cnt_op + 1);
        }
    }

    std::reverse(A.begin(), A.end());
    cnt_op = 1;
    cnt_inv = 0;
    ft = fenwick_tree(N + 1);
    for(int i = 0; i < N; i++) {
        int v = m[A[i]];
        cnt_inv += ft.query(v + 1, N);
        ft.update(v, 1);
    }

    if(cnt_inv == 0) {
        ans = std::min(ans, 1LL);
    }

    for(int i = N - 1; i >= 0; i--) {
        int v = m[A[i]]; 
        cnt_inv -= ft.query(v + 1, N);
        cnt_inv += ft.query(v - 1); 
        cnt_op += 1;

        if(cnt_inv == 0) {
            ans = std::min(ans, cnt_op);
        } else if(cnt_inv == tot_inv) {
            ans = std::min(ans, cnt_op + 1);
        }
    }

    std::cout << (ans == INF ? -1 : ans) << '\n';
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
