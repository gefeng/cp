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
    std::vector<int64_t> ft;
    
    fenwick_tree(int _n) : n(_n + 1), ft(n, 0) {}

    void update(int i, int v) {
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

    std::string S;
    std::cin >> S;

    int64_t ans = 0;
    // x - y > px - py - x + y
    // px - 2x < py - 2y

    fenwick_tree ft_1(N * 4);
    fenwick_tree ft_2(N * 4);
    fenwick_tree ft_3(N * 4);
    fenwick_tree ft_4(N * 4);

    int sum = 0;
    int offset = N << 1;
    ft_1.update(-1 + offset, 1);
    ft_2.update(-1 + offset, 1);
    for(int i = 0; i < N; i++) {
        sum += S[i] == '0' ? 1 : 0;
        int x = i - sum * 2;
        int64_t cnt = ft_1.query(x + offset, N * 4 - 1); 
        int64_t tot = ft_3.query(x + offset, N * 4 - 1);
        ans += cnt * sum - tot;
        ft_1.update(x + offset, 1);
        ft_3.update(x + offset, sum);
    }

    sum = 0;
    for(int i = 0; i < N; i++) {
        sum += S[i] == '1' ? 1 : 0;
        int x = i - sum * 2;
        int64_t cnt = ft_2.query(x + offset + 1, N * 4 - 1);
        int64_t tot = ft_4.query(x + offset + 1, N * 4 - 1);
        ans += cnt * sum - tot;
        ft_2.update(x + offset, 1);
        ft_4.update(x + offset, sum);
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
