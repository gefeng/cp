#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

template<class T>
struct fenwick_tree {
    int n;
    int log;
    std::vector<T> ft;

    fenwick_tree(int _n) : n(_n + 1), log(0) {
        ft.resize(n, static_cast<T>(0));
        while((1 << (log + 1)) < n) {
            log++;
        }
    }

    void update(int i, T v) {
        for(++i; i < n; i += i & -i) {
            ft[i] += v;
        }
    }

    T query(int i) {
        T res = 0;
        for(++i; i > 0; i -= i & -i) {
            res += ft[i];
        }
        return res;
    }

    T query(int l, int r) {
        return query(r) - query(l - 1);
    }

    // smallest index i such that prefix sum >= k
    int kth(T k) {
        int now = 0;
        for(int pw = 1 << log; pw > 0; pw >>= 1) {
            if(now + pw < n && ft[now + pw] < k) {
                now += pw;
                k -= ft[now];
            }
        }
        return now + 1;
    }
};

void run_case() {
    int N;
    int64_t L, R;
    std::cin >> N >> L >> R;

    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::map<int64_t, int> m;
    int64_t sum = 0;
    m[0] = 0;
    for(int i = 0; i < N; i++) {
        sum += A[i];
        m[sum] = 0;
        m[sum - R] = 0;
        m[sum - L + 1] = 0;
    }

    int id = 0;
    for(auto& [_, x] : m) {
        x = id++;
    }

    auto count = [&](int64_t r) {
        int64_t res = 0;
        fenwick_tree<int> ft(id + 10);
        sum = 0;
        ft.update(m[0], 1);
        for(int i = 0; i < N; i++) {
            sum += A[i]; 
            res += ft.query(m[sum - r], id);
            ft.update(m[sum], 1);
        }
        return res;
    };
    
    std::cout << count(R) - count(L - 1) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
