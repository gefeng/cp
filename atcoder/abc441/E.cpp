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

    fenwick_tree ft(N * 2 + 10);    
    
    ft.update(N, 1);
    int sum = 0;
    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'A') {
            sum += 1;
        } else if(S[i] == 'B') {
            sum -= 1;
        }

        ans += ft.query(0, sum + N - 1); 
        ft.update(sum + N, 1);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
