#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr int MAX = int(3e5);

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

    std::string S;
    std::cin >> S;

    int a = 0;
    int b = 0;
    int64_t ans = 0;
    int offset = MAX * 4;
    fenwick_tree ft(MAX * 10);
    std::map<int, int> m;

    ft.update(offset, 1);
    m[offset] = 1;

    for(int i = 0; i < N; i++) {
        if(S[i] == '0') {
            a += 1;
        } else {
            b += 1;
        }

        int x = a - 3 * b - 2 + offset;
        int y = a - 3 * b + 1 + offset;
        
        int cnt = ft.query(x);
        ans += cnt;

        if(m.find(y) != m.end()) {
            cnt = m[y];
            ans += cnt;
        }
        
        ft.update(a - 3 * b + offset, 1);
        m[a - 3 * b + offset] += 1;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
