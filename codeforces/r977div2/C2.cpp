#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <functional>

constexpr int INF = int(1e9);

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
    int l = INF;
    int r = INF;
    bool inc = true;
    S() {}
    S(int _l, int _r, bool _inc) : l(_l), r(_r), inc(_inc) {}
};

S op(S a, S b) { 
    if(a.inc && b.inc && a.r <= b.l) {
        return S(a.l, b.r, true);
    } else {
        return S(INF, INF, false);
    }
}

S e() {
    return S();
}

void run_case() {
    int N, M, Q;
    std::cin >> N >> M >> Q;

    std::vector<int> A(N);
    std::vector<int> B(M);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] -= 1;
    }

    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
        B[i] -= 1;
    }

    std::vector<int> mapping(N, 0);
    for(int i = 0; i < N; i++) {
        mapping[A[i]] = i;
    }

    segtree<S, op, e> st(N);
    std::vector<std::set<int>> pos(N);
    for(int i = 0; i < M; i++) {
        int v = mapping[B[i]];
        pos[v].insert(i);
    }

    for(int i = 0; i < N; i++) {
        st.set(i, pos[i].empty() ? S() : S(*pos[i].begin(), *pos[i].begin(), true));
    }

    std::cout << (st.all_prod().inc ? "YA" : "TIDAK") << '\n';
 
    for(int i = 0; i < Q; i++) {
        int P, V;
        std::cin >> P >> V;
        P -= 1;
        V -= 1;

        int pre = mapping[B[P]];
        int now = mapping[V];
        if(pre != now) {
            B[P] = V;

            pos[pre].erase(P);
            st.set(pre, pos[pre].empty() ? S() : S(*pos[pre].begin(), *pos[pre].begin(), true));

            pos[now].insert(P);
            st.set(now, S(*pos[now].begin(), *pos[now].begin(), true));
        }

        std::cout << (st.all_prod().inc ? "YA" : "TIDAK") << '\n';
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
