#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>
#include <functional>

const int64_t INF = (int64_t)1e18;

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
    std::array<int64_t, 3> val;
    std::array<int, 3> col;
    S() {
        val = {-INF, -INF, -INF};
        col = {-1, -1, -1};
    }
};

S op(S a, S b) {
    if(b.col[0] == -1) {
        return a;
    } else if(a.col[0] == -1) {
        return b;
    } else {
        S c;
        for(int i = 0, j = 0, k = 0; k < 3; ) {
            bool ok = true;
            if(i == 3 || b.val[j] > a.val[i]) {
                for(int p = 0; p < k; p++) {
                    if(c.col[p] == b.col[j]) {
                        ok = false;
                    }
                }
                if(ok) {
                    c.val[k] = b.val[j];
                    c.col[k] = b.col[j];
                    k += 1;
                }
                j += 1;
            } else {
                for(int p = 0; p < k; p++) {
                    if(c.col[p] == a.col[i]) {
                        ok = false;
                    }
                }
                if(ok) {
                    c.val[k] = a.val[i];
                    c.col[k] = a.col[i];
                    k += 1;
                }
                i += 1;
            } 
        }
        return c;
    }
}

S e() {
    return S();
}

class Solution {
public:
    long long maximumValueSum(std::vector<std::vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        std::vector<std::array<int64_t, 3>> a(n);
        std::vector<std::array<int, 3>> c(n);
        std::vector<std::pair<int, int>> tmp(m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                tmp[j] = {board[i][j], j};
            }
            std::sort(tmp.begin(), tmp.end());
            
            for(int j = 0; j < 3; j++) {
                a[i][j] = tmp[m - 1 - j].first;
                c[i][j] = tmp[m - 1 - j].second;
            }
        }
        
        segtree<S, op, e> st(n);
        for(int i = 0; i < n; i++) {
            S s;
            s.val = a[i];
            s.col = c[i];
            st.set(i, s);
        }
        
        int64_t ans = -INF;
        for(int i = 1; i < n - 1; i++) {
            for(int j = 0; j < i; j++) {
                for(int p1 = 0; p1 < 3; p1++) {
                    for(int p2 = 0; p2 < 3; p2++) {
                        if(c[i][p1] != c[j][p2]) {
                            int64_t x = a[i][p1];
                            int64_t y = a[j][p2];
                            int64_t z = 0;
                            
                            S res = st.prod(i + 1, n);
                            for(int p3 = 0; p3 < 3; p3++) {
                                if(res.col[p3] != c[i][p1] && res.col[p3] != c[j][p2]) {
                                    z = res.val[p3];
                                    break;
                                }
                            }
                            
                            ans = std::max(ans, x + y + z);
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};
