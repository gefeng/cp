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
    return int(1e9);
}

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    std::vector<std::vector<int>> pos(N + 1);
    std::vector<int64_t> psum(N + 1, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        if(A[i] <= N) {
            pos[A[i]].push_back(i);
        }
        psum[i + 1] = psum[i] + A[i];
    }

    int64_t min_sum = INF;
    int64_t max_sum = -INF;
    if(pos[0].empty()) {
        min_sum = A[0] + A.back() - (psum[N] - A[0] - A.back());
        for(int i = 1; i < N - 1; i++) {
            max_sum = std::max(max_sum, psum[N] - A[i] - A[i]);
        } 
        std::cout << min_sum << ' ' << max_sum << '\n';
        return;
    }

    segtree<S, op, e> st(N + 1);
    for(int x : A) {
        if(x <= N) {
            int pre = st.get(x);
            st.set(x, pre == int(1e9) ? 1 : pre + 1);
        } 
    }

    int mex = 0;
    int l = -1;
    int r = N;
    for(int x = 1; x <= N; x++) {
        int cnt = pos[x - 1].size();
        if(cnt < 3) {
            break;
        }
        int nl = std::max(l, pos[x - 1][0]);
        int nr = std::min(r, pos[x - 1].back());
        
        for(int i = l + 1; i <= nl; i++) {
            if(A[i] <= N) {
                st.set(A[i], st.get(A[i]) - 1);
            }
        }

        for(int i = r - 1; i >= nr; i--) {
            if(A[i] <= N) {
                st.set(A[i], st.get(A[i]) - 1);
            }
        }

        int min_cnt = st.prod(0, x);
        if(min_cnt == 0) {
            break;
        }

        mex += 1;
        l = nl;
        r = nr;
    }

    if(mex == 0 || !pos[mex].empty()) {
        std::cout << -1 << ' ' << -1 << '\n';
        return;
    }

    min_sum = psum[l + 1] + psum[N] - psum[r] - (psum[r] - psum[l + 1]);
    l += 1;
    r -= 1; 

    segtree<S, op, e> st_2(mex + 1);
    for(int i = 0; i < mex; i++) {
        st_2.set(i, 0);
    }

    for(int i = l, j = l; i <= r; i++) {
        if(A[i] < mex) {
            int pre = st_2.get(A[i]);
            st_2.set(A[i], pre == int(1e9) ? 1 : pre + 1);
        } 

        while(j <= i) {
            if(A[j] >= mex) {
                j += 1;
                continue;
            }
            
            int pre = st_2.get(A[j]);
            st_2.set(A[j], pre - 1);
            int min_cnt = st_2.prod(0, mex);
            if(min_cnt) {
                j += 1;
                continue;
            }
            st_2.set(A[j], pre);
            break;
        }

        if(st_2.prod(0, mex)) {
            max_sum = std::max(max_sum, psum[j] + psum[N] - psum[i + 1] - psum[i + 1] + psum[j]);
        }
    }
    
    std::cout << min_sum << ' ' << max_sum << '\n';
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
