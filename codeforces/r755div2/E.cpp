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

using S = int64_t;

S op(S a, S b) {
    return std::min(a, b);
}

S e() {
    return INF;
}

int64_t target;
bool f(S x) {
    return x >= target;
}

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> psum(N + 1, 0);
    segtree<S, op, e> st_0(N + 1);
    segtree<S, op, e> st_1(N + 1);
    std::map<int64_t, std::vector<int>> m_0;
    std::map<int64_t, std::vector<int>> m_1;
    for(int i = 0; i < N; i++) {
        psum[i + 1] = A[i] - psum[i];
        if(i % 2 == 0) {
            st_0.set(i + 1, psum[i + 1]);
            m_0[psum[i + 1]].push_back(i);
        } else {
            st_1.set(i + 1, psum[i + 1]);
            m_1[psum[i + 1]].push_back(i);
        }
    }
    
    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        int64_t t = psum[i];
        if(i % 2 == 0) {
            target = -t;
            int r = st_0.max_right<f>(i + 1);
            target = t;
            r = std::min(r, st_1.max_right<f>(i + 1));
            r -= 1; 

            if(m_0.find(-t) != m_0.end()) {
                ans += std::lower_bound(m_0[-t].begin(), m_0[-t].end(), r) - std::lower_bound(m_0[-t].begin(), m_0[-t].end(), i);
            } 
            if(m_1.find(t) != m_1.end()) {
                ans += std::lower_bound(m_1[t].begin(), m_1[t].end(), r) - std::lower_bound(m_1[t].begin(), m_1[t].end(), i);
            }
        } else {
            target = -t;
            int r = st_1.max_right<f>(i + 1);
            target = t;
            r = std::min(r, st_0.max_right<f>(i + 1));
            r -= 1;

            if(m_1.find(-t) != m_1.end()) {
                ans += std::lower_bound(m_1[-t].begin(), m_1[-t].end(), r) - std::lower_bound(m_1[-t].begin(), m_1[-t].end(), i);
            }
            if(m_0.find(t) != m_0.end()) {
                ans += std::lower_bound(m_0[t].begin(), m_0[t].end(), r) - std::lower_bound(m_0[t].begin(), m_0[t].end(), i);
            }
        }
    }  
    std::cout << ans << '\n';
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
