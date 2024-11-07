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

constexpr int64_t MOD = int64_t(1e9) + 7;
constexpr int MAX = int(2e5);
constexpr int INF = int(2e9);

int64_t gcd(int64_t a, int64_t b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

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

using S = int;

S op(S a, S b) {
    return std::min(a, b);
}

S e() {
    return INF;
}

void run_case() {
    int N, Q;
    std::cin >> N >> Q;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::map<int, int>> prime_factors(N); 
    std::vector<int> freq(MAX + 1, 0);
    for(int i = 0; i < N; i++) {
        int x = A[i];
        for(int f = 2; f * f <= x; f++) {
            if(x % f == 0) {
                int cnt = 0;
                while(x % f == 0) {
                    cnt += 1;
                    x /= f;
                }
                if(prime_factors[i].find(f) == prime_factors[i].end()) {
                    freq[f] += 1;
                }
                prime_factors[i][f] += cnt;
            }
        }
        if(x > 1) {
            if(prime_factors[i].find(x) == prime_factors[i].end()) {
                freq[x] += 1;
            }
            prime_factors[i][x] += 1;
        }
    }

    int64_t g = A[0];
    for(int i = 1; i < N; i++) {
        g = gcd(g, A[i]);
    }

    std::map<int, segtree<S, op, e>> m;
    for(int i = 2; i <= MAX; i++) {
        if(freq[i] == N) {
            m[i] = segtree<S, op, e>(N);
            for(int j = 0; j < N; j++) {
                m[i].set(j, prime_factors[j][i]);
            } 
        }
    }

    for(int i = 0; i < Q; i++) {
        int P, X;
        std::cin >> P >> X;
        P -= 1;

        std::vector<std::pair<int, int>> added;
        for(int f = 2; f * f <= X; f++) {
            if(X % f == 0) {
                int cnt = 0;
                while(X % f == 0) {
                    cnt += 1;
                    X /= f;
                }
                added.emplace_back(f, cnt);
            }
        }
        if(X > 1) {
            added.emplace_back(X, 1);
        }

        for(auto [f, cnt] : added) {
            if(prime_factors[P].find(f) == prime_factors[P].end()) {
                prime_factors[P][f] += cnt;
                if(++freq[f] == N) {
                    m[f] = segtree<S, op, e>(N);
                    for(int j = 0; j < N; j++) {
                        m[f].set(j, prime_factors[j][f]);
                    }
                    int min_f = m[f].all_prod();
                    g *= q_pow(f, min_f);
                    g %= MOD;
                } 
            } else {
                prime_factors[P][f] += cnt;
                if(m.find(f) != m.end()) {
                    int pre = m[f].prod(P, P + 1);
                    int pre_min = m[f].all_prod();

                    m[f].set(P, pre + cnt);

                    int cur_min = m[f].all_prod();
                    g *= q_pow(f, cur_min - pre_min);
                    g %= MOD;
                }
            }
        }

        std::cout << g << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
