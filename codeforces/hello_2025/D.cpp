#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <functional>

constexpr int64_t INF = int64_t(2e18);

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
    int64_t max_v;
    int64_t min_v;
    int64_t res;
    S() : max_v(-INF), min_v(INF), res(-INF) {}
    S(int64_t _v) : max_v(_v), min_v(_v), res(0) {}
};

S op_1(S a, S b) {
    S c;
    c.max_v = std::max(a.max_v, b.max_v);
    c.min_v = std::min(a.min_v, b.min_v);
    c.res = std::max(a.res, b.res);
    if(a.max_v != -INF && b.max_v != -INF) {
        c.res = std::max(c.res, b.max_v - a.min_v);
    }
    return c;
}

S op_2(S a, S b) {
    S c;
    c.max_v = std::max(a.max_v, b.max_v);
    c.min_v = std::min(a.min_v, b.min_v);
    c.res = std::max(a.res, b.res);
    if(a.max_v != -INF && b.max_v != -INF) {
        c.res = std::max(c.res, a.max_v - b.min_v);
    }
    return c;
}

S e() {
    return S();
}

void run_case() {
    int N, Q;
    std::cin >> N >> Q;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    segtree<S, op_1, e> st_1(N);
    segtree<S, op_2, e> st_2(N);
    for(int i = 0; i < N; i++) {
        st_1.set(i, S(A[i] - i));
        st_2.set(i, S(A[i] + i));
    }

    std::cout << std::max(st_1.all_prod().res, st_2.all_prod().res) << '\n';
    for(int i = 0; i < Q; i++) {
        int P, X;
        std::cin >> P >> X;
        P -= 1;

        st_1.set(P, S(X - P));
        st_2.set(P, S(X + P));
        std::cout << std::max(st_1.all_prod().res, st_2.all_prod().res) << '\n';
    }
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
