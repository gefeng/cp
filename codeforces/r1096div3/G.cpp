#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

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
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t ans = 0;
    std::vector<int64_t> psum0(N + 1, 0);
    std::vector<int64_t> psum1(N + 1, 0);

    for(int i = 0; i < N; i++) {
        if(i % 2 == 0) {
            psum0[i + 1] = psum0[i] + A[i];
            psum1[i + 1] = psum1[i];
        } else {
            psum0[i + 1] = psum0[i];
            psum1[i + 1] = psum1[i] + A[i];
        }
    }


    {
        // compress
        std::map<int64_t, int> m;
        m[0] = 0;
        
        for(int i = 0; i < N; i++) {
            m[psum0[i + 1] - psum1[i + 1]] = 0;
        }

        int id = 0;
        for(auto& [_, x] : m) {
            x = id++;
        }

        fenwick_tree ft(id + 10);
        ft.update(m[0], 1);
        for(int i = 0; i < N; i++) {
            int t = m[psum0[i + 1] - psum1[i + 1]];
            if(i % 2 == 0) {
                ans += ft.query(0, t - 1);
            } else {
                ft.update(t, 1);
            }
        }
    }

    {
        // compress
        std::map<int64_t, int> m;
        m[0] = 0;
        
        for(int i = 0; i < N; i++) {
            m[psum1[i + 1] - psum0[i + 1]] = 0;
        }

        int id = 0;
        for(auto& [_, x] : m) {
            x = id++;
        }

        fenwick_tree ft(id + 10);
        for(int i = 0; i < N; i++) {
            int t = m[psum1[i + 1] - psum0[i + 1]];
            if(i % 2 == 1) {
                ans += ft.query(0, t - 1);
            } else {
                ft.update(t, 1);
            }
        }
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
