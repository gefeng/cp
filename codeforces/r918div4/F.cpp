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
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i] >> B[i];
    }

    std::map<int, int> compress;
    int id = 0;
    for(int i = 0; i < N; i++) {
        compress[A[i]] = 0;
        compress[B[i]] = 0;
    }
    
    for(auto& [_, v] : compress) {
        v = id++;
    }

    std::vector<std::pair<int, int>> a;
    std::map<int, int> m;
    for(int i = 0; i < N; i++) {
        int x = compress[A[i]];
        int y = compress[B[i]];
        a.emplace_back(x, 0);
        a.emplace_back(y, 1);
        m[y] = x;
    }

    std::sort(a.begin(), a.end());

    int64_t ans = 0;
    fenwick_tree ft(N * 2 + 10);
    for(int i = 0; i < N * 2; i++) {
        if(a[i].second == 0) {
            ft.update(a[i].first, 1);
        } else {
            int l = m[a[i].first]; 
            ft.update(l, -1);
            ans += ft.query(0, l);
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
