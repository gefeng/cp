#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <set>

struct segment_tree {
    const int INF = (int)1e9;
    int _n;
    int _m;
    std::vector<int> _st;
    
    segment_tree(int n) : _n(n) {
        while(__builtin_popcount(_n) != 1) {
            _n += 1;
        }

        _m = _n << 1;

        _st.resize(_m, INF);
    }

    segment_tree(std::vector<int>& a) : segment_tree(a.size()) {
        build(a); 
    }

    void build(std::vector<int>& a) {
        int n = a.size();
        for(int i = 0; i < n; i++) {
            _st[i + _n] = a[i];
        }

        for(int i = _n - 1; i > 0; i--) {
            propagate(i);
        }
    }

    void propagate(int i) {
        _st[i] = std::min(_st[i * 2], _st[i * 2 + 1]);
    }

    void set(int i, int v) {
        set(1, 0, _n - 1, i, i, v);  
    }
    
    void set(int v, int lo, int hi, int l, int r, int val) {
        if(hi < l || lo > r) {
            return;
        } 
        if(lo >= l && hi <= r) {
            _st[v] = val;
            return;
        }

        int mid = (lo + hi) >> 1;
        set(v * 2, lo, mid, l, r, val);
        set(v * 2 + 1, mid + 1, hi, l, r, val);
        propagate(v);
    }
    
    int query(int l, int r) {
        return query(1, 0, _n - 1, l, r);  
    }
    
    int query(int v, int lo, int hi, int l, int r) {
        if(hi < l || lo > r) {
            return INF;
        } 
        if(lo >= l && hi <= r) {
            return _st[v];
        }

        int mid = (lo + hi) >> 1;
        return std::min(query(v * 2, lo, mid, l, r), query(v * 2 + 1, mid + 1, hi, l, r));
    }
};

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::array<int, 3>> A(N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            std::cin >> A[i][j];
        }
    }

    std::map<int, int> m;
    int generator = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            m[A[i][j]] = 0;
        }
    }

    for(auto& [k, v] : m) {
        v = generator++;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            A[i][j] = m[A[i][j]];
        }
    }

    std::vector<std::array<int, 3>> a;
    segment_tree st(N * 3);
    for(int i = 0; i < N; i++) {
        std::sort(A[i].begin(), A[i].end());
            a.push_back({A[i][0], A[i][1], A[i][2]});
        do {
        } while(std::next_permutation(A[i].begin(), A[i].end()));
    }

    std::sort(a.begin(), a.end());

    int sz = a.size();
    for(int i = 0; i < sz; ) {
        int j = i;
        while(i < sz && a[i][0] == a[j][0]) {
            i += 1;
        }

        for(int k = j; k < i; k++) {
            int y = a[k][1];
            int z = a[k][2];

            if(st.query(0, y - 1) < z) {
                std::cout << "Yes" << '\n';
                return;
            }
        }

        for(int k = j; k < i; k++) {
            int y = a[k][1];
            int z = a[k][2];
            
            if(st.query(y, y) > z) {
                st.set(y, z);
            }
        }
    }

    std::cout << "No" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
