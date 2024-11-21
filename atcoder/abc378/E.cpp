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
    std::vector<int> freq;
    std::vector<int64_t> sum;
    
    fenwick_tree(int _n) : n(_n + 1), freq(n, 0), sum(n, 0) {
    }

    void update(int i, int v) {
        int x = i;
        for(++i; i < n; i += i & -i) {
            freq[i] += v;
            sum[i] += x;
        }
    }
    
    int query_freq(int i) {
        int res = 0;
        for(++i; i > 0; i -= i & -i) {
            res += freq[i];
        }
        return res;
    }
    
    int64_t query_sum(int i) {
        int64_t res = 0;
        for(++i; i > 0; i -= i & -i) {
            res += sum[i];
        }
        return res;
    }

    int query_freq(int l, int r) {
        return query_freq(r) - query_freq(l - 1);
    }

    int64_t query_sum(int l, int r) {
        return query_sum(r) - query_sum(l - 1);
    }
};

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] %= M;
    }

    fenwick_tree ft(M);

    int64_t ans = 0;
    int now = 0;
    for(int i = 0; i < N; i++) {
        now += A[i];
        now %= M;
        
        ans += now;
        
        int64_t cnt = ft.query_freq(now);
        int64_t sum = ft.query_sum(now); 
        ans += now * cnt - sum;

        //std::cout << ft.query_sum(now - 1) << ' ' << ft.query_sum(M - 1) << '\n';
        sum = ft.query_sum(now + 1, M - 1);
        ans += int64_t(now) * (i - cnt) - sum + int64_t(M) * (i - cnt);

        ft.update(now, 1);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
