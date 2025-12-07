#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <functional>

unsigned int bit_ceil(unsigned int n) {
    unsigned int x = 1;
    while (x < (unsigned int)(n)) x *= 2;
    return x;
}

int countr_zero(unsigned int n) {
    return __builtin_ctz(n);
}

#if __cplusplus >= 201703L

template <class S, auto op, auto e> struct segtree {
    static_assert(std::is_convertible_v<decltype(op), std::function<S(S, S)>>,
                  "op must work as S(S, S)");
    static_assert(std::is_convertible_v<decltype(e), std::function<S()>>,
                  "e must work as S()");

#else

template <class S, S (*op)(S, S), S (*e)()> struct segtree {

#endif

  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
        size = bit_ceil((unsigned int)(_n));
        log = countr_zero((unsigned int)size);
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

struct S {
    int v;
    int p;
    S(int v_, int p_) : v(v_), p(p_) {}
};

S op(S a, S b) {
    if(a.v > b.v) {
        return a;
    }
    return b;
}

S id() {
    return S(-1, - 1);
}

int64_t dfs(std::vector<int>& A, std::vector<int>& pre, std::vector<int>& nxt, segtree<S, op, id>& st, 
        int p, std::vector<int64_t>& dp) {
    int l = pre[p];
    int r = nxt[p];
    if(p - l <= 1 && r - p <= 1) {
        return 0;
    }

    if(dp[p] != -1) {
        return dp[p];
    }

    int64_t res = 0;
    if(p - l > 1) {
        auto [max_v, np] = st.prod(l + 1, p);
        res = std::max(res, dfs(A, pre, nxt, st, np, dp) + std::abs(p - np));
    }
    
    if(r - p > 1) {
        auto [max_v, np] = st.prod(p + 1, r);
        res = std::max(res, dfs(A, pre, nxt, st, np, dp) + std::abs(p - np));
    }

    return dp[p] = res;
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    int p = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        if(A[i] == N) {
            p = i;
        }
    }

    std::vector<int> pre(N, -1);
    std::vector<int> nxt(N, N);
    std::vector<int> stk;
    
    for(int i = 0; i < N; i++) {
        while(!stk.empty() && A[stk.back()] < A[i]) {
            stk.pop_back();
        }
        if(!stk.empty()) {
            pre[i] = stk.back();
        }
        stk.push_back(i);
    }

    stk.clear();

    for(int i = N - 1; i >= 0; i--) {
        while(!stk.empty() && A[stk.back()] < A[i]) {
            stk.pop_back();
        }
        if(!stk.empty()) {
            nxt[i] = stk.back();
        }
        stk.push_back(i);
    }

    std::vector<int64_t> dp(N, -1);
    segtree<S, op, id> st(N);
    for(int i = 0; i < N; i++) {
        st.set(i, S(A[i], i));
    }
    std::cout << dfs(A, pre, nxt, st, p, dp) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
