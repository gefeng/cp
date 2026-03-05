#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <functional>

constexpr int64_t MOD = static_cast<int64_t>(998244353);
constexpr int64_t INF = static_cast<int64_t>(2e18);

int64_t q_pow(int64_t x, int64_t y) {
    int64_t res = 1;
    while(y) {
        if(y & 1) {
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        y >>= 1;
    }
    return res;
}

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
    int64_t sum;
    int64_t cnt;
};

S op(S a, S b) {
    return S{
        std::max(a.max_v, b.max_v),
        std::min(a.min_v, b.min_v), 
        a.sum + b.sum,
        a.cnt + b.cnt
    };
}

S id() {
    return S{-INF, INF, static_cast<int64_t>(0), static_cast<int64_t>(0)};
}

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> inv(N + 1, 1);
    for(int i = 1; i <= N; i++) {
        inv[i] = q_pow(i, MOD - 2);
    }

    std::vector<int64_t> sort_a(A);
    std::ranges::sort(sort_a);

    segtree<S, op, id> st(N);

    for(int i = 0; i < N; i++) {
        int p = std::lower_bound(sort_a.begin(), sort_a.end(), A[i]) - sort_a.begin();
        st.set(p, S{A[i], A[i], A[i], 1});

        if(i < 2) {
            continue;
        }

        int lo = 0;
        int hi = N - 1;
        int best = -1;
        int64_t res = INF;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;

            S l = st.prod(0, mid);
            S r = st.prod(mid + 1, N);
            int64_t sr = r.sum - r.cnt * r.min_v;
            int64_t sl = l.cnt * l.max_v - l.sum;

            if(sr >= sl) {
                best = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        for(int j = -1; j <= 1; j++) {
            if(best + j >= 0 && best + j < N) {
                S l = st.prod(0, best + j);
                S r = st.prod(best + j + 1, N);
                int64_t sr = r.sum - r.cnt * r.min_v;
                int64_t sl = l.cnt * l.max_v - l.sum;
                res = std::min(res, std::max(sl, sr));
            }
        }
        res %= MOD;
        res *= inv[i - 1];
        res %= MOD;
        std::cout << res << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
