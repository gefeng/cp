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

struct Mint {
    const static int64_t MOD = (int64_t)998244353;
    int64_t x;
    Mint() : x(0) {}
    Mint(int64_t _x) : x(((_x % MOD) + MOD) % MOD) {}

    friend std::ostream& operator<<(std::ostream& os, const Mint& obj) {
        return os << obj.x;
    }
    
    Mint& operator+=(const Mint& rhs) {
        x += rhs.x;
        x %= MOD;
        return *this;
    }
    
    Mint& operator-=(const Mint& rhs) {
        x -= rhs.x;
        x += MOD;
        x %= MOD;
        return *this;
    }

    Mint& operator*=(const Mint& rhs) {
        x *= rhs.x; 
        x %= MOD;
        return *this;
    }
    
    friend Mint operator+(Mint lhs, const Mint& rhs) {
        lhs.x += rhs.x;
        lhs.x %= MOD;
        return lhs;
    }

    friend Mint operator-(Mint lhs, const Mint& rhs) {
        lhs.x -= rhs.x;
        lhs.x += MOD;
        lhs.x %= MOD;
        return lhs;
    }
    
    friend Mint operator*(Mint lhs, const Mint& rhs) {
        lhs.x *= rhs.x;
        lhs.x %= MOD;
        return lhs;
    }
};

struct S {
    Mint sa;
    Mint sb;
    Mint sab;
    Mint len;
    S() : sa(0), sb(0), sab(0), len(0) {}
    S(Mint _sa, Mint _sb, Mint _sab, Mint _len) : sa(_sa), sb(_sb), sab(_sab), len(_len) {}
};

struct F {
    Mint x;
    Mint y;
    F() : x(0), y(0) {}
    F(Mint _x, Mint _y) : x(_x), y(_y) {}
};

S op(S a, S b) {
    return S(a.sa + b.sa, a.sb + b.sb, a.sab + b.sab, a.len + b.len);
}

S e() {
    return S();
}

S mapping(F f, S a) {
    S b;
    b.sa = a.sa + (f.x * a.len);
    b.sb = a.sb + (f.y * a.len);
    b.sab = a.sa * f.y + a.sb * f.x + a.sab + f.x * f.y * a.len;
    b.len = a.len;
    return b;
}

F composition(F f, F g) {
    return F(f.x + g.x, f.y + g.y); 
}

F id() {
    return F();
}

void run_case() {
    int N, Q;
    std::cin >> N >> Q;
    
    std::vector<int> A(N);
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::vector<S> a(N);
    for(int i = 0; i < N; i++) {
        a[i] = S(Mint(A[i]), Mint(B[i]), Mint(A[i]) * Mint(B[i]), Mint(1));
    }
    lazy_segtree<S, op, e, F, mapping, composition, id> st(a); 

    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;
        if(T == 1) {
            int L, R, X;
            std::cin >> L >> R >> X;
            L -= 1;
            R -= 1;
            
            st.apply(L, R + 1, F(X, 0));
        } else if(T == 2) {
            int L, R, X;
            std::cin >> L >> R >> X;
            L -= 1;
            R -= 1;

            st.apply(L, R + 1, F(0, X));
        } else {
            int L, R;
            std::cin >> L >> R;
            L -= 1;
            R -= 1;

            std::cout << st.prod(L, R + 1).sab << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
