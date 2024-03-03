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
    int max1, max2;
    int cnt1, cnt2;
    S() : max1(0), max2(0), cnt1(0), cnt2(0) {}
    S(int v) : max1(v), max2(0), cnt1(1), cnt2(0) {}
    S(int max1, int max2, int cnt1, int cnt2) : max1(max1), max2(max2), cnt1(cnt1), cnt2(cnt2) {}
};

S op(S a, S b) {
    int max1, max2, cnt1, cnt2;
    if(a.max1 > b.max1) {
        max1 = a.max1;
        cnt1 = a.cnt1;
        if(a.max2 > b.max1) {
            max2 = a.max2;
            cnt2 = a.cnt2;
        } else if(b.max1 > a.max2) {
            max2 = b.max1;
            cnt2 = b.cnt1;
        } else {
            max2 = a.max2;
            cnt2 = a.cnt2 + b.cnt1;
        }
    } else if(b.max1 > a.max1) {
        max1 = b.max1;
        cnt1 = b.cnt1;
        if(b.max2 > a.max1) {
            max2 = b.max2;
            cnt2 = b.cnt2;
        } else if(a.max1 > b.max2) {
            max2 = a.max1;
            cnt2 = a.cnt1;
        } else {
            max2 = b.max2;
            cnt2 = a.cnt1 + b.cnt2;
        }
    } else {
        max1 = a.max1;
        cnt1 = a.cnt1 + b.cnt1;
        if(a.max2 > b.max2) {
            max2 = a.max2;
            cnt2 = a.cnt2;
        } else if(b.max2 > a.max2) {
            max2 = b.max2;
            cnt2 = b.cnt2;
        } else {
            max2 = a.max2;
            cnt2 = a.cnt2 + b.cnt2;
        }
    }

    return S(max1, max2, cnt1, cnt2);
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

    std::vector<S> a;
    for(int i = 0; i < N; i++) {
        a.emplace_back(A[i]);
    }
    
    segtree<S, op, e> st(a);

    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;
        
        if(T == 1) {
            int P, X;
            std::cin >> P >> X;
            P -= 1;
            st.set(P, S(X));
        } else {
            int L, R;
            std::cin >> L >> R;
            L -= 1;
            R -= 1;
            S res = st.prod(L, R + 1);
            if(res.max1 == res.max2) {
                std::cout << 0 << '\n';
            } else {
                std::cout << res.cnt2 << '\n';
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
