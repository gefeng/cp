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

constexpr int INF = int(2e9);

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
    int v = INF;
    int i = -1;
    S() {}
    S(int _v, int _i) : v(_v), i(_i) {}
};

S op(S a, S b) {
    if(a.v < b.v) {
        return a;
    } else {
        return b;
    }
}

S e() {
    return S();
}

void run_case() {
    int N, K, Q;
    std::cin >> N >> K >> Q;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> ans(N - K + 1, 0);
    std::vector<int> freq(N * 2 + 1, 0); 
    std::multiset<int> ms;
    for(int l = 0, r = 0; r < N; r++) {
        int v = A[r] - r + N; 

        if(ms.find(freq[v]) != ms.end()) {
            ms.erase(ms.find(freq[v]));
        }
        freq[v] += 1;
        ms.insert(freq[v]);
        
        if(r - l + 1 > K) {
            v = A[l] - l + N;
            l += 1;
            ms.erase(ms.find(freq[v])); 
            if(--freq[v] > 0) {
                ms.insert(freq[v]);
            }
        }

        if(r - l + 1 == K) {
            ans[l] = K - *ms.rbegin();
        }
    }

    int n = N - K + 1;
    std::vector<int> nxt_smaller(n, n);
    std::vector<int> s;
    for(int i = n - 1; i >= 0; i--) {
        while(!s.empty() && ans[s.back()] >= ans[i]) {
            s.pop_back();
        }
        if(!s.empty()) {
            nxt_smaller[i] = s.back();
        }
        s.push_back(i);
    }

    std::vector<int64_t> suf_sum(n + 1, 0);
    for(int i = n - 1; i >= 0; i--) {
        suf_sum[n - i] = int64_t(nxt_smaller[i] - i) * ans[i] + suf_sum[n - nxt_smaller[i]];
    }

    segtree<S, op, e> st(n);
    for(int i = 0; i < n; i++) {
        st.set(i, S(ans[i], i));
    }

    for(int i = 0; i < Q; i++) {
        int L, R;
        std::cin >> L >> R;
        L -= 1;
        R -= 1;

        R -= K - 1;
        
        int min_p = st.prod(L, R + 1).i;

        int64_t res = suf_sum[n - L] - suf_sum[n - min_p] + int64_t(ans[min_p]) * (R - min_p + 1);
        std::cout << res << '\n';
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
