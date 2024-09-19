#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
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

template <class S,
          auto op,
          auto e,
          class F,
          auto mapping,
          auto composition,
          auto id>
struct lazy_segtree {
    static_assert(std::is_convertible_v<decltype(op), std::function<S(S, S)>>,
                  "op must work as S(S, S)");
    static_assert(std::is_convertible_v<decltype(e), std::function<S()>>,
                  "e must work as S()");
    static_assert(
        std::is_convertible_v<decltype(mapping), std::function<S(F, S)>>,
        "mapping must work as F(F, S)");
    static_assert(
        std::is_convertible_v<decltype(composition), std::function<F(F, F)>>,
        "compostiion must work as F(F, F)");
    static_assert(std::is_convertible_v<decltype(id), std::function<F()>>,
                  "id must work as F()");

#else

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree {

#endif

  public:
    lazy_segtree() : lazy_segtree(0) {}
    explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
        size = (int)bit_ceil((unsigned int)(_n));
        log = countr_zero((unsigned int)size);
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
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

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
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
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

struct S {
    int64_t val;
    int64_t len;
    S() : val(0), len(0) {}
    S(int64_t _v, int64_t _l) : val(_v), len(_l) {}
};

//using S = int64_t;
using F = int64_t;

S op1(S a, S b) {
    return S(a.val + b.val, a.len + b.len);
}

S op2(S a, S b) {
    return S(std::max(a.val, b.val), a.len + b.len);
}

S e1() {
    return S();
}

S e2() {
    return S(-INF, 0);
}

S mapping1(F f, S x) {
    if(f == INF) {
        return x;
    }
    return S(f * x.len, x.len);
}

S mapping2(F f, S x) {
    if(f == INF) {
        return x;
    }
    return S(f, x.len);
}

F composition(F f, F g) {
    return f == INF ? g : f;
}

F id() {
    return INF;
}

int64_t t;
bool cmp1(S x) {
    return x.val <= t;
}

bool cmp2(S x) {
    return x.val < t;
}

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] -= i;
    }
    
    std::vector<S> init(N);
    for(int i = 0; i < N; i++) {
        init[i].val = A[i];
        init[i].len = 1;
    }
    lazy_segtree<S, op1, e1, F, mapping1, composition, id> st1(init);
    lazy_segtree<S, op2, e2, F, mapping2, composition, id> st2(init);

    int Q;
    std::cin >> Q;

    int64_t ans = 0;
    for(int i = 0; i < Q; i++) {
        int T;
        int64_t G;
        std::cin >> T >> G;

        T -= 1;
        G -= T;
    
        int pos = st1.prod(T, T + 1).val;
        if(pos <= G) {
            t = G;
            int r = st2.max_right<cmp1>(T); 
            int len = r - T;
            int64_t cost = G * len - st1.prod(T, r).val;
            ans += cost;

            st1.apply(T, r, G);
            st2.apply(T, r, G);
        } else {
            t = G;
            int l = st2.max_right<cmp2>(0);
            int len = T - l + 1;  
            int64_t cost = st1.prod(l, T + 1).val - G * len;
            ans += cost;
            
            st1.apply(l, T + 1, G);
            st2.apply(l, T + 1, G);
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
