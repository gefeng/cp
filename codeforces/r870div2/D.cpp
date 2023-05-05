#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr int INF = (int)2e9;

struct fenwick_tree {
    int n;
    std::vector<int> ft;

    fenwick_tree(int _n) : n(_n + 1) {
        ft.resize(n, 0);
    }

    void update(int i, int v) {
        for(i++; i < n; i += i & -i) {
            ft[i] += v;
        }
    }

    int query(int i) {
        int res = 0;
        for(i++; i > 0; i -= i & -i) {
            res += ft[i];
        }
        return res;
    }

    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

struct seg_tree {
    int N, M, H;
    std::vector<int> st;

    seg_tree(int n) {
        build(n);
    }

    seg_tree(std::vector<int>& v) {
        build(v);
    }

    int highest_one_bit(unsigned int i) {
        i |= (i >>  1);
        i |= (i >>  2);
        i |= (i >>  4);
        i |= (i >>  8);
        i |= (i >> 16);
        return i - (i >> 1); 
    }

    void propagate(int i) {
        st[i] = std::max(st[2 * i], st[2 * i + 1]);
    }

    void build(int n) {
        N = n;
        M = highest_one_bit(std::max(1, N - 1)) << 2; 
        H = M / 2;
        st.resize(M, -INF);
    }

    void build(std::vector<int>& v) {
        build(v.size());
        
        for(int i = 0; i < N; i++) {
            st[i + H] = v[i];
        }
        
        for(int i = H - 1; i > 0; i--) {
            propagate(i);
        }
    }

    void add(int i, int v) {
        st[i + H] = v;
        for(int j = (i + H) >> 1; j > 0; j >>= 1) {
            propagate(j);
        }
    }

    int query(int l, int r) {
        int res = -INF;
        for(l += H, r += H; l <= r; l >>= 1, r >>= 1) {
            if(l & 1) {
                res = std::max(res, st[l++]);
            }
            if(!(r & 1)) {
                res = std::max(res, st[r--]);
            }
        }
        return res;
    }
};

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> pre_greater(N, -1);
    std::vector<int> nxt_greater(N, N);
    std::vector<int> s;
    seg_tree rmq1(N);
    seg_tree rmq2(N);

    for(int i = 0; i < N; i++) {
        while(!s.empty() && A[s.back()] <= A[i]) {
            s.pop_back();
        }
        if(!s.empty()) {
            pre_greater[i] = s.back();
        }
        s.push_back(i);
    }

    s = std::vector<int>();
    for(int i = N - 1; i >= 0; i--) {
        while(!s.empty() && A[s.back()] <= A[i]) {
            s.pop_back();
        }
        if(!s.empty()) {
            nxt_greater[i] = s.back();
        }
        s.push_back(i);
    }

    for(int i = 0; i < N; i++) {
        rmq1.add(i, A[i] + i);
        rmq2.add(i, A[i] - i);
    }

    int ans = 0;
    for(int i = 1; i < N - 1; i++) {
        int l = pre_greater[i];
        int r = nxt_greater[i];

        if(l == -1) {
            l = 0;
        }
        if(r == N) {
            r = N - 1;
        }

        int max_1 = rmq1.query(l, i - 1);
        int max_2 = rmq2.query(i + 1, r);
        ans = std::max(ans, max_1 + max_2 + A[i]);
    }

    std::cout << ans << '\n';
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
